module S = ReactDOMRe.Style;

let component = ReasonReact.statelessComponent("NavBar");
let make =
    (~rootNode, ~nextButton, ~prevButton, ~onNext, ~onPrev, ~width, _children) => {
  ...component,
  render: _self =>
    <nav style=Style.(project(rootNode, reset |> zIndex(100)))>
      <Button node={nextButton.Button.node} mode=Info onClick=onNext>
        {ReasonReact.string(nextButton.text)}
      </Button>
      <Button node={prevButton.Button.node} mode=Secondary onClick=onPrev>
        {ReasonReact.string(prevButton.text)}
      </Button>
    </nav>,
};
