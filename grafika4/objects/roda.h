#ifndef __RODA_H_
#define __RODA_H_

#include <polygon.h> 

struct Roda : public Polygon {
  Roda() {
    addPoint(Point<double>(325,90));
    addPoint(Point<double>(475,90));
    addPoint(Point<double>(475,120));
    addPoint(Point<double>(535,120));
    addPoint(Point<double>(535,150));
    addPoint(Point<double>(565,150));
    addPoint(Point<double>(565,180));
    addPoint(Point<double>(595,180));
    addPoint(Point<double>(595,210));
    addPoint(Point<double>(625,210));
    addPoint(Point<double>(625,270));
    addPoint(Point<double>(655,270));
    addPoint(Point<double>(655,420));
    addPoint(Point<double>(625,420));
    addPoint(Point<double>(625,480));
    addPoint(Point<double>(595,480));
    addPoint(Point<double>(595,510));
    addPoint(Point<double>(565,510));
    addPoint(Point<double>(565,540));
    addPoint(Point<double>(535,540));
    addPoint(Point<double>(535,570));
    addPoint(Point<double>(475,570));
    addPoint(Point<double>(475,600));
    addPoint(Point<double>(325,600));
    addPoint(Point<double>(325,570));
    addPoint(Point<double>(265,570));
    addPoint(Point<double>(265,540));
    addPoint(Point<double>(235,540));
    addPoint(Point<double>(235,510));
    addPoint(Point<double>(205,510));
    addPoint(Point<double>(205,480));
    addPoint(Point<double>(175,480));
    addPoint(Point<double>(175,420));
    addPoint(Point<double>(145,420));
    addPoint(Point<double>(145,270));
    addPoint(Point<double>(175,270));
    addPoint(Point<double>(175,210));
    addPoint(Point<double>(205,210));
    addPoint(Point<double>(205,180));
    addPoint(Point<double>(235,180));
    addPoint(Point<double>(235,150));
    addPoint(Point<double>(265,150));
    addPoint(Point<double>(265,120));
    addPoint(Point<double>(325,120));
    addPoint(Point<double>(325,390));
    addPoint(Point<double>(355,390));
    addPoint(Point<double>(355,420));
    addPoint(Point<double>(445,420));
    addPoint(Point<double>(445,390));
    addPoint(Point<double>(475,390));
    addPoint(Point<double>(475,300));
    addPoint(Point<double>(445,300));
    addPoint(Point<double>(445,270));
    addPoint(Point<double>(355,270));
    addPoint(Point<double>(355,300));
    addPoint(Point<double>(325,300));
  }
};

#endif
