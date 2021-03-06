#ifndef __KOTAK_H_
#define __KOTAK_H_

#include <polygon.h> 

struct Kotak : public Polygon {
  Kotak(Point<double> a, Point<double> b) {
    addPoint(a);
    addPoint(Point<double>(b.x, a.y));
    addPoint(b);
    addPoint(Point<double>(a.x, b.y));
  }
};

#endif
