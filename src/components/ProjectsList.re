open RadixUI.Themes;

[@react.component]
let make = () => {
  let (
    projects: Api.ProjectRest.res_t(list(Common.Types.Project.t)),
    setProjects,
  ) =
    React.useState(() => Api.ProjectRest.NotStarted);
  React.useEffect0(() => {
    setProjects(_ => Loading);
    Api.ProjectRest.fetch_projects()
    |> Js.Promise.then_(result => {
         switch (result) {
         | Error(msg) => setProjects(_ => Failure(msg))
         | Ok(projects) => setProjects(_ => Loaded(projects))
         };
         Js.Promise.resolve();
       })
    |> ignore;
    None;
  });
  <Flex
    _as="div" display="flex" justify="center" direction="column" className="">
    <Container size="4" p="4" pt="8" pb="8">
      <Text _as="p" size="8" weight="bold"> {React.string("Projects")} </Text>
      <ScrollArea _type="always" scrollbars="horizontal">
        <Flex
          _as="div"
          display="flex"
          justify="flex-start"
          direction="row"
          pt="9"
          className="">
          {switch (projects) {
           | NotStarted
           | Loading => <p> {React.string("Loading")} </p>
           | Failure(msg) =>
             <div>
               <p> {React.string("Error: ")} </p>
               <p> {React.string(msg)} </p>
             </div>
           | Loaded(projects) =>
             Belt.List.map(projects, project => {
               <Container
                 size="2"
                 p="9"
                 style={
                   backgroundColor: "var(--gray-a2)",
                   borderRadius: "var(--radius-3)",
                 }>
                 <Box maxWidth="20rem" height="20rem">
                   <Text _as="p" size="6" weight="bold">
                     {React.string(project.name)}
                   </Text>
                   <Text _as="p" size="4" weight="bold">
                     {React.string(project._type)}
                   </Text>
                   <br />
                   <Text _as="p" size="2" weight="bold">
                     {React.string(project.description)}
                   </Text>
                   {switch (project.demo_id) {
                    | None => React.null
                    | Some(demo_id) =>
                      let url = "/apps?id=" ++ string_of_int(demo_id);
                      <>
                        <br />
                        <Link
                          onClick={e => {
                            React.Event.Mouse.preventDefault(e);
                            ReasonReactRouter.push(url);
                          }}
                          href=url
                          size="2"
                          weight="bold">
                          {React.string("Play the Demo")}
                        </Link>
                      </>;
                    }}
                 </Box>
               </Container>
             })
             ->Belt.List.toArray
             |> React.array
           }}
        </Flex>
      </ScrollArea>
    </Container>
  </Flex>;
};
