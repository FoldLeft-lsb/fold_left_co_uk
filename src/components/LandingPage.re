open RadixUI.Themes;

[@react.component]
let make = () => {
  <Flex
    _as="div"
    display="flex"
    justify="center"
    direction="column"
    className="home"
    pt="9">
    <Container size="2" pt="9" pb="9">
      <CopyWriter source="Hello World!" delay=600>
        ...{(hello_world, _) =>
          <Text _as="p" size="9" weight="bold">
            {React.string(hello_world)}
          </Text>
        }
      </CopyWriter>
    </Container>
    <Container size="2" pt="9">
      <CopyWriter
        source="https://github.com/FoldLeft-lsb" delay=2000 interval=20>
        ...{(url, finished) =>
          if (!finished) {
            <Text _as="p" size="4" weight="bold"> {React.string(url)} </Text>;
          } else {
            <Link href=url size="4" weight="bold">
              {React.string(url)}
            </Link>;
          }
        }
      </CopyWriter>
      <CopyWriter
        source="Broad spectrum Software Developer" delay=2700 interval=20>
        ...{(copy, _) =>
          <Text _as="p" size="4" weight="bold"> {React.string(copy)} </Text>
        }
      </CopyWriter>
    </Container>
  </Flex>;
};
