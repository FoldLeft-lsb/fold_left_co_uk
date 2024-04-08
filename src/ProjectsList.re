open RadixUI;

[@react.component]
let make = () => {
  <Flex
    _as="div"
    display="flex"
    justify="center"
    direction="column"
    className="home">
    <Container size="2" pb="9">
      <CopyWriter source="Show projects here" delay=200>
        ...{(copy, _) =>
          <Text _as="p" size="9" weight="bold"> {React.string(copy)} </Text>
        }
      </CopyWriter>
    </Container>
  </Flex>;
};
