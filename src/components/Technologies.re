open RadixUI.Themes;

let techs = [
  (
    "Strong",
    "14rem",
    [
      "ReasonML for JS",
      "JavaScript/React",
      "Linux sysadmin/Cloud",
      "Problem solving",
      "Learning new things",
    ],
  ),
  (
    "Competent",
    "16rem",
    [
      "ReasonML/OCaml native",
      "Relational Database",
      "DevOps/CI/CD",
      "System Design",
      "TypeScript",
      "Python and Ruby",
    ],
  ),
  (
    "Future",
    "14rem",
    [
      "WebAssembly/WebGL",
      "C and C++",
      "Shader/GLSL",
      "Rust? Elixir?",
      "Haskell?",
    ],
  ),
];

[@react.component]
let make = () => {
  <Flex
    _as="div" display="flex" justify="center" direction="column" className="">
    <Container size="2" p="4" pt="8">
      <Text _as="p" size="8" weight="bold">
        {React.string("Technologies")}
      </Text>
      <Flex
        _as="div"
        display="flex"
        justify="flex-start"
        direction="column"
        pt="9"
        className="">
        {techs
         ->Belt.List.mapWithIndex((i, (title, height, values)) => {
             <Box height pt="8" key={title ++ "_" ++ string_of_int(i)}>
               <Text _as="p" size="6" weight="bold">
                 {React.string(title)}
               </Text>
               {values
                ->Belt.List.mapWithIndex((j, v) => {
                    <Text
                      _as="p"
                      size="4"
                      key={
                        title ++ "_" ++ string_of_int(i) ++ string_of_int(j)
                      }>
                      {React.string(v)}
                    </Text>
                  })
                ->Belt.List.toArray
                |> React.array}
             </Box>
           })
         ->Belt.List.toArray
         |> React.array}
      </Flex>
    </Container>
  </Flex>;
};
