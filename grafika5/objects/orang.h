#ifndef __ORANG_H_
#define __ORANG_H_

#include "../lib/polygon.h" 

struct Orang : public Polygon {
  Orang() {
    addPoint(Point(412,300));
    addPoint(Point(420,300));
    addPoint(Point(420,308));
    addPoint(Point(428,308));
    addPoint(Point(428,316));
    addPoint(Point(437,316));
    addPoint(Point(437,358));
    addPoint(Point(429,358));
    addPoint(Point(429,366));
    addPoint(Point(421,366));
    addPoint(Point(421,375));
    addPoint(Point(454,375));
    addPoint(Point(454,385));
    addPoint(Point(462,385));
    addPoint(Point(462,467));
    addPoint(Point(464,467));
    addPoint(Point(464,490));
    addPoint(Point(443,490));
    addPoint(Point(443,467));
    addPoint(Point(445,467));
    addPoint(Point(445,400));
    addPoint(Point(437,400));
    addPoint(Point(437,590));
    addPoint(Point(445,590));
    addPoint(Point(445,600));
    addPoint(Point(410,600));
    addPoint(Point(410,520));
    addPoint(Point(400,510));
    addPoint(Point(390,520));
    addPoint(Point(390,600));
    addPoint(Point(355,600));
    addPoint(Point(355,590));
    addPoint(Point(363,590));
    addPoint(Point(363,400));
    addPoint(Point(355,400));
    addPoint(Point(355,467));
    addPoint(Point(357,467));
    addPoint(Point(357,490));
    addPoint(Point(336,490));
    addPoint(Point(336,467));
    addPoint(Point(338,467));
    addPoint(Point(338,385));
    addPoint(Point(346,385));
    addPoint(Point(346,375));
    addPoint(Point(392,375));
    addPoint(Point(374,375));
    addPoint(Point(374,366));
    addPoint(Point(366,366));
    addPoint(Point(366,358));
    addPoint(Point(358,358));
    addPoint(Point(358,316));
    addPoint(Point(366,316));
    addPoint(Point(366,308));
    addPoint(Point(374,308));
    addPoint(Point(374,300));
  }
};

#endif
