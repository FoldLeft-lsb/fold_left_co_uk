let _thing: Common.Types.greeting_t = {greeting: "Hello from Server"};

let default_route = Dream.from_filesystem("public", "index.html");

let routes = [
  Dream.scope(
    "/api",
    [],
    [
      Dream.get("/games", request => {
        let%lwt db_apps = Dream.sql(request, Wasm_App.Table.list);
        db_apps |> Wasm_App.Json.encode_list |> Dream.json;
      }),
    ],
  ),
  Dream.get("/", default_route),
  Dream.get("/games", default_route),
  Dream.get("/game", default_route),
  Dream.get("/**", Dream.static("public")),
];

let () =
  Dream.router(routes)
  |> Dream.sql_sessions
  |> Dream.sql_pool("sqlite3:db.sqlite")
  |> Dream.logger
  |> Dream.run(~port=42069);
