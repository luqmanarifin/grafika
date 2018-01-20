#ifndef __BALING_H_
#define __BALING_H_

#include <polygon.h> 
using namespace std;

struct Baling : public Polygon {
  Baling() {
    addPoint(Point<double>(400,350));
    addPoint(Point<double>(634,493));
    addPoint(Point<double>(664,406));
    addPoint(Point<double>(444,275));
    addPoint(Point<double>(450,0));
    addPoint(Point<double>(350,0));
    addPoint(Point<double>(356,275));
    addPoint(Point<double>(115,406));
    addPoint(Point<double>(150,493));
  }
};

#endif
