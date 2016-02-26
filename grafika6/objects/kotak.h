#ifndef __KOTAK_H_
#define __KOTAK_H_

#include "../../lib/polygon.h" 
#include "../../lib/point.h"

struct Kotak : public Polygon {
  Kotak(Point<double> a, Point<double> b) {
    addPoint(a);
    addPoint(Point<double>(b.x, a.y));
    addPoint(b);
    addPoint(Point<double>(a.x, b.y));
  }
};

#endif
