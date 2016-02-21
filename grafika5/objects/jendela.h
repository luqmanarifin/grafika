#ifndef __JENDELA_H_
#define __JENDELA_H_

#include "../lib/polygon.h" 

struct Jendela : public Polygon {
  Jendela() {
    addPoint(Point<double>(350,280));
    addPoint(Point<double>(450,280));
    addPoint(Point<double>(450,320));
    addPoint(Point<double>(350,320));
  }
};

#endif
