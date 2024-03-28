let _thing: Common.Types.greeting_t = {greeting: "Hello from Client"};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let currentView =
    switch (url.path) {
    | [] => Nav.Home
    | ["games"] => GamesList
    | ["game"] => Game
    | _ => NotFound
    };
  <div className="GameGoblin-ui">
    <Nav currentView />
    {switch (currentView) {
     | Nav.Home =>
       <div className="home"> <p> {React.string("Home View")} </p> </div>
     | GamesList =>
       <div className="games-list">
         <p> {React.string("GamesList View")} </p>
       </div>
     | Game =>
       <div className="game">
         <IFrame
           src="/wasm/cgol.html"
           title="Game of Life"
           width="752px"
           height="900px"
         />
       </div>
     | NotFound => <NotFound />
     }}
  </div>;
};
