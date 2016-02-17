#ifndef __JAWA_H_
#define __JAWA_H_

#include "../lib/polygon.h" 

struct Jawa : public Polygon {
  Jawa() {
    //Kiri
    addPoint(Point(80, 0));
    addPoint(Point(80, 30));
    addPoint(Point(75, 30));
    addPoint(Point(75, 60));
    addPoint(Point(120, 60));
    addPoint(Point(120, 90));
    addPoint(Point(175, 90));
    addPoint(Point(175, 120));
    //Lekukan Bawah
    //lekukan bawah
    addPoint(Point(315, 120));
    addPoint(Point(315, 150));
    //Kanan
    addPoint(Point(525, 150));
    addPoint(Point(525, 120));
    addPoint(Point(515, 120));
    addPoint(Point(515, 90));
    addPoint(Point(430, 90));
    addPoint(Point(430, 60));
    addPoint(Point(420, 60));
    addPoint(Point(420, 30));
    //lekukan Atas
    addPoint(Point(325, 30));
    addPoint(Point(325, 60));
    addPoint(Point(255, 60));
    addPoint(Point(255, 30));
    //lekukan Atas
    addPoint(Point(200, 30));
    addPoint(Point(200, 0));
  }
};

#endif
