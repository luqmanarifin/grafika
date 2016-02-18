#ifndef __BALI_H_
#define __BALI_H_

#include "../lib/polygon.h" 

struct Bali : public Polygon {
  Bali() {
    addPoint(Point(308,275));
    addPoint(Point(313,275));
    addPoint(Point(318,273));
    addPoint(Point(326,278));
    addPoint(Point(319,284));
    addPoint(Point(314,280));
    addPoint(Point(310,280));
  }
};

#endif
/*
Bali 
308,275
313,275
318,273
326,278
319,284
314,280
310,280
308,275
*/