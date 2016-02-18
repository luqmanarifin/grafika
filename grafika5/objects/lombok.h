#ifndef __LOMBOK_H_
#define __LOMBOK_H_

#include "../lib/polygon.h" 

struct Lombok : public Polygon {
  Lombok() {
    addPoint(Point(330,285));
    addPoint(Point(332,281));
    addPoint(Point(338,277));
    addPoint(Point(342,278));
    addPoint(Point(341,282));
    addPoint(Point(338,288));
    addPoint(Point(330,285));
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