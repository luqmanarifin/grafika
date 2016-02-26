#ifndef __Halmahera_H_
#define __Halmahera_H_

#include "../../lib/polygon.h" 

struct Halmahera : public Polygon {
  Halmahera() {
    addPoint(Point<double>(300, 100));
    addPoint(Point<double>(330, 100));
    addPoint(Point<double>(330, 130));
    addPoint(Point<double>(360, 130));
    addPoint(Point<double>(360, 100));
    addPoint(Point<double>(390, 100));
    addPoint(Point<double>(390, 130));
    addPoint(Point<double>(380, 130));
    addPoint(Point<double>(380, 160));
    addPoint(Point<double>(400, 160));
    addPoint(Point<double>(430, 160));
    addPoint(Point<double>(430, 190));
    addPoint(Point<double>(360, 190));
    addPoint(Point<double>(360, 220));
    addPoint(Point<double>(370, 220));
    addPoint(Point<double>(370, 250));
    addPoint(Point<double>(385, 250));
    addPoint(Point<double>(385, 280));
    addPoint(Point<double>(355, 280));
    addPoint(Point<double>(355, 250));
    addPoint(Point<double>(335, 250));
    addPoint(Point<double>(335, 220));
    addPoint(Point<double>(320, 220));
    addPoint(Point<double>(320, 190));
    addPoint(Point<double>(300, 190));
    addPoint(Point<double>(300, 160));
    addPoint(Point<double>(290, 160));
    addPoint(Point<double>(290, 130));
    addPoint(Point<double>(300, 130));
    
  }
};

#endif
