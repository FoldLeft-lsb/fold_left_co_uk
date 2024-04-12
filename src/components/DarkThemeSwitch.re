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
        set_stored_theme(Dark);
        setTheme(_ => Dark);
      } else {
        set_stored_theme(Light);
        setTheme(_ => Light);
      }
    }
  />;
};
