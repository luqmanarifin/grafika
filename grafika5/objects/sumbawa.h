#ifndef __SUMBAWA_H_
#define __SUMBAWA_H_

#include "../lib/polygon.h" 

struct Sumbawa : public Polygon {
  Sumbawa() {
    addPoint(Point(343,281));
    addPoint(Point(349,279));
    addPoint(Point(354,280));
    addPoint(Point(358,283));
    addPoint(Point(362,284));
    addPoint(Point(355,277));
    addPoint(Point(363,274));
    addPoint(Point(366,280));
    addPoint(Point(369,277));
    addPoint(Point(377,278));
    addPoint(Point(380,285));
    addPoint(Point(369,287));
    addPoint(Point(359,288));
    addPoint(Point(350,292));
    addPoint(Point(343,289));
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
