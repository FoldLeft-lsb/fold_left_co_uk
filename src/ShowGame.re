[@react.component]
let make = (~id: int) => {
  let (game: Demo_App.res_t(Common.Types.Demo_App.t), setGame) =
    React.useState(() => Demo_App.NotStarted);
  React.useEffect0(() => {
    setGame(_ => Loading);
    Demo_App.fetch_app_by_id(~id)
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
  <div className="game">
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
  </div>;
};
