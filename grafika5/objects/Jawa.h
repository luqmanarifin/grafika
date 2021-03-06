#ifndef __JAWA_H_
#define __JAWA_H_

#include <polygon.h> 

struct Jawa : public Polygon {
  Jawa() {
    //Kiri
    addPoint(Point<double>(85, 0));
    addPoint(Point<double>(80, 30));
    //addPoint(Point<double>(75, 30));
    addPoint(Point<double>(75, 60));
    addPoint(Point<double>(120, 60));
    addPoint(Point<double>(125, 90));
    addPoint(Point<double>(175, 90));
    addPoint(Point<double>(180, 120));
    //Lekukan Bawah
    //lekukan bawah
    addPoint(Point<double>(315, 120));
    addPoint(Point<double>(310, 150));
    //Kanan
    addPoint(Point<double>(525, 150));
    //addPoint(Point<double>(525, 120));
    addPoint(Point<double>(515, 120));
    addPoint(Point<double>(510, 90));
    addPoint(Point<double>(430, 90));
    //addPoint(Point<double>(430, 60));
    addPoint(Point<double>(420, 60));
    addPoint(Point<double>(410, 30));
    //lekukan Atas
    addPoint(Point<double>(335, 30));
    addPoint(Point<double>(325, 60));
    addPoint(Point<double>(255, 60));
    addPoint(Point<double>(245, 30));
    //lekukan Atas
    addPoint(Point<double>(215, 30));
    addPoint(Point<double>(200, 0));
  }
};

#endif
