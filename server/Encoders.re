// Replace this with Yojson or something
// I don't get type errors from it
module Demo_App = {
  let encode_item = (t: Common.Types.Demo_App.t) => {
    "{"
    ++ "\"id\": "
    ++ string_of_int(t.id)
    ++ ","
    ++ "\"type\":\""
    ++ t.type_
    ++ "\","
    ++ "\"name\":\""
    ++ t.name
    ++ "\","
    ++ "\"homepage\":\""
    ++ t.homepage
    ++ "\","
    ++ "\"height\":\""
    ++ t.height
    ++ "\","
    ++ "\"width\":\""
    ++ t.width
    ++ "\","
    ++ "\"description\":\""
    ++ t.description
    ++ "\","
    ++ "\"controls\":\""
    ++ t.controls
    ++ "\""
    ++ "}";
  };
  let encode_list = (l: list(Common.Types.Demo_App.t)) => {
    "["
    ++ (
      l
      |> List.map(encode_item)
      |> List.fold_left((acc, v) => acc ++ (acc == "" ? "" : ", ") ++ v, "")
    )
    ++ "]";
  };
};
