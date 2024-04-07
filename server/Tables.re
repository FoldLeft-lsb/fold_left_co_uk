module type DB = Caqti_lwt.CONNECTION;

module Demo_App = {
  open Caqti_request.Infix;
  open Caqti_type.Std;

  let demo_app = {
    let encode =
        (
          {id, type_, name, homepage, height, width, description, controls}: Common.Types.Demo_App.t,
        ) =>
      Ok((
        string_of_int(id),
        (
          type_,
          (name, (homepage, (height, (width, (description, controls))))),
        ),
      ));
    let decode =
        (
          (
            id,
            (
              type_,
              (
                name,
                (homepage, (height, (width, (description, controls)))),
              ),
            ),
          ),
        ) =>
      Ok(
        {
          id: int_of_string(id),
          type_,
          name,
          homepage,
          height,
          width,
          description,
          controls,
        }: Common.Types.Demo_App.t,
      );
    let rep =
      Caqti_type.(
        tup2(
          string,
          tup2(
            string,
            tup2(
              string,
              tup2(
                string,
                tup2(string, tup2(string, tup2(string, string))),
              ),
            ),
          ),
        )
      );
    custom(~encode, ~decode, rep);
  };

  let _add = {
    let query =
      tup2(string, tup2(string, tup2(string, tup2(string, string))))
      ->. unit @@
      "INSERT INTO demo_apps "
      ++ "(type, name, homepage, height, width, description, controls)"
      ++ " VALUES (?, ?, ?, ?, ?, ?, ?)";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let _change_name = {
    let query =
      tup2(string, string)
      ->. unit @@
      "UPDATE demo_apps SET name = ? WHERE id = ?";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let item = {
    let query = int ->? demo_app @@ "SELECT * FROM demo_apps WHERE id == ?";
    (id: int, module Db: DB) => {
      let%lwt demo_app_or_error = Db.find_opt(query, id);
      Caqti_lwt.or_fail(demo_app_or_error);
    };
  };

  let list = {
    let query = unit ->* demo_app @@ "SELECT * FROM demo_apps";
    (module Db: DB) => {
      let%lwt demo_app_or_error = Db.collect_list(query, ());
      Caqti_lwt.or_fail(demo_app_or_error);
    };
  };
};
