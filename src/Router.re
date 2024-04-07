// Lol
let get_gameid_search = (search: string) =>
  if (Js.Re.test(~str=search, Js.Re.fromString("id=([0-9])+"))) {
    switch (
      int_of_string(
        Js.String.split(
          ~sep="id=",
          Js.String.split(~sep="&", ~limit=1, search)[0],
        )[1],
      )
    ) {
    | exception _exn => None
    | id => Some(id)
    };
  } else {
    None;
  };

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let currentView =
    switch (url.path, url.search) {
    | ([], "") => Nav.Home
    | (["apps"], "") => GamesList
    | (["apps"], search) =>
      switch (get_gameid_search(search)) {
      | Some(id) => Game(id)
      | None => NotFound
      }
    | _ => NotFound
    };
  <div className="GameGoblin-ui">
    <Nav currentView />
    {switch (currentView) {
     | Nav.Home =>
       <div className="home"> <p> {React.string("Home View")} </p> </div>
     | GamesList => <GamesList />
     | Game(id) => <ShowGame id />
     | NotFound => <NotFound />
     }}
  </div>;
};
