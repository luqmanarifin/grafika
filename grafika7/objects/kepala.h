#ifndef __Kepala_H_
#define __Kepala_H_

#include <polygon.h> 

struct Kepala : public Polygon {
  Kepala() {
    //ndas
    //bawah
    addCurve(curve(Point<double>(100, 500), Point<double>(210, 630), Point<double>(310, 630), Point<double>(420, 500)));
    addPoint(Point<double>(420, 500));
    addPoint(Point<double>(420, 400));
    //kiri
    addCurve(curve(Point<double>(420, 400), Point<double>(430, 390), Point<double>(420, 360), Point<double>(410, 350)));
    //atas
    addCurve(curve(Point<double>(410, 350), Point<double>(360, 70), Point<double>(160, 70), Point<double>(110, 350)));
    //kanan
    addCurve(curve(Point<double>(110, 350), Point<double>(90, 360), Point<double>(110, 390), Point<double>(100, 400)));
    addPoint(Point<double>(100, 400));
    addPoint(Point<double>(100, 500));
    setColor(255,235,205,0);
  }
};

struct HidungKanan : public Polygon {
  HidungKanan() {
    addCurve(curve(Point<double>(280, 450), Point<double>(287, 440), Point<double>(294, 440), Point<double>(300, 450)));
    addCurve(curve(Point<double>(300, 450), Point<double>(263, 340), Point<double>(287, 330), Point<double>(290, 300)));
    move(-5,0);//move(-20,0);
    //rotateCenter(-5);
    setColor(255,227,190,0);
  }
};
struct Hidung : public Polygon {
  Hidung() {
    addCurve(curve(Point<double>(250, 450), Point<double>(260, 465), Point<double>(270, 465), Point<double>(280, 450)));
    addCurve(curve(Point<double>(280, 450), Point<double>(270, 457), Point<double>(260, 457), Point<double>(250, 450)));
    setColor(255,227,190,0);
    move(-5,0);
  }
};

struct HidungKiri : public Polygon {
  HidungKiri() {
    addCurve(curve(Point<double>(250, 450), Point<double>(245, 440), Point<double>(240, 440), Point<double>(235, 450)));
    addCurve(curve(Point<double>(235, 450), Point<double>(267, 340), Point<double>(243, 330), Point<double>(240, 300)));
    //move(-20,0);
    //rotateCenter(5);
    setColor(255,227,190,0);
    move(-5,0);
  }
};
struct Hidung1 : public Polygon {
  Hidung1() {
    //hidung
//left
  addPoint(Point<double>(265,370));
  addCurve(curve(Point<double>(257.5, 400), Point<double>(256, 410), Point<double>(255, 411), Point<double>(250, 415)));
  addCurve(curve(Point<double>(250, 415), Point<double>(248, 420), Point<double>(247, 421), Point<double>(245, 425)));
  addCurve(curve(Point<double>(245, 425), Point<double>(247, 430), Point<double>(248, 431), Point<double>(250, 435)));
  addCurve(curve(Point<double>(250, 435), Point<double>(257, 437), Point<double>(258, 438), Point<double>(265, 440)));
//bottom
  addPoint(Point<double>(265,440));
  addPoint(Point<double>(275,440));
//right
  addCurve(curve(Point<double>(275, 440), Point<double>(282,437), Point<double>(283, 438), Point<double>(290, 435)));
  addCurve(curve(Point<double>(290, 435), Point<double>(294, 431), Point<double>(293, 430), Point<double>(295, 425)));
  addCurve(curve(Point<double>(295, 425), Point<double>(293,421), Point<double>(292, 420), Point<double>(290, 415)));
  addCurve(curve(Point<double>(290, 415), Point<double>(285, 411), Point<double>(284, 410), Point<double>(282.5,400)));
  addPoint(Point<double>(275,370));
    setColor(255,227,190,0);
  }

};
#endif
