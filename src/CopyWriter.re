type timer_t;
[@mel.val] external setTimeout: (unit => unit, int) => timer_t = "setTimeout";
[@mel.val] external clearTimeout: timer_t => unit = "clearTimeout";

// Idk if this is dumb but it is wicked!

[@react.component]
let make =
    (~source: string, ~interval: int=100, ~children: string => React.element) => {
  let source_chars = Js.String.split(~sep="", ~limit=-1, source);
  let target = Js.String.length(source);

  let (counter, setCounter) = React.useState(() => 0);
  let (output, setOutput) = React.useState(() => "");

  React.useEffect1(
    () =>
      if (counter >= target) {
        None;
      } else {
        let adj_interval =
          interval + int_of_float((Js.Math.random() -. 0.5) *. 50.);
        let timer =
          setTimeout(
            () => {
              setOutput(acc => acc ++ source_chars[counter]);
              setCounter(acc => acc + 1);
            },
            adj_interval,
          );
        Some(() => clearTimeout(timer));
      },
    [|output|],
  );
  children(output);
};
