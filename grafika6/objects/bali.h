#ifndef __BALI_H_
#define __BALI_H_

#include "../lib/polygon.h" 

struct Bali : public Polygon {
  Bali() {
    addPoint(Point<double>(308,275));
    addPoint(Point<double>(313,275));
    addPoint(Point<double>(318,273));
    addPoint(Point<double>(326,278));
    addPoint(Point<double>(319,284));
    addPoint(Point<double>(314,280));
    addPoint(Point<double>(310,280));
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
