#ifndef __LOMBOK_H_
#define __LOMBOK_H_

#include "../lib/polygon.h" 

struct Lombok2 : public Polygon {
  Lombok2() {
    addPoint(Point<double>(330,285));
    addPoint(Point<double>(332,281));
    addPoint(Point<double>(338,277));
    addPoint(Point<double>(342,278));
    addPoint(Point<double>(341,282));
    addPoint(Point<double>(338,288));
    addPoint(Point<double>(330,285));
  }
};

#endif
/*
Lombok
330,285
332.281
338,277
342,278
341,282
338,288
330,285
*/
