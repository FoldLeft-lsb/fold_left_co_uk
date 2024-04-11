open RadixUI.Themes;
open Util;

[@react.component]
let make = (~theme, ~setTheme) => {
  <Switch
    className="theme-button"
    color="gray"
    size="3"
    checked={theme == Dark}
    highContrast=true
    onCheckedChange={checked =>
      if (checked) {
        set_saved_theme(Dark);
        setTheme(_ => Dark);
      } else {
        set_saved_theme(Light);
        setTheme(_ => Light);
      }
    }
  />;
};
