#ifndef __PESAWAT_H_
#define __PESAWAT_H_

#include "../lib/polygon.h" 

struct Pesawat : public Polygon {
  Pesawat() {
    addPoint(Point(450,200));
    addPoint(Point(460,200));
    addPoint(Point(460,210));
    addPoint(Point(470,210));
    addPoint(Point(470,220));
    addPoint(Point(480,220));
    addPoint(Point(480,230));
    addPoint(Point(490,230));
    addPoint(Point(490,240));
    addPoint(Point(500,240));
    addPoint(Point(500,290));
    addPoint(Point(750,290));
    addPoint(Point(750,300));
    addPoint(Point(700,300));
    addPoint(Point(700,310));
    addPoint(Point(500,310));
    addPoint(Point(500,360));
    addPoint(Point(490,360));
    addPoint(Point(490,370));
    addPoint(Point(480,370));
    addPoint(Point(480,380));
    addPoint(Point(470,380));
    addPoint(Point(470,390));
    addPoint(Point(460,390));
    addPoint(Point(460,400));
    addPoint(Point(340,400));
    addPoint(Point(340,390));
    addPoint(Point(330,390));
    addPoint(Point(330,380));
    addPoint(Point(320,380));
    addPoint(Point(320,370));
    addPoint(Point(310,370));
    addPoint(Point(310,360));
    addPoint(Point(300,360));
    addPoint(Point(300,310));
    addPoint(Point(100,310));
    addPoint(Point(100,300));
    addPoint(Point(50,300));
    addPoint(Point(50,290));
    addPoint(Point(300,290));
    addPoint(Point(300,240));
    addPoint(Point(310,240));
    addPoint(Point(310,230));
    addPoint(Point(320,230));
    addPoint(Point(320,220));
    addPoint(Point(330,220));
    addPoint(Point(330,210));
    addPoint(Point(340,210));
    addPoint(Point(340,200));
    addPoint(Point(390,200));
    addPoint(Point(390,140));
    addPoint(Point(395,140));
    addPoint(Point(395,100));
    addPoint(Point(405,100));
    addPoint(Point(405,140));
    addPoint(Point(410,140));
    addPoint(Point(410,200));
  }
};

#endif
