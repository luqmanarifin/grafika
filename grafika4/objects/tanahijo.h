#ifndef __TANAHIJO_H_
#define __TANAHIJO_H_

#include "../lib/polygon.h" 

struct TanahIjo : public Polygon {
  TanahIjo() {
    addPoint(Point(0,500));
    addPoint(Point(0,600));
    addPoint(Point(800,600));
    addPoint(Point(800,500));
  }
};

#endif
