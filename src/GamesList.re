[@react.component]
let make = () => {
  let (games: Demo_App.res_t(list(Common.Types.Demo_App.t)), setGames) =
    React.useState(() => Demo_App.NotStarted);
  React.useEffect0(() => {
    setGames(_ => Loading);
    Demo_App.fetch_apps()
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
  <div className="games-list">
    {switch (games) {
     | NotStarted
     | Loading => <p> {React.string("Loading")} </p>
     | Failure(msg) =>
       <div>
         <p> {React.string("Error: ")} </p>
         <p> {React.string(msg)} </p>
       </div>
     | Loaded(games) =>
       let rows =
         games
         ->Belt.List.map(game => {
             let url = "/apps?id=" ++ string_of_int(game.id);
             <tr>
               <td colSpan=2> {React.string(game.name)} </td>
               <td>
                 <a
                   href=url
                   onClick={e => {
                     React.Event.Mouse.preventDefault(e);
                     ReasonReactRouter.push(url);
                   }}>
                   {React.string(url)}
                 </a>
               </td>
             </tr>;
           })
         ->Belt.List.toArray
         |> React.array;
       <table>
         <thead>
           <tr>
             <th colSpan=2> {React.string("Title")} </th>
             <th> {React.string("Link")} </th>
           </tr>
         </thead>
         <tbody> rows </tbody>
       </table>;
     }}
  </div>;
};
