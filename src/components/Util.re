type storage_t;
[@mel.val] external localStorage: storage_t = "localStorage";
[@mel.send]
external getItem: (storage_t, string) => Js.Nullable.t(string) = "getItem";
[@mel.send]
external setItem: (storage_t, string, Js.Nullable.t(string)) => unit =
  "setItem";

type route_t =
  | Landing
  | Demo(int)
  | NotFound;

type theme_t =
  | Light
  | Dark
  | Inherit;

let get_theme_name = th =>
  switch (th) {
  | Light => "light"
  | Dark => "dark"
  | Inherit => "inherit"
  };

let get_theme = n =>
  switch (n) {
  | "light" => Light
  | "dark" => Dark
  | "inherit" => Inherit
  | _ => Inherit
  };

let local_storage_theme_key = "selected-theme-foldleft.co.uk";

let get_saved_theme = () => {
  (localStorage->getItem(local_storage_theme_key) |> Js.Nullable.toOption)
  ->Belt.Option.map(theme => get_theme(theme))
  ->Belt.Option.getWithDefault(Dark);
};

let set_saved_theme = (theme: theme_t) => {
  localStorage->setItem(
    local_storage_theme_key,
    Js.Nullable.return(get_theme_name(theme)),
  );
};
