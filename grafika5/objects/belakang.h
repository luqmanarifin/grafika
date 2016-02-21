#ifndef __BELAKANG_H_
#define __BELAKANG_H_

#include "../lib/polygon.h" 

struct Belakang : public Polygon {
  Belakang() {
    addPoint(Point(0,0));
    addPoint(Point(0,768));
    addPoint(Point(1366,768));
    addPoint(Point(1366,0));
  }
};

#endif
