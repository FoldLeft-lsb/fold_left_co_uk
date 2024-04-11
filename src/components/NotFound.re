open RadixUI.Themes;

[@react.component]
let make = () => {
  <Container size="2" p="9">
    <Text _as="p" size="8" weight="bold">
      {React.string("Page not found")}
    </Text>
  </Container>;
};
