let default_route = Dream.from_filesystem("public", "index.html");

let api_routes = [
  Dream.get("/games", request => {
    let%lwt db_apps = Dream.sql(request, Wasm_App.Table.list);
    db_apps |> Wasm_App.Json.encode_list |> Dream.json;
  }),
  Dream.get("/games/:id", request => {
    switch (int_of_string(Dream.param(request, "id"))) {
    | exception _exn => request |> Dream.not_found
    | id =>
      let%lwt db_app = Dream.sql(request, Wasm_App.Table.item(id));
      switch (db_app) {
      | Some(db_app) => db_app |> Wasm_App.Json.encode |> Dream.json
      | None => request |> Dream.not_found
      };
    }
  }),
];

let routes = [
  Dream.scope("/api", [], api_routes),
  Dream.get("/static/**", Dream.static("public")),
  Dream.get("/games", default_route),
  Dream.get("/", default_route),
];

let () =
  Dream.router(routes)
  |> Dream.sql_sessions
  |> Dream.sql_pool("sqlite3:db.sqlite")
  |> Dream.logger
  |> Dream.run(~port=42069);
