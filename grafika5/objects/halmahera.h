#ifndef __HALMAHERA_H_
#define __HALMAHERA_H_

#include "../lib/polygon.h" 

struct Halmahera : public Polygon {
  Halmahera() {
    addPoint(Point(517,114));
    addPoint(Point(523,109));
    addPoint(Point(524,119));
    addPoint(Point(520,120));
    addPoint(Point(518,114));
    addPoint(Point(515,120));
    addPoint(Point(516,126));
    addPoint(Point(511,135));
    addPoint(Point(514,137));
    addPoint(Point(525,126));
    addPoint(Point(526,134));
    addPoint(Point(519,138));
    addPoint(Point(529,146));
    addPoint(Point(513,143));
    addPoint(Point(515,153));
    addPoint(Point(521,165));
    addPoint(Point(511,154));
    addPoint(Point(508,141));
    addPoint(Point(505,132));
    addPoint(Point(512,118));
  }
};

#endif
/*
Halmahera
517,114
523,109
524,119
520,120
518,114
515,120
516,126
511,135
514,137
525,126
526,134
519,138
529,146
513,143
515,153
521,165
511,154
508,141
505,132
512,118
*/
