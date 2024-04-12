open RadixUI.Themes;
open Util;

[@react.component]
let make = (~id: int, ~theme: theme_t, ~setTheme) => {
  let (game: server_res_t(Common.Types.Demo_App.t), setGame) =
    React.useState(() => NotStarted);
  React.useEffect0(() => {
    setGame(_ => Loading);
    Api.DemoAppRest.fetch_app_by_id(~id)
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
    <BackButton />
    <Flex _as="div" display="flex" justify="center" direction="column" pt="8">
      {switch (game) {
       | NotStarted
       | Loading => React.null
       | Failure(msg) => <ErrorMessage msg />
       | Loaded(game) =>
         // This is bad on mobile
         // the games also aren't playable without a keyboard
         <>
           <IFrame
             src={"/static/" ++ game.homepage}
             title={game.name}
             width={game.width}
             height={game.height}
           />
           <br />
           <Container size="2" p="4" pb="9">
             <Text _as="p" size="4" weight="bold">
               {React.string(game.controls)}
             </Text>
           </Container>
         </>
       }}
    </Flex>
    <DarkThemeSwitch theme setTheme />
  </Theme>;
};
