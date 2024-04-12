open RadixUI.Themes;

[@react.component]
let make = (~project: Common.Types.Project.t) => {
  <Container size="2" p="8" style={backgroundColor: "var(--gray-a2)"}>
    <Box maxWidth="20rem" height="20rem">
      <Text _as="p" size="6" weight="bold">
        {React.string(project.name)}
      </Text>
      <Text _as="p" size="4" weight="bold">
        {React.string(project._type)}
      </Text>
      <br />
      <Text _as="p" size="2"> {React.string(project.description)} </Text>
      {switch (project.link) {
       | None => React.null
       | Some(link_url) =>
         <>
           <br />
           <Link href=link_url size="2" weight="bold">
             {React.string(
                Belt.Option.getWithDefault(project.link_text, link_url),
              )}
           </Link>
         </>
       }}
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
  </Container>;
};
