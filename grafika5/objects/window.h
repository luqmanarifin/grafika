#ifndef __WINDOW_H_
#define __WINDOW_H_

#include "../../lib/polygon.h" 

struct Window : public Polygon {
  Window(int a, int b) {
    addPoint(Point<double>(a,b));
    addPoint(Point<double>(a,800));
    addPoint(Point<double>(1400,800));
    addPoint(Point<double>(1400,b));
  }
};


#endif
