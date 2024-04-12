type style_t = {backgroundColor: string};

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
      ~className: string=?,
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
      ~onClick: React.Event.Mouse.t => unit=?,
      ~className: string=?,
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
      ~p: string=?,
      ~pt: string=?,
      ~pb: string=?,
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
      ~style: style_t=?,
      ~asChild: bool=?,
      // Responsive<"1" | "2" | "3" | "4">
      ~size: string=?,
      // Responsive<"none" | "initial">
      ~display: string=?,
      // Responsive<"left" | "center" | "right">
      ~align: string=?,
      ~className: string=?,
      ~p: string=?,
      ~pt: string=?,
      ~pb: string=?,
      ~px: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Container";
};

module ScrollArea = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~asChild: bool=?,
      // Responsive<"1" | "2" | "3">
      ~size: string=?,
      // "none" | "small" | "medium" | "large" | "full"
      ~radius: string=?,
      // "vertical" | "horizontal" | "both"
      ~scrollbars: string=?,
      ~className: string=?,
      ~_type: string=?,
      ~pt: string=?,
      ~pb: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "ScrollArea";
};

module Box = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~_as: string=?, // "div" | "span"
      ~asChild: bool=?,
      ~style: style_t=?,
      // Responsive<"none" | "inline" | "inline-block" | "block">
      ~display: string=?,
      ~className: string=?,
      ~p: string=?,
      ~pt: string=?,
      ~pb: string=?,
      ~maxWidth: string=?,
      ~width: string=?,
      ~height: string=?,
      ~children: React.element=?,
      unit
    ) =>
    React.element =
    "Box";
};

module Switch = {
  [@mel.module "@radix-ui/themes"] [@react.component]
  external make:
    (
      ~asChild: bool=?,
      ~defaultChecked: bool=?,
      ~checked: bool=?,
      ~disabled: bool=?,
      ~required: bool=?,
      ~name: string=?,
      ~value: string=?,
      ~onCheckedChange: bool => unit=?,
      // Responsive<"1" | "2" | "3">
      ~size: string=?,
      // "classic" | "surface" | "soft"
      ~variant: string=?,
      // enum
      ~color: string=?,
      ~highContrast: bool=?,
      ~radius: string=?,
      ~style: style_t=?,
      ~className: string=?,
      unit
    ) =>
    React.element =
    "Switch";
};
