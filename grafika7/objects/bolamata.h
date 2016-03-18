#ifndef __Bolamata_H_
#define __Bolamata_H_

#include "../../lib/polygon.h" 

/*
struct Bolamata : public Polygon {
  Bolamata() {
     addCurve(curve(Point<double>(310, 335), Point<double>(300, 325), Point<double>(330, 295), Point<double>(340, 305)));
     addCurve(curve(Point<double>(340, 305), Point<double>(350, 295), Point<double>(380, 325), Point<double>(370, 335)));
     addCurve(curve(Point<double>(370, 335), Point<double>(380, 345), Point<double>(350, 375), Point<double>(340, 365)));
     addCurve(curve(Point<double>(340, 365), Point<double>(330, 375), Point<double>(300, 345), Point<double>(310, 335)));
     setColor(87,59,12,0);
  }
  
};*/
struct Bolamata : public Polygon {
  Bolamata() {
     addCurve(curve(Point<double>(310, 335), Point<double>(305, 330), Point<double>(320, 315), Point<double>(325, 320)));
     addCurve(curve(Point<double>(325, 320), Point<double>(330, 315), Point<double>(345, 330), Point<double>(340, 335)));
     addCurve(curve(Point<double>(340, 335), Point<double>(345, 345), Point<double>(330, 355), Point<double>(325, 350)));
     addCurve(curve(Point<double>(325, 350), Point<double>(320, 355), Point<double>(305, 345), Point<double>(310, 335)));
     //setColor(87,59,12,0);
     setColor(198,226,225,0);
     move(10,0);
  }
  
};
struct Bolamata2 : public Polygon {
  Bolamata2() {
     addCurve(curve(Point<double>(310, 335), Point<double>(330, 305), Point<double>(340, 305), Point<double>(360, 335)));
     addCurve(curve(Point<double>(360, 335), Point<double>(340, 365), Point<double>(330, 365), Point<double>(310, 335)));
     setColor(87,59,12,0);
  }
  
};

#endif
