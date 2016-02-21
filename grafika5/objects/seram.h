#ifndef __SERAM_H_
#define __SERAM_H_

#include "../lib/polygon.h" 

struct Seram : public Polygon {
  Seram() {

    addPoint(Point(518,194));
    addPoint(Point(529,194));
    addPoint(Point(533,195));
    addPoint(Point(540,192));
    addPoint(Point(547,196));
    addPoint(Point(553,195));
    addPoint(Point(556,197));
    addPoint(Point(556,202));
    addPoint(Point(560,205));
    addPoint(Point(558,209));
    addPoint(Point(539,200));
    addPoint(Point(539,203));
    addPoint(Point(532,203));
    addPoint(Point(527,201));
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