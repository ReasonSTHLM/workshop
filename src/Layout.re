module S = ReactDOMRe.Style;

type slide =
  | Intro
  | Workshop
  | Links
  | Thanks;

let nextSlide =
  fun
  | Intro => Workshop
  | Workshop => Links
  | Links => Thanks
  | Thanks => Thanks;

let prevSlide =
  fun
  | Intro => Intro
  | Workshop => Intro
  | Links => Workshop
  | Thanks => Links;

type buttons = {
  next: Button.t,
  prev: Button.t,
};

type state = {
  root: Yoga.Node.t,
  navNode: Yoga.Node.t,
  contentNode: Yoga.Node.t,
  slide,
  buttons,
};

type action =
  | Next
  | Prev;

let component = ReasonReact.reducerComponent("Layout");
let make = (~width, ~height, _children) => {
  ...component,
  initialState: () => {
    let buttons = {
      next: Button.withText("next"),
      prev: Button.withText("prev"),
    };

    let navNode =
      Yoga.Node.(
        create({
          width,
          height: 100,
          justify_content: Yoga.Space_between,
          flex_direction: Row,
          align_items: Center,
        })
        |> insertChild(buttons.next.node, 0)
        |> insertChild(buttons.prev.node, 1)
      );

    let contentNode =
      Yoga.Node.create({
        width,
        height,
        justify_content: Yoga.Space_between,
        flex_direction: Row,
        align_items: Center,
      });

    {
      contentNode,
      buttons,
      navNode,
      root:
        Yoga.Node.create({
          width,
          height,
          justify_content: Flex_start,
          flex_direction: Column,
          align_items: Flex_start,
        })
        |> Yoga.Node.insertChild(navNode, 0)
        |> Yoga.Node.insertChild(contentNode, 1)
        |> Yoga.Node.calculateLayout({
             width: Window.width,
             height: Window.height,
             direction: Yoga.Right_to_left,
           }),
      slide: Intro,
    };
  },
  reducer: (action, state) =>
    switch (action) {
    | Next => ReasonReact.Update({...state, slide: nextSlide(state.slide)})
    | Prev => ReasonReact.Update({...state, slide: prevSlide(state.slide)})
    },
  render: self =>
    <div style=Style.(project(self.state.root, reset |> zIndex(10)))>
      <NavBar
        width
        rootNode={self.state.navNode}
        nextButton={self.state.buttons.next}
        prevButton={self.state.buttons.prev}
        onNext={_ => self.send(Next)}
        onPrev={_ => self.send(Prev)}
      />
      {
        switch (self.state.slide) {
        | Intro => <Slide.Intro node={self.state.contentNode} />
        | Workshop => <Slide.Workshop node={self.state.contentNode} />
        | Thanks => <Slide.Thanks node={self.state.contentNode} />
        | Links => <Slide.Links node={self.state.contentNode} />
        }
      }
    </div>,
};
