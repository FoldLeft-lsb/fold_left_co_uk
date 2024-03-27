type greeting_t = {greeting: string};

let greeting: greeting_t = {greeting: "Greetings from the API"};

let elt_to_string = elt => Fmt.str("%a", Tyxml.Html.pp_elt(), elt);

let someMarkup = Tyxml.Html.(a(~a=[a_href("/api")], [txt("api")]));
let _markupText = elt_to_string(someMarkup);

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
  Dream.get("/", Dream.from_filesystem("public", "index.html")),
  Dream.get("/**", Dream.static("public")),
];

let () = Dream.router(routes) |> Dream.logger |> Dream.run(~port=42069);
