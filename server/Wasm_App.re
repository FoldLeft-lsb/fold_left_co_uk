module type DB = Caqti_lwt.CONNECTION;

// Replace this with Yojson or something
module Json = {
  let encode_item = (t: Common.Types.Wasm_App.t) => {
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
      |> List.map(encode_item)
      |> List.fold_left((acc, v) => acc ++ (acc == "" ? "" : ", ") ++ v, "")
    )
    ++ "]";
  };
};

module Table = {
  open Caqti_request.Infix;
  open Caqti_type.Std;

  let wasm_app = {
    let encode =
        ({id, type_, name, homepage, height, width}: Common.Types.Wasm_App.t) =>
      Ok((
        string_of_int(id),
        (type_, (name, (homepage, (height, width)))),
      ));
    let decode = ((id, (type_, (name, (homepage, (height, width)))))) =>
      Ok(
        {id: int_of_string(id), type_, name, homepage, height, width}: Common.Types.Wasm_App.t,
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
      "INSERT INTO wasm_apps (type, name, homepage, height, width) VALUES (?, ?, ?, ?, ?)";
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

  let item = {
    let query = int ->? wasm_app @@ "SELECT * FROM wasm_apps WHERE id == ?";
    (id: int, module Db: DB) => {
      let%lwt comments_or_error = Db.find_opt(query, id);
      Caqti_lwt.or_fail(comments_or_error);
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
