type view_t =
  | Home
  | GamesList
  | Game(int)
  | NotFound;

let getViewLabel = view =>
  switch (view) {
  | Home => "Home"
  | GamesList => "GamesList"
  | Game(_id) => "Game"
  | NotFound => ""
  };

let getViewHref = view =>
  switch (view) {
  | Home => "/"
  | GamesList => "/games"
  | Game(id) => "/games?id=" ++ string_of_int(id)
  | NotFound => ""
  };

[@react.component]
let make = (~currentView) => {
  <div className="nav">
    <ul>
      {[Home, GamesList]
       ->Belt.List.map(view =>
           <li
             className={"nav-item " ++ (view == currentView ? "selected" : "")}>
             <a
               href={getViewHref(view)}
               onClick={e => {
                 React.Event.Mouse.preventDefault(e);
                 ReasonReactRouter.push(getViewHref(view));
               }}>
               {React.string(getViewLabel(view))}
             </a>
           </li>
         )
       ->Belt.List.toArray
       |> React.array}
    </ul>
  </div>;
};
