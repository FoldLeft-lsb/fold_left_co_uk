open RadixUI.Themes;

[@react.component]
let make = () => {
  <Link
    className="back-button"
    onClick={e => {
      React.Event.Mouse.preventDefault(e);
      ReasonReactRouter.push("/");
    }}
    href="/">
    {React.string("< Back")}
  </Link>;
};
