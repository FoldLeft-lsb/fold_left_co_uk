open RadixUI.Themes;
open Types;

[@react.component]
let make = (~id: int, ~theme: theme_t, ~setTheme) => {
  let (game: DemoAppRest.res_t(Common.Types.Demo_App.t), setGame) =
    React.useState(() => DemoAppRest.NotStarted);
  React.useEffect0(() => {
    setGame(_ => Loading);
    DemoAppRest.fetch_app_by_id(~id)
    |> Js.Promise.then_(result => {
         switch (result) {
         | Error(msg) => setGame(_ => Failure(msg))
         | Ok(games) => setGame(_ => Loaded(games))
         };
         Js.Promise.resolve();
       })
    |> ignore;
    None;
  });

  <Theme
    appearance={get_theme_name(theme)}
    accentColor="mint"
    grayColor="gray"
    panelBackground="solid"
    radius="medium">
    <Flex _as="div" display="flex" justify="center" direction="column" pt="8">
      {switch (game) {
       | NotStarted
       | Loading => <p> {React.string("Loading")} </p>
       | Failure(msg) =>
         <div>
           <p> {React.string("Error: ")} </p>
           <p> {React.string(msg)} </p>
         </div>
       | Loaded(game) =>
         <>
           <IFrame
             src={"/static/" ++ game.homepage}
             title={game.name}
             width={game.width}
             height={game.height}
           />
           <br />
           <Container size="2" p="4" pb="9">
             <Text size="4" weight="bold">
               {React.string(game.controls)}
             </Text>
           </Container>
         </>
       }}
    </Flex>
    <Switch
      className="theme-button"
      color="gray"
      checked={theme == Dark}
      highContrast=true
      style={backgroundColor: "var(--gray-a2)", borderRadius: "var(--radius)"}
      onCheckedChange={checked =>
        if (checked) {
          setTheme(_ => Dark);
        } else {
          setTheme(_ => Light);
        }
      }
    />
  </Theme>;
};
