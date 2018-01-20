#ifndef __SERAM_H_
#define __SERAM_H_

#include <polygon.h> 

struct Seram : public Polygon {
  Seram() {

    addPoint(Point<double>(518,194));
    addPoint(Point<double>(529,194));
    addPoint(Point<double>(533,195));
    addPoint(Point<double>(540,192));
    addPoint(Point<double>(547,196));
    addPoint(Point<double>(553,195));
    addPoint(Point<double>(556,197));
    addPoint(Point<double>(556,202));
    addPoint(Point<double>(560,205));
    addPoint(Point<double>(558,209));
    addPoint(Point<double>(539,200));
    addPoint(Point<double>(539,203));
    addPoint(Point<double>(532,203));
    addPoint(Point<double>(527,201));
  }
};

#endif
/* Koordinatnya:
518,194
529,194
533,195
540,192
547,196
553,195
556,197
556,202
560,205
558,209
539,200
539,203
532,203
527,201
518,194*/