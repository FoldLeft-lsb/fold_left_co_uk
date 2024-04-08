type timer_t;
[@mel.val] external setTimeout: (unit => unit, int) => timer_t = "setTimeout";
[@mel.val] external clearTimeout: timer_t => unit = "clearTimeout";

let clamp_int_to = (n, c): int => n < c ? c : n;

// Idk if this is dumb but it is wicked!

[@react.component]
let make =
    (
      ~source: string,
      ~interval: int=100,
      ~delay: option(int)=?,
      ~children: (string, bool) => React.element,
    ) => {
  let buffer = Js.String.split(~sep="", ~limit=-1, source);
  let target = Js.String.length(source);

  let (start, setStart) = React.useState(() => false);
  React.useEffect0(() => {
    switch (delay) {
    | None =>
      setStart(_ => true);
      None;
    | Some(delay_amount) =>
      let timer = setTimeout(() => setStart(_ => true), delay_amount);
      Some(() => clearTimeout(timer));
    }
  });

  let (counter, setCounter) = React.useState(() => 0);
  let (output, setOutput) = React.useState(() => "");

  React.useEffect2(
    () =>
      if (!start || counter >= target) {
        None;
      } else {
        let adj_interval =
          interval
          + int_of_float(
              (Js.Math.random() -. 0.5) *. float_of_int(interval / 2),
            );
        let timer =
          setTimeout(
            () => {
              setOutput(acc => acc ++ buffer[counter]);
              setCounter(acc => acc + 1);
            },
            clamp_int_to(adj_interval, 1),
          );
        Some(() => clearTimeout(timer));
      },
    (output, start),
  );
  children(output, source == output);
};
