// Yojson produces a warning indicating it can't be properly
// compiled to JS by melange, so I guess it's separate JSON
// utils for front and back ends

module Demo_App = {
  type t = {
    id: int,
    [@mel.key "type"] // this probably won't work for server
    type_: string,
    name: string,
    homepage: string,
    height: string,
    width: string,
    description: string,
    controls: string,
  };
};
