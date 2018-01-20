#ifndef __PELURU_H_
#define __PELURU_H_

#include <polygon.h> 

struct Peluru : public Polygon {
  Peluru() {
    addPoint(Point<double>(300,600));
    addPoint(Point<double>(500,600));
    addPoint(Point<double>(500,200));
    addPoint(Point<double>(550,200));
    addPoint(Point<double>(450,0));
    addPoint(Point<double>(350,0));
    addPoint(Point<double>(250,200));
    addPoint(Point<double>(300,200));
  }
};

#endif
