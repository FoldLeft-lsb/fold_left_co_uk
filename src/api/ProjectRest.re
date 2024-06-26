module Decode = {
  let item = (json: Js.Json.t): Common.Types.Project.t => {
    Json.Decode.{
      id: json |> field("id", int),
      _type: json |> field("type", string),
      name: json |> field("name", string),
      description: json |> field("description", string),
      demo_id: json |> optional(field("demo_id", int)),
      link: json |> optional(field("link", string)),
      link_text: json |> optional(field("link_text", string)),
    };
  };
  let list = (json: Js.Json.t): list(Common.Types.Project.t) => {
    json |> Json.Decode.array(item) |> Array.to_list;
  };
};

let fetch_projects = () => {
  Fetch.fetch("/api/projects")
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(res => {
       switch (Decode.list(res)) {
       | exception exn =>
         Js.log2("Failed to decode projects json: ", exn);
         Js.Promise.resolve(Error("Failed to decode projects json"));
       | games => Js.Promise.resolve(Ok(games))
       }
     })
  |> Js.Promise.catch(exn => {
       Js.log2("Failed to fetch projects: ", exn);
       Js.Promise.resolve(Error("Failed to fetch projects"));
     });
};

let fetch_project_by_id = (~id: int) => {
  Fetch.fetch("/api/projects/" ++ string_of_int(id))
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(res => {
       switch (Decode.item(res)) {
       | exception exn =>
         Js.log2("Failed to decode projects json: ", exn);
         Js.Promise.resolve(Error("Failed to decode projects json"));
       | games => Js.Promise.resolve(Ok(games))
       }
     })
  |> Js.Promise.catch(exn => {
       Js.log2(
         "Failed to fetch project with ID " ++ string_of_int(id) ++ ": ",
         exn,
       );
       Js.Promise.resolve(
         Error("Failed to fetch project with ID " ++ string_of_int(id)),
       );
     });
};
