#ifndef __JENDELA_H_
#define __JENDELA_H_

#include "../lib/polygon.h" 

struct Jendela : public Polygon {
  Jendela() {
    addPoint(Point(350,280));
    addPoint(Point(450,280));
    addPoint(Point(450,320));
    addPoint(Point(350,320));
  }
};

#endif
