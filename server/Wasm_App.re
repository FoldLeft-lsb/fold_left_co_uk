module type DB = Caqti_lwt.CONNECTION;

// Replace this with Yojson or something
// Maybe place in Common and use it front and back end
module Json = {
  let encode = (t: Common.Types.Wasm_App.t) => {
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
  let encode_list = (l: list(Common.Types.Wasm_App.t)) => {
    "["
    ++ (
      l
      |> List.map(encode)
      |> List.fold_left((acc, v) => acc ++ (acc == "" ? "" : ", ") ++ v, "")
    )
    ++ "]";
  };
  let _decode = (_t: Common.Types.Wasm_App.t) => {
    "";
  };
};

module Table = {
  open Caqti_request.Infix;
  open Caqti_type.Std;

  let wasm_app = {
    let encode =
        ({id, name, type_, homepage, height, width}: Common.Types.Wasm_App.t) =>
      Ok((
        string_of_int(id),
        (name, (type_, (homepage, (height, width)))),
      ));
    let decode = ((id, (name, (type_, (homepage, (height, width)))))) =>
      Ok(
        {id: int_of_string(id), name, type_, homepage, height, width}: Common.Types.Wasm_App.t,
      );
    let rep =
      Caqti_type.(
        tup2(
          string,
          tup2(string, tup2(string, tup2(string, tup2(string, string)))),
        )
      );
    custom(~encode, ~decode, rep);
  };

  let _add = {
    let query =
      tup2(string, tup2(string, tup2(string, tup2(string, string))))
      ->. unit @@
      "INSERT INTO wasm_apps (name, type, homepage, height, width) VALUES (?, ?, ?, ?, ?)";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let _change_name = {
    let query =
      tup2(string, string)
      ->. unit @@
      "UPDATE wasm_apps SET name = ? WHERE id = ?";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let list = {
    let query = unit ->* wasm_app @@ "SELECT * FROM wasm_apps WHERE id < 10";
    (module Db: DB) => {
      let%lwt comments_or_error = Db.collect_list(query, ());
      Caqti_lwt.or_fail(comments_or_error);
    };
  };
};
