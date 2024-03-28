switch (ReactDOM.querySelector("#root")) {
| Some(element) =>
  ReactDOM.Client.render(ReactDOM.Client.createRoot(element), <Router />)
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
};
