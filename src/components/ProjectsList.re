open RadixUI.Themes;
open Util;

[@react.component]
let make = (~theme, ~setTheme) => {
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
  <Theme
    appearance={get_theme_name(theme)}
    accentColor="mint"
    grayColor="gray"
    panelBackground="solid"
    radius="medium">
    <Box
      _as="div"
      className="GameGoblin-ui"
      style={backgroundColor: "var(--gray-a2)"}>
      <Container size="4" p="4" pt="8" pb="8">
        <Text _as="p" size="8" weight="bold">
          {React.string("Projects")}
        </Text>
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
             | Loading => React.null
             | Failure(msg) =>
               <div>
                 <p> {React.string("Error: ")} </p>
                 <p> {React.string(msg)} </p>
               </div>
             | Loaded(projects) =>
               Belt.List.mapWithIndex(projects, (i, project) => {
                 <ProjectsListItem
                   key={"project_" ++ string_of_int(i)}
                   project
                 />
               })
               ->Belt.List.toArray
               |> React.array
             }}
          </Flex>
        </ScrollArea>
      </Container>
    </Box>
    <Conclusion />
    <DarkThemeSwitch theme setTheme />
  </Theme>;
};
