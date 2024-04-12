open RadixUI.Themes;

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
        <Text _as="p" size="4" weight="bold">
          {React.string(
             "Everything here should be MIT licensed as they're just toys really, check the repo if you're interested in using any of the code.",
           )}
        </Text>
      </Flex>
    </Container>
  </Flex>;
};
