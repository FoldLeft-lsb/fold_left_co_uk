open RadixUI.Themes;

[@react.component]
let make = (~msg: string) => {
  <Container size="2" p="9">
    <Text _as="p" size="8" weight="bold">
      {React.string("Encountered an error")}
    </Text>
    <Text _as="p" size="6"> {React.string(msg)} </Text>
  </Container>;
};
