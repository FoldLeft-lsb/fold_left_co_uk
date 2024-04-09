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
