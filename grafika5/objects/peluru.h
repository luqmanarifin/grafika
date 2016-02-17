#ifndef __PELURU_H_
#define __PELURU_H_

#include "../lib/polygon.h" 

struct Peluru : public Polygon {
  Peluru() {
    addPoint(Point(300,600));
    addPoint(Point(500,600));
    addPoint(Point(500,200));
    addPoint(Point(550,200));
    addPoint(Point(450,0));
    addPoint(Point(350,0));
    addPoint(Point(250,200));
    addPoint(Point(300,200));
  }
};

#endif
