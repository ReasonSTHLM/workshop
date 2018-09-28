module Style = ReactDOMRe.Style;

type color =
  | White
  | Black
  | Accent
  | Background;

let color =
  fun
  | White => "#ffffff"
  | Black => "#333333"
  | Accent => "#dd4b39"
  | Background => "#f6f4f4";

let reset =
  Style.make(
    ~margin="",
    ~padding="",
    ~position="absolute",
    ~boxSizing="border-box",
    (),
  );
