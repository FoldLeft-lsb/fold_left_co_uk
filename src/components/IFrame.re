[@react.component]
let make = (~height: string, ~width: string, ~title=?, ~src: string) => {
  <iframe className="demo-frame" src ?title width height />;
};
