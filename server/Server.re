// module type DB = Caqti_lwt.CONNECTION;
// module T = Caqti_type;

type greeting_t = {greeting: string};

let greeting: greeting_t = {greeting: "Greetings from the API"};

let elt_to_string = elt => Fmt.str("%a", Tyxml.Html.pp_elt(), elt);

let someMarkup = Tyxml.Html.(a(~a=[a_href("/api")], [txt("api")]));
let _markupText = elt_to_string(someMarkup);

let default_route = Dream.from_filesystem("public", "index.html");

let routes = [
  Dream.scope(
    "/api",
    [],
    [
      Dream.get("", _request =>
        "{\"greeting\":\"" ++ greeting.greeting ++ "\"}" |> Dream.json
      ),
    ],
  ),
  Dream.get("/", default_route),
  Dream.get("/games", default_route),
  Dream.get("/game", default_route),
  Dream.get("/**", Dream.static("public")),
];

let () =
  Dream.router(routes)
  // |> Dream.sql_sessions
  // |> Dream.sql_pool("sqlite3:db.sqlite")
  |> Dream.logger
  |> Dream.run(~port=42069);
