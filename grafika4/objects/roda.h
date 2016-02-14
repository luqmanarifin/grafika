#ifndef __RODA_H_
#define __RODA_H_

#include "../lib/polygon.h" 

struct Roda : public Polygon {
  Roda() {
    addPoint(Point(325,90));
    addPoint(Point(475,90));
    addPoint(Point(475,120));
    addPoint(Point(535,120));
    addPoint(Point(535,150));
    addPoint(Point(565,150));
    addPoint(Point(565,180));
    addPoint(Point(595,180));
    addPoint(Point(595,210));
    addPoint(Point(625,210));
    addPoint(Point(625,270));
    addPoint(Point(655,270));
    addPoint(Point(655,420));
    addPoint(Point(625,420));
    addPoint(Point(625,480));
    addPoint(Point(595,480));
    addPoint(Point(595,510));
    addPoint(Point(565,510));
    addPoint(Point(565,540));
    addPoint(Point(535,540));
    addPoint(Point(535,570));
    addPoint(Point(475,570));
    addPoint(Point(475,600));
    addPoint(Point(325,600));
    addPoint(Point(325,570));
    addPoint(Point(265,570));
    addPoint(Point(265,540));
    addPoint(Point(235,540));
    addPoint(Point(235,510));
    addPoint(Point(205,510));
    addPoint(Point(205,480));
    addPoint(Point(175,480));
    addPoint(Point(175,420));
    addPoint(Point(145,420));
    addPoint(Point(145,270));
    addPoint(Point(175,270));
    addPoint(Point(175,210));
    addPoint(Point(205,210));
    addPoint(Point(205,180));
    addPoint(Point(235,180));
    addPoint(Point(235,150));
    addPoint(Point(265,150));
    addPoint(Point(265,120));
    addPoint(Point(325,120));
    addPoint(Point(325,390));
    addPoint(Point(355,390));
    addPoint(Point(355,420));
    addPoint(Point(445,420));
    addPoint(Point(445,390));
    addPoint(Point(475,390));
    addPoint(Point(475,300));
    addPoint(Point(445,300));
    addPoint(Point(445,270));
    addPoint(Point(355,270));
    addPoint(Point(355,300));
    addPoint(Point(325,300));
  }
};

#endif
