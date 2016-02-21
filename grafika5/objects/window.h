#ifndef __WINDOW_H_
#define __WINDOW_H_

#include "../lib/polygon.h" 

struct Window : public Polygon {
  Window(int a, int b) {
    addPoint(Point(a,b));
    addPoint(Point(a,800));
    addPoint(Point(1400,800));
    addPoint(Point(1400,b));
  }
};

#endif
