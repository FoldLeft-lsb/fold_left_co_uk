module Demo_App = {
  type t = {
    id: int,
    _type: string,
    name: string,
    homepage: string,
    height: string,
    width: string,
    controls: string,
  };
};

module Project = {
  type t = {
    id: int,
    _type: string,
    name: string,
    description: string,
    demo_id: option(int),
    link: option(string),
    link_text: option(string),
  };
};
