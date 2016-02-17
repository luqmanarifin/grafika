#ifndef __SIJAGUR_H_
#define __SIJAGUR_H_

#include "../lib/polygon.h" 

struct SiJagur : public Polygon {
  SiJagur() {
    addPoint(Point(800,600));
    addPoint(Point(800,500));
    addPoint(Point(700,500));
    addPoint(Point(700,300));
    addPoint(Point(600,300));
    addPoint(Point(600,0));
    addPoint(Point(500,0));
    addPoint(Point(500,200));
    addPoint(Point(300,200));
    addPoint(Point(300,0));
    addPoint(Point(200,0));
    addPoint(Point(200,500));
    addPoint(Point(200,300));
    addPoint(Point(100,300));
    addPoint(Point(100,500));
    addPoint(Point(0,500));
    addPoint(Point(0,600));
  }
};

#endif
