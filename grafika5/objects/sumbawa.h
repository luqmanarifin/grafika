#ifndef __SUMBAWA_H_
#define __SUMBAWA_H_

#include "../lib/polygon.h" 

struct Sumbawa : public Polygon {
  Sumbawa() {
    addPoint(Point<double>(343,281));
    addPoint(Point<double>(349,279));
    addPoint(Point<double>(354,280));
    addPoint(Point<double>(358,283));
    addPoint(Point<double>(362,284));
    addPoint(Point<double>(355,277));
    addPoint(Point<double>(363,274));
    addPoint(Point<double>(366,280));
    addPoint(Point<double>(369,277));
    addPoint(Point<double>(377,278));
    addPoint(Point<double>(380,285));
    addPoint(Point<double>(369,287));
    addPoint(Point<double>(359,288));
    addPoint(Point<double>(350,292));
    addPoint(Point<double>(343,289));
  }
};

#endif
/*
Sumbawa
343,281
349,279
354,280
358,283
362,284
355,277
363,274
366,280
369,277
377,278
380,285
369,287
359,288
350,292
343,289
343,281
*/
