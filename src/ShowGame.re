[@react.component]
let make = (~id: int) => {
  let (game: Wasm_App.res_t(Common.Types.Wasm_App.t), setGames) =
    React.useState(() => Wasm_App.NotStarted);
  React.useEffect0(() => {
    setGames(_ => Loading);
    Wasm_App.fetch_app_by_id(~id)
    |> Js.Promise.then_(result => {
         switch (result) {
         | Error(msg) => setGames(_ => Failure(msg))
         | Ok(games) => setGames(_ => Loaded(games))
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
         src={"/static/wasm/" ++ game.homepage}
         title={game.name}
         width={game.width}
         height={game.height}
       />
     }}
  </div>;
};
