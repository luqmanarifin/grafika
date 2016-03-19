#ifndef __TANAHIJO_H_
#define __TANAHIJO_H_

#include "../../lib/polygon.h" 

struct TanahIjo : public Polygon {
  TanahIjo() {
    addPoint(Point<double>(0,500));
    addPoint(Point<double>(0,600));
    addPoint(Point<double>(800,600));
    addPoint(Point<double>(800,500));
  }
};

#endif
