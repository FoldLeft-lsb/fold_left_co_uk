type greeting_t = {greeting: string};

module Wasm_App = {
  type t = {
    id: int,
    [@mel.key "type"]
    type_: string,
    name: string,
    homepage: string,
    height: string,
    width: string,
  };
};
