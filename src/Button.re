module S = ReactDOMRe.Style;

type t = {
  node: Yoga.Node.t,
  text: string,
};

let withText = text => {
  text,
  node:
    Yoga.Node.create({
      width: 100,
      height: 100,
      justify_content: Space_between,
      flex_direction: Row,
      align_items: Center,
    }),
};

let component = ReasonReact.statelessComponent("Button");

let style = palette =>
  S.combine(Style.palette(palette), S.make(~cursor="pointer", ()));

let make = (~node, ~mode, ~onClick, children) => {
  ...component,
  render: _self =>
    <button style={Style.project(node, style(mode))} onClick>
      {ReasonReact.array(children)}
    </button>,
};
