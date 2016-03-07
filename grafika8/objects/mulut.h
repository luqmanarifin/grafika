#ifndef __Mulut_H_
#define __Mulut_H_

#include "../../lib/polygon.h" 

struct Mulut : public Polygon {
  Mulut() {
    //baw
    addCurve(curve(Point<double>(210, 500), Point<double>(240, 520), Point<double>(300, 520), Point<double>(330, 500)));
    addCurve(curve(Point<double>(330, 500), Point<double>(315, 497), Point<double>(300, 493), Point<double>(285, 490)));
    addCurve(curve(Point<double>(255, 490), Point<double>(240, 493), Point<double>(225, 497), Point<double>(210, 500)));
    setColor(255,222,173,0);
  }
};

struct Bibir : public Polygon {
  Bibir() {
    //baw
    addCurve(curve(Point<double>(200, 500), Point<double>(240, 530), Point<double>(300, 530), Point<double>(340, 500)));
    addCurve(curve(Point<double>(340, 500), Point<double>(315, 497), Point<double>(300, 493), Point<double>(285, 490)));
    addCurve(curve(Point<double>(255, 490), Point<double>(240, 493), Point<double>(225, 497), Point<double>(200, 500)));
    setColor(255,222,173,0);
  }
};

struct Bibir2 : public Polygon {
  Bibir2() {
    //baw
    addCurve(curve(Point<double>(210, 510), Point<double>(240, 520), Point<double>(300, 520), Point<double>(330, 510)));
    addCurve(curve(Point<double>(330, 510), Point<double>(315, 497), Point<double>(300, 493), Point<double>(285, 495)));
    addCurve(curve(Point<double>(255, 495), Point<double>(240, 493), Point<double>(225, 497), Point<double>(210, 510)));
    setColor(255,222,173,0);
  }
};

struct MulutSenyum : public Polygon {
  MulutSenyum() {
    //baw
    addCurve(curve(Point<double>(210, 500), Point<double>(240, 520), Point<double>(300, 520), Point<double>(330, 500)));
    //addCurve(curve(Point<double>(330, 500), Point<double>(300, 515), Point<double>(240, 515), Point<double>(210, 500)));
    setColor(255,255,255,0);
  }
};

struct MulutTertawa : public Polygon {
  MulutTertawa() {
    //baw
    addCurve(curve(Point<double>(210, 500), Point<double>(240, 520), Point<double>(300, 520), Point<double>(330, 500)));
    //addCurve(curve(Point<double>(330, 500), Point<double>(300, 515), Point<double>(240, 515), Point<double>(210, 500)));
    setColor(160,82,45,0);
  }
};

struct GigiTertawa : public Polygon {
  GigiTertawa() {
    //baw
    addCurve(curve(Point<double>(210, 500), Point<double>(220, 508), Point<double>(320, 508), Point<double>(330, 500)));
    //addCurve(curve(Point<double>(330, 500), Point<double>(300, 515), Point<double>(240, 515), Point<double>(210, 500)));
    setColor(255,255,255,0);
  }
};


struct MulutSedih : public Polygon {
  MulutSedih() {
    //baw
    addCurve(curve(Point<double>(230, 510), Point<double>(240, 500), Point<double>(300, 500), Point<double>(310, 510)));
    //addCurve(curve(Point<double>(330, 500), Point<double>(300, 515), Point<double>(240, 515), Point<double>(210, 500)));
    setColor(255,255,255,0);
  }
};



#endif
