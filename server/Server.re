let default_route = Dream.from_filesystem("public", "index.html");

let api_routes = [
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
  Dream.get("/projects", request => {
    let%lwt db_projects = Dream.sql(request, Tables.Project.list);
    db_projects |> Encoders.Project.encode_list |> Dream.json;
  }),
  Dream.get("/projects/:id", request => {
    switch (int_of_string(Dream.param(request, "id"))) {
    | exception _exn => request |> Dream.not_found
    | id =>
      let%lwt db_project = Dream.sql(request, Tables.Project.item(id));
      switch (db_project) {
      | Some(db_project) =>
        db_project |> Encoders.Project.encode_item |> Dream.json
      | None => request |> Dream.not_found
      };
    }
  }),
];

let routes = [
  Dream.scope("/api", [], api_routes),
  Dream.get("/static/**", Dream.static("public")),
  Dream.get("/projects", default_route),
  Dream.get("/apps", default_route),
  Dream.get("/", default_route),
];

let () =
  Dream.router(routes)
  |> Dream.sql_sessions
  |> Dream.sql_pool("sqlite3:db.sqlite")
  |> Dream.logger
  |> Dream.run(~port=4444);
