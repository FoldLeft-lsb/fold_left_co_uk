[@react.component]
let make = (~height: string, ~width: string, ~title=?, ~src: string) => {
  <iframe src ?title width height />;
};
