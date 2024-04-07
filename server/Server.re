let default_route = Dream.from_filesystem("public", "index.html");

let api_routes = [
  Dream.get("/apps", request => {
    let%lwt db_apps = Dream.sql(request, Tables.Demo_App.list);
    db_apps |> Encoders.Demo_App.encode_list |> Dream.json;
  }),
  Dream.get("/apps/:id", request => {
    switch (int_of_string(Dream.param(request, "id"))) {
    | exception _exn => request |> Dream.not_found
    | id =>
      let%lwt db_app = Dream.sql(request, Tables.Demo_App.item(id));
      switch (db_app) {
      | Some(db_app) => db_app |> Encoders.Demo_App.encode_item |> Dream.json
      | None => request |> Dream.not_found
      };
    }
  }),
];

let routes = [
  Dream.scope("/api", [], api_routes),
  Dream.get("/static/**", Dream.static("public")),
  Dream.get("/apps", default_route),
  Dream.get("/", default_route),
];

let () =
  Dream.router(routes)
  |> Dream.sql_sessions
  |> Dream.sql_pool("sqlite3:db.sqlite")
  |> Dream.logger
  |> Dream.run(~port=42069);
