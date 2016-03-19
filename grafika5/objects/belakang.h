#ifndef __BELAKANG_H_
#define __BELAKANG_H_

#include "../../lib/polygon.h" 

struct Belakang : public Polygon {
  Belakang() {
    addPoint(Point<double>(0,0));
    addPoint(Point<double>(0,768));
    addPoint(Point<double>(1366,768));
    addPoint(Point<double>(1366,0));
  }
};

#endif
