module Theme = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~asChild: bool=?,
      ~hasBackground: bool=?,
      // "inherit" | "light" | "dark"
      ~appearance: string=?,
      // "gray" | "gold" | "bronze" | "brown" | "yellow" | "amber" | "orange" | "tomato" | "red" | "ruby" | "crimson" | "pink" | "plum" | "purple" | "violet" | "iris" | "indigo" | "blue" | "cyan" | "teal" | "jade" | "green" | "grass" | "lime" | "mint" | "sky"
      ~accentColor: string=?,
      // "auto" | "gray" | "mauve" | "slate" | "sage" | "olive" | "sand"
      ~grayColor: string=?,
      // "solid" | "translucent"
      ~panelBackground: string=?,
      // "90%" | "95%" | "100%" | "105%" | "110%"
      ~scaling: string=?,
      // "none" | "small" | "medium" | "large" | "full"
      ~radius: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Theme";
};

module Button = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~variant: string=?,
      ~onClick: React.Event.Mouse.t => unit=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Button";
};

module Text = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  // _as = "as": "span" | "div" | "label" | "p"
  external make:
    (
      ~_as: string=?, // "as"
      ~asChild: bool=?,
      // Responsive<"1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9">
      ~size: string=?,
      // Responsive<"light" | "regular" | "medium" | "bold">
      ~weight: string=?,
      // Responsive<"left" | "center" | "right">
      ~align: string=?,
      // Responsive<"normal" | "start" | "end" | "both">
      ~trim: string=?,
      ~truncate: bool=?,
      // Responsive<"wrap" | "nowrap" | "pretty" | "balance">
      ~wrap: string=?,
      ~color: string=?,
      ~highContrast: bool=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Text";
};

module Link = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~asChild: bool=?,
      // Responsive<"1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9">
      ~size: string=?,
      // Responsive<"light" | "regular" | "medium" | "bold">
      ~weight: string=?,
      // Responsive<"normal" | "start" | "end" | "both">
      ~trim: string=?,
      ~truncate: bool=?,
      // Responsive<"wrap" | "nowrap" | "pretty" | "balance">
      ~wrap: string=?,
      // "auto" | "always" | "hover" | "none"
      ~underline: string=?,
      ~color: string=?,
      ~highContrast: bool=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Link";
};

module Flex = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~_as: string=?,
      ~asChild: bool=?,
      ~display: string=?,
      ~direction: string=?,
      ~align: string=?,
      ~justify: string=?,
      ~wrap: string=?,
      ~gap: string=?,
      ~gapX: string=?,
      ~gapY: string=?,
      ~className: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Flex";
};

module Container = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~asChild: bool=?,
      // Responsive<"1" | "2" | "3" | "4">
      ~size: string=?,
      // Responsive<"none" | "initial">
      ~display: string=?,
      // Responsive<"left" | "center" | "right">
      ~align: string=?,
      ~className: string=?,
      ~pt: string=?,
      ~pb: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Container";
};
