#ifndef __HALMAHERA_H_
#define __HALMAHERA_H_

#include "../../lib/polygon.h" 

struct Halmahera : public Polygon {
  Halmahera() {
    addPoint(Point<double>(517,114));
    addPoint(Point<double>(523,109));
    addPoint(Point<double>(524,119));
    addPoint(Point<double>(520,120));
    addPoint(Point<double>(518,114));
    addPoint(Point<double>(515,120));
    addPoint(Point<double>(516,126));
    addPoint(Point<double>(511,135));
    addPoint(Point<double>(514,137));
    addPoint(Point<double>(525,126));
    addPoint(Point<double>(526,134));
    addPoint(Point<double>(519,138));
    addPoint(Point<double>(529,146));
    addPoint(Point<double>(513,143));
    addPoint(Point<double>(515,153));
    addPoint(Point<double>(521,165));
    addPoint(Point<double>(511,154));
    addPoint(Point<double>(508,141));
    addPoint(Point<double>(505,132));
    addPoint(Point<double>(512,118));
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
