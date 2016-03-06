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
    addCurve(Point<double>(280, 450), Point<double>(287, 440), Point<double>(294, 440), Point<double>(300, 450));
    addCurve(Point<double>(300, 450), Point<double>(263, 340), Point<double>(287, 330), Point<double>(290, 300));
    move(-5,0);
    //rotateCenter(-5);
    setColor(255,227,190,0);
  }
};
struct Hidung : public Polygon {
  Hidung() {
    addCurve(Point<double>(250, 450), Point<double>(260, 465), Point<double>(270, 465), Point<double>(280, 450));
    addCurve(Point<double>(280, 450), Point<double>(270, 457), Point<double>(260, 457), Point<double>(250, 450));
    setColor(255,227,190,0);
    move(-5,0);
  }
};

struct HidungKiri : public Polygon {
  HidungKiri() {
    addCurve(Point<double>(250, 450), Point<double>(245, 440), Point<double>(240, 440), Point<double>(235, 450));
    addCurve(Point<double>(235, 450), Point<double>(267, 340), Point<double>(243, 330), Point<double>(240, 300));
    //move(-20,0);
    //rotateCenter(5);
    setColor(255,227,190,0);
    move(-5,0);
  }
};
#endif
