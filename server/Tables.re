module type DB = Caqti_lwt.CONNECTION;

module Project = {
  open Caqti_request.Infix;
  open Caqti_type.Std;

  let project = {
    let encode =
        (
          {id, _type, name, description, demo_id, link, link_text}: Common.Types.Project.t,
        ) =>
      Ok((
        string_of_int(id),
        (_type, (name, (description, (demo_id, (link, link_text))))),
      ));
    let decode =
        (
          (
            id,
            (_type, (name, (description, (demo_id, (link, link_text))))),
          ),
        ) =>
      Ok(
        {
          id: int_of_string(id),
          _type,
          name,
          description,
          demo_id,
          link,
          link_text,
        }: Common.Types.Project.t,
      );
    // This is too much
    // Caqti has Field.t so I should figure out how to use that
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
                tup2(option(int), tup2(option(string), option(string))),
              ),
            ),
          ),
        )
      );
    custom(~encode, ~decode, rep);
  };

  let _add = {
    let query =
      tup2(
        string,
        tup2(
          string,
          tup2(
            string,
            tup2(
              string,
              tup2(
                string,
                tup2(option(int), tup2(option(string), option(string))),
              ),
            ),
          ),
        ),
      )
      ->. unit @@
      "INSERT INTO projects "
      ++ "(type, name, description, demo_id, link, link_text)"
      ++ " VALUES (?, ?, ?, ?, ?, ?)";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let _change_name = {
    let query =
      tup2(string, string)
      ->. unit @@
      "UPDATE projects SET name = ? WHERE id = ?";
    (text, module Db: DB) => {
      let%lwt unit_or_error = Db.exec(query, text);
      Caqti_lwt.or_fail(unit_or_error);
    };
  };

  let item = {
    let query = int ->? project @@ "SELECT * FROM projects WHERE id == ?";
    (id: int, module Db: DB) => {
      let%lwt project_or_error = Db.find_opt(query, id);
      Caqti_lwt.or_fail(project_or_error);
    };
  };

  let list = {
    let query = unit ->* project @@ "SELECT * FROM projects";
    (module Db: DB) => {
      let%lwt project_or_error = Db.collect_list(query, ());
      Caqti_lwt.or_fail(project_or_error);
    };
  };
};

module Demo_App = {
  open Caqti_request.Infix;
  open Caqti_type.Std;

  let demo_app = {
    let encode =
        (
          {id, _type, name, homepage, height, width, controls}: Common.Types.Demo_App.t,
        ) =>
      Ok((
        string_of_int(id),
        (_type, (name, (homepage, (height, (width, controls))))),
      ));
    let decode =
        ((id, (_type, (name, (homepage, (height, (width, controls))))))) =>
      Ok(
        {
          id: int_of_string(id),
          _type,
          name,
          homepage,
          height,
          width,
          controls,
        }: Common.Types.Demo_App.t,
      );
    let rep =
      Caqti_type.(
        tup2(
          string,
          tup2(
            string,
            tup2(string, tup2(string, tup2(string, tup2(string, string)))),
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
      ++ "(type, name, homepage, height, width, controls)"
      ++ " VALUES (?, ?, ?, ?, ?, ?)";
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
