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

module Project = {
  let encode_item = (t: Common.Types.Project.t) => {
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
    ++ t.description
    ++ "\","
    ++ "\"height\":\""
    ++ t.controls
    ++ "\""
    ++ "}";
  };
  let encode_list = (l: list(Common.Types.Project.t)) => {
    "["
    ++ (
      l
      |> List.map(encode_item)
      |> List.fold_left((acc, v) => acc ++ (acc == "" ? "" : ", ") ++ v, "")
    )
    ++ "]";
  };
};
