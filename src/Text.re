let component = ReasonReact.statelessComponent("Text");
let make = (~node, ~style, children) => {
  ...component,
  render: _self =>
    <div style={Style.project(node, style)}>
      {ReasonReact.string(children[0])}
    </div>,
};
