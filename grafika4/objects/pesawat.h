#ifndef __PESAWAT_H_
#define __PESAWAT_H_

#include "../../lib/polygon.h" 

struct Pesawat : public Polygon {
  Pesawat() {
    addPoint(Point<double>(450,200));
    addPoint(Point<double>(460,200));
    addPoint(Point<double>(460,210));
    addPoint(Point<double>(470,210));
    addPoint(Point<double>(470,220));
    addPoint(Point<double>(480,220));
    addPoint(Point<double>(480,230));
    addPoint(Point<double>(490,230));
    addPoint(Point<double>(490,240));
    addPoint(Point<double>(500,240));
    addPoint(Point<double>(500,290));
    addPoint(Point<double>(750,290));
    addPoint(Point<double>(750,300));
    addPoint(Point<double>(700,300));
    addPoint(Point<double>(700,310));
    addPoint(Point<double>(500,310));
    addPoint(Point<double>(500,360));
    addPoint(Point<double>(490,360));
    addPoint(Point<double>(490,370));
    addPoint(Point<double>(480,370));
    addPoint(Point<double>(480,380));
    addPoint(Point<double>(470,380));
    addPoint(Point<double>(470,390));
    addPoint(Point<double>(460,390));
    addPoint(Point<double>(460,400));
    addPoint(Point<double>(340,400));
    addPoint(Point<double>(340,390));
    addPoint(Point<double>(330,390));
    addPoint(Point<double>(330,380));
    addPoint(Point<double>(320,380));
    addPoint(Point<double>(320,370));
    addPoint(Point<double>(310,370));
    addPoint(Point<double>(310,360));
    addPoint(Point<double>(300,360));
    addPoint(Point<double>(300,310));
    addPoint(Point<double>(100,310));
    addPoint(Point<double>(100,300));
    addPoint(Point<double>(50,300));
    addPoint(Point<double>(50,290));
    addPoint(Point<double>(300,290));
    addPoint(Point<double>(300,240));
    addPoint(Point<double>(310,240));
    addPoint(Point<double>(310,230));
    addPoint(Point<double>(320,230));
    addPoint(Point<double>(320,220));
    addPoint(Point<double>(330,220));
    addPoint(Point<double>(330,210));
    addPoint(Point<double>(340,210));
    addPoint(Point<double>(340,200));
    addPoint(Point<double>(390,200));
    addPoint(Point<double>(390,140));
    addPoint(Point<double>(395,140));
    addPoint(Point<double>(395,100));
    addPoint(Point<double>(405,100));
    addPoint(Point<double>(405,140));
    addPoint(Point<double>(410,140));
    addPoint(Point<double>(410,200));
  }
};

#endif
