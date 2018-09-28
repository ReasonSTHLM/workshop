// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Yoga = require("@ostera/reiki/lib/js/src/Yoga.bs.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var Slide$Workshop = require("./Slide.bs.js");
var Style$Workshop = require("./Style.bs.js");
var Button$Workshop = require("./Button.bs.js");
var NavBar$Workshop = require("./NavBar.bs.js");

function nextSlide(param) {
  if (param !== 1) {
    if (param !== 0) {
      return /* Thanks */3;
    } else {
      return /* Workshop */1;
    }
  } else {
    return /* Links */2;
  }
}

function prevSlide(param) {
  if (param !== 2) {
    if (param >= 3) {
      return /* Links */2;
    } else {
      return /* Intro */0;
    }
  } else {
    return /* Workshop */1;
  }
}

var component = ReasonReact.reducerComponent("Layout");

function make(width, height, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* slide */3];
              var tmp;
              switch (match) {
                case 0 : 
                    tmp = ReasonReact.element(undefined, undefined, Slide$Workshop.Intro[/* make */1](self[/* state */1][/* contentNode */2], /* array */[]));
                    break;
                case 1 : 
                    tmp = ReasonReact.element(undefined, undefined, Slide$Workshop.Workshop[/* make */1](self[/* state */1][/* contentNode */2], /* array */[]));
                    break;
                case 2 : 
                    tmp = ReasonReact.element(undefined, undefined, Slide$Workshop.Links[/* make */1](self[/* state */1][/* contentNode */2], /* array */[]));
                    break;
                case 3 : 
                    tmp = ReasonReact.element(undefined, undefined, Slide$Workshop.Thanks[/* make */1](self[/* state */1][/* contentNode */2], /* array */[]));
                    break;
                
              }
              return React.createElement("div", {
                          style: Style$Workshop.project(self[/* state */1][/* root */0], Style$Workshop.zIndex(10, Style$Workshop.reset))
                        }, ReasonReact.element(undefined, undefined, NavBar$Workshop.make(self[/* state */1][/* navNode */1], self[/* state */1][/* buttons */4][/* next */0], self[/* state */1][/* buttons */4][/* prev */1], (function () {
                                    return Curry._1(self[/* send */3], /* Next */0);
                                  }), (function () {
                                    return Curry._1(self[/* send */3], /* Prev */1);
                                  }), width, /* array */[])), tmp);
            }),
          /* initialState */(function () {
              var buttons_000 = /* next */Button$Workshop.withText("next");
              var buttons_001 = /* prev */Button$Workshop.withText("prev");
              var buttons = /* record */[
                buttons_000,
                buttons_001
              ];
              var navNode = Yoga.Node[/* insertChild */1](buttons_001[/* node */0], 1, Yoga.Node[/* insertChild */1](buttons_000[/* node */0], 0, Yoga.Node[/* create */0](/* record */[
                            /* width */width,
                            /* height */100,
                            /* justify_content : Space_between */3,
                            /* flex_direction : Row */2,
                            /* align_items : Center */2
                          ])));
              var contentNode = Yoga.Node[/* create */0](/* record */[
                    /* width */width,
                    /* height */height,
                    /* justify_content : Space_between */3,
                    /* flex_direction : Row */2,
                    /* align_items : Center */2
                  ]);
              return /* record */[
                      /* root */Yoga.Node[/* calculateLayout */2](/* record */[
                            /* width */window.visualViewport.width,
                            /* height */window.visualViewport.height,
                            /* direction : Right_to_left */2
                          ], Yoga.Node[/* insertChild */1](contentNode, 1, Yoga.Node[/* insertChild */1](navNode, 0, Yoga.Node[/* create */0](/* record */[
                                        /* width */width,
                                        /* height */height,
                                        /* justify_content : Flex_start */0,
                                        /* flex_direction : Column */0,
                                        /* align_items : Flex_start */1
                                      ])))),
                      /* navNode */navNode,
                      /* contentNode */contentNode,
                      /* slide : Intro */0,
                      /* buttons */buttons
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [/* record */[
                            /* root */state[/* root */0],
                            /* navNode */state[/* navNode */1],
                            /* contentNode */state[/* contentNode */2],
                            /* slide */prevSlide(state[/* slide */3]),
                            /* buttons */state[/* buttons */4]
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* root */state[/* root */0],
                            /* navNode */state[/* navNode */1],
                            /* contentNode */state[/* contentNode */2],
                            /* slide */nextSlide(state[/* slide */3]),
                            /* buttons */state[/* buttons */4]
                          ]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var S = 0;

exports.S = S;
exports.nextSlide = nextSlide;
exports.prevSlide = prevSlide;
exports.component = component;
exports.make = make;
/* component Not a pure module */