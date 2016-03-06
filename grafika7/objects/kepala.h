#ifndef __Kepala_H_
#define __Kepala_H_

#include "../../lib/polygon.h" 

struct Kepala : public Polygon {
  Kepala() {
    //ndas
    //bawah
    addCurve(Point<double>(100, 500), Point<double>(210, 630), Point<double>(310, 630), Point<double>(420, 500));
    addPoint(Point<double>(420, 500));
    addPoint(Point<double>(420, 400));
    //kiri
    addCurve(Point<double>(420, 400), Point<double>(430, 390), Point<double>(420, 360), Point<double>(410, 350));
    //atas
    addCurve(Point<double>(410, 350), Point<double>(360, 70), Point<double>(160, 70), Point<double>(110, 350));
    //kanan
    addCurve(Point<double>(110, 350), Point<double>(90, 360), Point<double>(110, 390), Point<double>(100, 400));
    addPoint(Point<double>(100, 400));
    addPoint(Point<double>(100, 500));
    setColor(255,235,205,0);
  }
};

struct HidungKanan : public Polygon {
  HidungKanan() {
    addCurve(Point<double>(280, 450), Point<double>(285, 440), Point<double>(290, 440), Point<double>(295, 450));
    addCurve(Point<double>(295, 450), Point<double>(285, 400), Point<double>(283, 350), Point<double>(280, 330));
    move(-20,0);
    setColor(255,232,180,0);
  }
};
struct Hidung : public Polygon {
  Hidung() {
    addCurve(Point<double>(250, 450), Point<double>(260, 460), Point<double>(270, 460), Point<double>(280, 450));
    addCurve(Point<double>(280, 450), Point<double>(270, 457), Point<double>(260, 457), Point<double>(250, 450));
    setColor(255,227,177,0);
  }
};

struct HidungKiri : public Polygon {
  HidungKiri() {
    addCurve(Point<double>(250, 450), Point<double>(247, 440), Point<double>(243, 440), Point<double>(240, 450));
    addCurve(Point<double>(240, 450), Point<double>(247, 400), Point<double>(257, 350), Point<double>(250, 330));
    //move(-20,0);
    setColor(255,222,173,0);
  }
};
#endif
