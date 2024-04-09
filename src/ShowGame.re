open RadixUI.Themes;
open Types;

[@react.component]
let make = (~id: int, ~theme: theme_t) => {
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
  <div className="GameGoblin-ui">
    <Theme
      appearance={get_theme_name(theme)}
      accentColor="mint"
      grayColor="gray"
      panelBackground="solid"
      radius="medium">
      {switch (game) {
       | NotStarted
       | Loading => <p> {React.string("Loading")} </p>
       | Failure(msg) =>
         <div>
           <p> {React.string("Error: ")} </p>
           <p> {React.string(msg)} </p>
         </div>
       | Loaded(game) =>
         <IFrame
           src={"/static/" ++ game.homepage}
           title={game.name}
           width={game.width}
           height={game.height}
         />
       }}
    </Theme>
  </div>;
};
