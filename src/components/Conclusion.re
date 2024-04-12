open RadixUI.Themes;

[@react.component]
let make = () => {
  <Flex
    _as="div" display="flex" justify="center" direction="column" className="">
    <Container size="2" p="4" pt="9">
      <Box pb="4">
        <Text _as="p" size="4">
          {React.string(
             "Everything here is MIT licensed, check the repo if you'd like to use any of the code.",
           )}
        </Text>
      </Box>
    </Container>
  </Flex>;
};
