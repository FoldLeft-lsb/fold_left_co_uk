// Use something serious like Yojson for this
// ultimately it's a more complicated way to do exactly
// what I've done here, I think this is Ok for a toy project

module Demo_App = {
  let encode_item = (t: Common.Types.Demo_App.t) => {
    "{"
    ++ "\"id\":"
    ++ string_of_int(t.id)
    ++ ","
    ++ "\"type\":\""
    ++ t._type
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

module Project = {
  let encode_item = (t: Common.Types.Project.t) => {
    "{"
    ++ "\"id\":"
    ++ string_of_int(t.id)
    ++ ","
    ++ "\"type\":\""
    ++ t._type
    ++ "\","
    ++ "\"name\":\""
    ++ t.name
    ++ "\","
    ++ "\"description\":\""
    ++ t.description
    ++ "\","
    ++ "\"demo_id\":"
    ++ (
      switch (t.demo_id) {
      | None => "null"
      | Some(demo_id) => string_of_int(demo_id)
      }
    )
    ++ ","
    ++ "\"link\":"
    ++ (
      switch (t.link) {
      | None => "null"
      | Some(link) => "\"" ++ link ++ "\""
      }
    )
    ++ ","
    ++ "\"link_text\":"
    ++ (
      switch (t.link_text) {
      | None => "null"
      | Some(link_text) => "\"" ++ link_text ++ "\""
      }
    )
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
