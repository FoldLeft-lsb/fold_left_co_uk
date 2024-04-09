// Yojson produces a warning indicating it can't be properly
// compiled to JS by melange, so I guess it's separate JSON
// utils for front and back ends

module Demo_App = {
  type t = {
    id: int,
    _type: string,
    name: string,
    homepage: string,
    height: string,
    width: string,
  };
};

module Project = {
  type t = {
    id: int,
    _type: string,
    name: string,
    description: string,
    controls: option(string),
    demo_id: option(int),
  };
};
