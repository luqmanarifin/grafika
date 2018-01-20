#ifndef __PARACHUTE_H_
#define __PARACHUTE_H_

#include <polygon.h> 

struct Parachute : public Polygon {
  Parachute() {
    addPoint(Point<double>(75,350));
    addPoint(Point<double>(25,400));
    addPoint(Point<double>(0,200));
    addPoint(Point<double>(50,150));
    addPoint(Point<double>(200,100));
    addPoint(Point<double>(600,100));
    addPoint(Point<double>(750,150));
    addPoint(Point<double>(800,200));
    addPoint(Point<double>(775,400));
    addPoint(Point<double>(725,350));
    addPoint(Point<double>(575,300));
    addPoint(Point<double>(550,600));
    addPoint(Point<double>(525,600));
    addPoint(Point<double>(550,300));
    addPoint(Point<double>(250,300));
    addPoint(Point<double>(275,600));
    addPoint(Point<double>(250,600));
    addPoint(Point<double>(225,300));
  }
};

#endif
