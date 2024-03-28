module Wasm_App = {
  type t = {
    id: int,
    [@mel.key "type"] // this probably won't work for server
    type_: string,
    name: string,
    homepage: string,
    height: string,
    width: string,
  };
};
