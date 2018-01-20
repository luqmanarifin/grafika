#ifndef __Rambut_H_
#define __Rambut_H_

#include <polygon.h> 

struct Rambut : public Polygon {
  Rambut() {
    addCurve(curve(Point<double>(310, 30), Point<double>(420, 100), Point<double>(460, 170), Point<double>(470, 320)));
    //last point 
    //addPoint(Point<double>(470, 320));
    addPoint(Point<double>(470, 400));
    addPoint(Point<double>(459, 400));
    //addCurve(curve(Point<double>(460, 480), Point<double>(470, 490), Point<double>(480, 500), Point<double>(490, 520)));
    //kiri
    addPoint(Point<double>(458, 500));
    //addPoint(Point<double>(490, 520));
    addPoint(Point<double>(450, 500));
    //addPoint(Point<double>(450, 550));
    addCurve(curve(Point<double>(450, 550), Point<double>(460, 570), Point<double>(470, 580), Point<double>(480, 600)));
    addCurve(curve(Point<double>(481, 600), Point<double>(460, 626), Point<double>(440, 650), Point<double>(470, 660)));
    addCurve(curve(Point<double>(471, 660), Point<double>(440, 650), Point<double>(420, 640), Point<double>(380, 620)));
    //addPoint(Point<double>(380, 620));
    addCurve(curve(Point<double>(380, 570), Point<double>(400, 540), Point<double>(415, 520), Point<double>(420, 500)));
    //addPoint(Point<double>(420, 500));
    //addPoint(Point<double>(420, 380));
    //addPoint(Point<double>(390, 400));
    addCurve(curve(Point<double>(390, 400), Point<double>(380, 250), Point<double>(360, 180), Point<double>(320, 160)));
    addCurve(curve(Point<double>(320, 160), Point<double>(270, 200), Point<double>(230, 240), Point<double>(190, 320)));
    addPoint(Point<double>(191, 320));
    addCurve(curve(Point<double>(191, 320), Point<double>(190, 270), Point<double>(140, 280), Point<double>(200, 250)));
    addPoint(Point<double>(201, 250));
    addCurve(curve(Point<double>(201, 250), Point<double>(160, 270), Point<double>(140, 280), Point<double>(100, 370)));
    addCurve(curve(Point<double>(100, 460), Point<double>(110, 550), Point<double>(120, 670), Point<double>(180, 730)));
    addCurve(curve(Point<double>(180, 730), Point<double>(10, 690), Point<double>(50, 660), Point<double>(10, 600)));
    addCurve(curve(Point<double>(10, 600), Point<double>(30, 590), Point<double>(40, 580), Point<double>(20, 560)));
    addPoint(Point<double>(20, 559));
    addCurve(curve(Point<double>(20, 559), Point<double>(40, 500), Point<double>(30, 440), Point<double>(10, 350)));
    addPoint(Point<double>(10, 349));
    addCurve(curve(Point<double>(10, 349), Point<double>(40, 170), Point<double>(100, 100), Point<double>(250, 30)));
    addPoint(Point<double>(250, 30));
    //addPoint(Point<double>(310, 30));
    //last point
    //setColor(217,62,20,0);
    
    setColor(139,0,0,0);
    //setColor(255,246,153,0);
  }
};

#endif
