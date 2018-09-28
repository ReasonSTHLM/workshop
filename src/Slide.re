module S = ReactDOMRe.Style;
let str = ReasonReact.string;

module Common = {
  let style = palette =>
    S.combine(
      Style.palette(palette),
      S.make(~textAlign="center", ~fontSize="48px", ()),
    );

  let a = (palette, href, text) =>
    <a
      style={
        S.combine(
          Style.palette(palette),
          S.make(
            ~padding="30px",
            ~display="block",
            ~textDecoration="none",
            (),
          ),
        )
      }
      href>
      {str(text)}
    </a>;
};

module type Base = {
  let name: string;
  let theme: Style.theme;
  let body: ReasonReact.reactElement;
};

module Make = (B: Base) => {
  let component = ReasonReact.statelessComponent(B.name);

  let make = (~node, _children) => {
    ...component,
    render: _self =>
      <section style={Style.project(node, Common.style(B.theme))}>
        B.body
      </section>,
  };
};

module Intro =
  Make({
    let name = "Slide.Intro";
    let theme = Style.Primary;
    let body =
      <fragment>
        <h1>
          {ReasonReact.string({j|Welcome to the Reason Workshop! 🎉|j})}
        </h1>
        <p>
          {
            Common.a(
              Primary,
              {j|https://github.com/ostera|j},
              {j|👤 @ostera|j},
            )
          }
          {
            Common.a(
              Primary,
              {j|https://go/toolbox|j},
              {j|👥 #content-toolbox|j},
            )
          }
          {
            Common.a(
              Primary,
              "https://github.com/ReasonSTHLM",
              {j|🗣 #reasonml|j},
            )
          }
          {
            Common.a(
              Primary,
              "https://meetup.com/ReasonSTHLM",
              {j|🗓 ReasonSTHLM Meetup|j},
            )
          }
        </p>
      </fragment>;
  });

module Workshop =
  Make({
    let name = "Slide.Workshop";
    let theme = Style.Secondary;
    let body =
      <fragment>
        <h1> {str({j|Let's get our hands dirty|j})} </h1>
        <p> {str({j|Setup and Intro|j})} </p>
        <p> {str({j|What is Reason?|j})} </p>
        <p> {str({j|A sample app|j})} </p>
        <p> {str({j|ReasonReact|j})} </p>
        <p> {str({j|State of the Ecosystem|j})} </p>
      </fragment>;
  });

module Thanks =
  Make({
    let name = "Slide.Thanks";
    let theme = Style.Primary;
    let body =
      <fragment>
        <h1> {str({j|Stay Reasonable 🙌🏼|j})} </h1>
        <p> {str({j|And thanks for coming.|j})} </p>
        <p> {str({j|@ostera|j})} </p>
      </fragment>;
  });

module Links =
  Make({
    let name = "Slide.Links";
    let theme = Style.Secondary;
    let body =
      <fragment>
        <h1> {str({j|Useful Links|j})} </h1>
        <p>
          {
            Common.a(
              Secondary,
              "https://reasonml.github.com",
              {j|ReasonML Website|j},
            )
          }
          {
            Common.a(
              Secondary,
              "https://bucklescript.github.io",
              {j|BuckleScript Website|j},
            )
          }
          {
            Common.a(
              Primary,
              "https://reasonml.github.io/docs/en/community",
              {j|🗣 ReasonML Community|j},
            )
          }
        </p>
      </fragment>;
  });
