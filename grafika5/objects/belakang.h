#ifndef __BELAKANG_H_
#define __BELAKANG_H_

#include "../lib/polygon.h" 

struct Belakang : public Polygon {
  Belakang() {
    addPoint(Point(0,0));
    addPoint(Point(0,600));
    addPoint(Point(800,600));
    addPoint(Point(800,0));
  }
};

#endif
