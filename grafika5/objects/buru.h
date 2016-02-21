#ifndef __BURU_H_
#define __BURU_H_

#include "../lib/polygon.h" 

struct Buru : public Polygon {
  Buru() {
    addPoint(Point(487,197));
    addPoint(Point(494,197));
    addPoint(Point(502,200));
    addPoint(Point(503,206));
    addPoint(Point(496,208));
    addPoint(Point(485,202));
    addPoint(Point(486,197));

  }
};

#endif
/*
P.Buru
487,197
494,197
502,200
503,206
496,208
485,202
486,197
*/
