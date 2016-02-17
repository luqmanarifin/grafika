#ifndef __BALING_H_
#define __BALING_H_

#include "../lib/polygon.h" 
using namespace std;

struct Baling : public Polygon {
  Baling() {
    addPoint(Point(400,350));
    addPoint(Point(634,493));
    addPoint(Point(664,406));
    addPoint(Point(444,275));
    addPoint(Point(450,0));
    addPoint(Point(350,0));
    addPoint(Point(356,275));
    addPoint(Point(115,406));
    addPoint(Point(150,493));
  }
};

#endif
