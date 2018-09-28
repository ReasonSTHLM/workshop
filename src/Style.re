module S = ReactDOMRe.Style;

type theme =
  | Primary
  | Secondary
  | Info;

type color =
  | Transparent
  | White
  | Black
  | Accent
  | Ok
  | Info
  | Background;

let color =
  fun
  | Transparent => "rgba(0,0,0,0)"
  | White => "#ffffff"
  | Black => "#333333"
  | Accent => "#dd4b39"
  | Ok => "#37b978"
  | Info => "#3f92db"
  | Background => "#f6f4f4";

let reset =
  S.make(
    ~margin="0",
    ~padding="0",
    ~position="absolute",
    ~boxSizing="border-box",
    ~top="0",
    ~left="0",
    ~zIndex="0",
    ~outline="none",
    (),
  );

let zIndex = (i, s) =>
  S.(make(~zIndex=string_of_int(i), ()) |> combine(s));

let bgColor = (c, s) =>
  S.(make(~backgroundColor=color(c), ()) |> combine(s));

let textColor = (c, s) => S.(make(~color=color(c), ()) |> combine(s));

let paletteStyle = (~bg, ~text, ~border) =>
  S.make(
    ~backgroundColor=color(bg),
    ~color=color(text),
    ~borderColor=color(border),
    (),
  );

let palette =
  fun
  | Primary => paletteStyle(~bg=Accent, ~text=White, ~border=Accent)
  | Info => paletteStyle(~bg=Info, ~text=White, ~border=Info)
  | Secondary => paletteStyle(~bg=White, ~text=Accent, ~border=Accent);

let project = (node, style) => {
  let layout = Yoga.Node.computedLayout(node);
  let top = string_of_int(layout.top) ++ "px";
  let left = string_of_int(layout.left) ++ "px";
  let width = string_of_int(layout.width) ++ "px";
  let height = string_of_int(layout.height) ++ "px";
  S.combine(
    style,
    S.make(
      ~position="absolute",
      ~top={j|$top|j},
      ~left={j|$left|j},
      ~width={j|$width|j},
      ~height={j|$height|j},
      (),
    ),
  );
};
