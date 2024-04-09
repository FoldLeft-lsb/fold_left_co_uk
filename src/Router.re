open RadixUI.Themes;
open Types;

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
  let (theme, setTheme) = React.useState(() => Dark);
  switch (currentView) {
  | NotFound => <NotFound />
  | Demo(id) => <ShowGame id theme />
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
          style={
            backgroundColor: "var(--gray-a2)",
            borderRadius: "var(--radius-3)",
          }>
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
            <Text _as="p" size="4">
              {React.string("lboyle@protonmail.com")}
            </Text>
          </Container>
        </Flex>
        <Switch
          className="theme-button"
          color="gray"
          checked={theme == Dark}
          highContrast=true
          style={
            backgroundColor: "var(--gray-a2)",
            borderRadius: "var(--radius)",
          }
          onCheckedChange={checked =>
            if (checked) {
              setTheme(_ => Dark);
            } else {
              setTheme(_ => Light);
            }
          }
        />
      </Theme>
    </>
  };
};
