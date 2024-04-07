open RadixUI;

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

type theme_t =
  | Light
  | Dark
  | Inherit;

let get_theme_name = th =>
  switch (th) {
  | Light => "light"
  | Dark => "dark"
  | Inherit => "inherit"
  };

let get_theme = n =>
  switch (n) {
  | "light" => Light
  | "dark" => Dark
  | "inherit" => Inherit
  | _ => Inherit
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
  let (theme, _setTheme) = React.useState(() => Dark);

  <Theme
    appearance={get_theme_name(theme)}
    accentColor="mint"
    grayColor="gray"
    panelBackground="solid"
    radius="medium">
    <div className="GameGoblin-ui">
      // <Nav currentView />

        {switch (currentView) {
         | Nav.Home =>
           <Flex _as="div" display="flex" justify="center" className="home">
             <CopyWriter source="Hello World!">
               ...{copy =>
                 <Text _as="p" size="9" weight="bold">
                   {React.string(copy)}
                 </Text>
               }
             </CopyWriter>
           </Flex>
         | GamesList => <GamesList />
         | Game(id) => <ShowGame id />
         | NotFound => <NotFound />
         }}
      </div>
  </Theme>;
};
