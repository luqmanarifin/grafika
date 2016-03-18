#ifndef __Mata_H_
#define __Mata_H_

#include "../../lib/polygon.h" 

struct Matakiri : public Polygon {
  Matakiri() {
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 320), Point<double>(310, 320), Point<double>(290, 325)));
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 375), Point<double>(340, 375), Point<double>(370, 365)));
    addCurve(curve(Point<double>(370, 365), Point<double>(380, 355), Point<double>(380, 345), Point<double>(380, 335)));
    setColor(255,255,255,0);
    move(0,-10);
  }
};
struct Matakanan : public Polygon {
  Matakanan() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 320), Point<double>(360, 320), Point<double>(380, 325)));
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 375), Point<double>(330, 375), Point<double>(300, 365)));
    addCurve(curve(Point<double>(300, 365), Point<double>(290, 355), Point<double>(290, 345), Point<double>(290, 335)));
    setColor(255,255,255,0);
    move(0,-10);
  }
};
struct Mata : public Polygon {
  Mata() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 310), Point<double>(360, 310), Point<double>(380, 335)));
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 350), Point<double>(310, 350), Point<double>(290, 335)));
    setColor(255,255,255,0);
  }
};
struct MataMerem : public Polygon {
  MataMerem() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 330), Point<double>(360, 330), Point<double>(380, 335)));
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 330), Point<double>(310, 330), Point<double>(290, 335)));
    setColor(0,0,0,0);
  }
};
struct MataSedih : public Polygon {
  MataSedih() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 310), Point<double>(360, 310), Point<double>(380, 335)));
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 350), Point<double>(310, 350), Point<double>(290, 335)));
    setColor(255,255,255,0);
  }
};

struct MataSipit : public Polygon {
  MataSipit() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 315), Point<double>(360, 315), Point<double>(380, 335)));
    addCurve(curve(Point<double>(380, 335), Point<double>(360, 355), Point<double>(310, 355), Point<double>(290, 335)));
    setColor(255,255,255,0);
  }
};

struct Tangisan : public Polygon {
  Tangisan() {
    addCurve(curve(Point<double>(290, 335), Point<double>(310, 365), Point<double>(360, 365), Point<double>(380, 335)));
    addPoint(Point<double>(377, 335));
    addCurve(curve(Point<double>(375, 335), Point<double>(360, 355), Point<double>(310, 355), Point<double>(295, 335)));
    addPoint(Point<double>(293, 335));
    setColor(176,224,230,0);
  }
};

struct Alis : public Polygon {
  Alis() {
    addCurve(curve(Point<double>(290, 290), Point<double>(310, 280), Point<double>(360, 280), Point<double>(380, 290)));
    addPoint(Point<double>(377, 290));
    addCurve(curve(Point<double>(375, 290), Point<double>(360, 285), Point<double>(310, 285), Point<double>(295, 290)));
    addPoint(Point<double>(293, 290));
    setColor(139,0,0,0);
  }
};

#endif
