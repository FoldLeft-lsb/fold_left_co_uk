open RadixUI.Themes;
open Util;

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
    | ([], "") => Landing
    | (["apps"], search) =>
      switch (get_gameid_search(search)) {
      | Some(id) => Demo(id)
      | None => NotFound
      }
    | _ => NotFound
    };
  let (theme, setTheme) = React.useState(() => get_saved_theme());
  switch (currentView) {
  | NotFound =>
    <Theme
      appearance={get_theme_name(theme)}
      accentColor="mint"
      grayColor="gray"
      panelBackground="solid"
      radius="medium">
      <NotFound />
      <DarkThemeSwitch theme setTheme />
    </Theme>
  | Demo(id) => <ShowGame id theme setTheme />
  | Landing =>
    <>
      <Theme
        appearance={get_theme_name(theme)}
        accentColor="mint"
        grayColor="gray"
        panelBackground="solid"
        radius="medium">
        <LandingPage />
      </Theme>
      <Theme
        appearance={get_theme_name(theme)}
        accentColor="mint"
        grayColor="gray"
        panelBackground="solid"
        radius="medium">
        <Box
          _as="div"
          className="GameGoblin-ui"
          style={backgroundColor: "var(--gray-a2)"}>
          <ProjectsList />
        </Box>
      </Theme>
      <Theme
        appearance={get_theme_name(theme)}
        accentColor="mint"
        grayColor="gray"
        panelBackground="solid"
        radius="medium">
        <Technologies />
        <Flex
          _as="div"
          display="flex"
          justify="center"
          direction="column"
          className="">
          <Container size="2" p="4" pb="9" pt="8">
            <Text _as="p" size="7" weight="bold">
              {React.string("Contact")}
            </Text>
            <br />
            <a href="mailto:lboyle@protonmail.com">
              {React.string("lboyle@protonmail.com")}
            </a>
          </Container>
        </Flex>
        <DarkThemeSwitch theme setTheme />
      </Theme>
    </>
  };
};
