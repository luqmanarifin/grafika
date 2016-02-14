#ifndef __PARACHUTE_H_
#define __PARACHUTE_H_

#include "../lib/polygon.h" 

struct Parachute : public Polygon {
  Parachute() {
    addPoint(Point(75,350));
    addPoint(Point(25,400));
    addPoint(Point(0,200));
    addPoint(Point(50,150));
    addPoint(Point(200,100));
    addPoint(Point(600,100));
    addPoint(Point(750,150));
    addPoint(Point(800,200));
    addPoint(Point(775,400));
    addPoint(Point(725,350));
    addPoint(Point(575,300));
    addPoint(Point(550,600));
    addPoint(Point(525,600));
    addPoint(Point(550,300));
    addPoint(Point(250,300));
    addPoint(Point(275,600));
    addPoint(Point(250,600));
    addPoint(Point(225,300));
  }
};

#endif
