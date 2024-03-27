switch (ReactDOM.querySelector("#root")) {
| Some(element) =>
  let root = ReactDOM.Client.createRoot(element);
  ReactDOM.Client.render(root, <Router />);
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
};
