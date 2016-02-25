#ifndef __SIJAGUR_H_
#define __SIJAGUR_H_

#include "../lib/polygon.h" 

struct SiJagur : public Polygon {
  SiJagur() {
    addPoint(Point<double>(800,600));
    addPoint(Point<double>(800,500));
    addPoint(Point<double>(700,500));
    addPoint(Point<double>(700,300));
    addPoint(Point<double>(600,300));
    addPoint(Point<double>(600,0));
    addPoint(Point<double>(500,0));
    addPoint(Point<double>(500,200));
    addPoint(Point<double>(300,200));
    addPoint(Point<double>(300,0));
    addPoint(Point<double>(200,0));
    addPoint(Point<double>(200,500));
    addPoint(Point<double>(200,300));
    addPoint(Point<double>(100,300));
    addPoint(Point<double>(100,500));
    addPoint(Point<double>(0,500));
    addPoint(Point<double>(0,600));
  }
};

#endif
