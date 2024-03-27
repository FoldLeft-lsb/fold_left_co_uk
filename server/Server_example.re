module type DB = Caqti_lwt.CONNECTION;
module T = Caqti_type;

let list_comments = {
  let query =
    Caqti_request.Infix.(
      (T.unit ->* T.(tup2(int, string)))("SELECT id, text FROM comment")
    );
  (module Db: DB) => {
    let%lwt comments_or_error = Db.collect_list(query, ());
    Caqti_lwt.or_fail(comments_or_error);
  };
};

let add_comment = {
  let query =
    Caqti_request.Infix.(
      (T.string ->. T.unit)("INSERT INTO comment (text) VALUES ($1)")
    );
  (text, module Db: DB) => {
    let%lwt unit_or_error = Db.exec(query, text);
    Caqti_lwt.or_fail(unit_or_error);
  };
};

let render = comments =>
  comments
  |> List.fold_left(
       (acc, (id, comment)) =>
         acc
         ++ (acc == "" ? "" : ", ")
         ++ string_of_int(id)
         ++ ": "
         ++ comment,
       "",
     );

let () =
  Dream.run @@
  Dream.logger @@
  Dream.sql_pool("sqlite3:db.sqlite") @@
  Dream.sql_sessions @@
  Dream.router([
    Dream.get("/", request => {
      let%lwt comments = Dream.sql(request, list_comments);
      Dream.html(render(comments));
    }),
    Dream.post("/", request =>
      switch%lwt (Dream.form(request)) {
      | `Ok([("text", text)]) =>
        let%lwt () = Dream.sql(request, add_comment(text));
        Dream.redirect(request, "/");
      | _ => Dream.empty(`Bad_Request)
      }
    ),
  ]);
