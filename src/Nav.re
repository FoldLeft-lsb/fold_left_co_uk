type view_t =
  | Home
  | GamesList
  | Game(int)
  | NotFound;

let getViewLabel = view =>
  switch (view) {
  | Home => "Home"
  | GamesList => "Games List"
  | Game(_id) => "Game"
  | NotFound => ""
  };

let getViewHref = view =>
  switch (view) {
  | Home => "/"
  | GamesList => "/apps"
  | Game(id) => "/apps?id=" ++ string_of_int(id)
  | NotFound => ""
  };

module NavItem = {
  [@react.component]
  let make = (~view: view_t, ~selected: bool) => {
    <li className={"nav-item " ++ (selected ? "selected" : "")}>
      <a
        href={getViewHref(view)}
        onClick={e => {
          React.Event.Mouse.preventDefault(e);
          ReasonReactRouter.push(getViewHref(view));
        }}>
        {React.string(getViewLabel(view))}
      </a>
    </li>;
  };
};

[@react.component]
let make = (~currentView) => {
  <div className="nav">
    <ul>
      {[Home, GamesList]
       ->Belt.List.mapWithIndex((i, view) =>
           <NavItem
             key={string_of_int(i)}
             view
             selected={view == currentView}
           />
         )
       ->Belt.List.toArray
       |> React.array}
    </ul>
  </div>;
};
