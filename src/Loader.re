type phase =
  | Loading
  | Error
  | Ok;

type state = {
  node: Yoga.Node.t,
  text_node: Yoga.Node.t,
};

let fullScreenNode = () =>
  Yoga.Node.create({
    width: Window.width,
    height: Window.height,
    justify_content: Center,
    flex_direction: Column,
    align_items: Center,
  });

let loaderStyle = Style.(reset |> bgColor(Style.Background) |> zIndex(-10));
let textStyle = Style.(reset |> textColor(Style.Black));

let component = ReasonReact.statelessComponent("Loader");
let make = (~width, ~height, ~phase, children) => {
  let text_node =
    Yoga.Node.create({
      /* TODO(@ostera): this should 100% be known from the text+typeface */
      width: 70,
      height: 20,
      justify_content: Center,
      flex_direction: Column,
      align_items: Center,
    });
  let node =
    fullScreenNode()
    |> Yoga.Node.insertChild(text_node, 0)
    |> Yoga.Node.calculateLayout({width, height, direction: Left_to_right});
  {
    ...component,
    render: _self =>
      <div style={Style.project(node, loaderStyle)}>
        {
          switch (phase) {
          | Ok => ReasonReact.array(children)
          | Error => <Text node=text_node style=textStyle> "ERROR" </Text>
          | Loading =>
            <Text node=text_node style=textStyle> "Loading..." </Text>
          }
        }
      </div>,
  };
};
