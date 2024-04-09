type res_t('a) =
  | NotStarted
  | Loading
  | Loaded('a)
  | Failure(string);

module Decode = {
  let item = (json: Js.Json.t): Common.Types.Demo_App.t => {
    Json.Decode.{
      id: json |> field("id", int),
      _type: json |> field("type", string),
      name: json |> field("name", string),
      homepage: json |> field("homepage", string),
      height: json |> field("height", string),
      width: json |> field("width", string),
    };
  };
  let list = (json: Js.Json.t): list(Common.Types.Demo_App.t) => {
    json |> Json.Decode.array(item) |> Array.to_list;
  };
};

let fetch_apps = () => {
  // Fetch.fetch("/api/apps")
  Fetch.fetch("http://localhost:42069/api/apps")
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(res => {
       switch (Decode.list(res)) {
       | exception exn =>
         Js.log2("Failed to decode apps json: ", exn);
         Js.Promise.resolve(Error("Failed to decode apps json"));
       | games => Js.Promise.resolve(Ok(games))
       }
     })
  |> Js.Promise.catch(exn => {
       Js.log2("Failed to fetch apps: ", exn);
       Js.Promise.resolve(Error("Failed to fetch apps"));
     });
};

let fetch_app_by_id = (~id: int) => {
  // Fetch.fetch("/api/apps/" ++ string_of_int(id))
  Fetch.fetch("http://localhost:42069/api/apps/" ++ string_of_int(id))
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(res => {
       switch (Decode.item(res)) {
       | exception exn =>
         Js.log2("Failed to decode apps json: ", exn);
         Js.Promise.resolve(Error("Failed to decode apps json"));
       | games => Js.Promise.resolve(Ok(games))
       }
     })
  |> Js.Promise.catch(exn => {
       Js.log2(
         "Failed to fetch app with ID " ++ string_of_int(id) ++ ": ",
         exn,
       );
       Js.Promise.resolve(
         Error("Failed to fetch app with ID " ++ string_of_int(id)),
       );
     });
};
