#ifndef __RUMAHGAZANDI_H_
#define __RUMAHGAZANDI_H_

#include "../../lib/polygon.h" 

struct RumahGazandi : public Polygon {
  RumahGazandi() {
    //Kiri
    addPoint(Point<double>(70, 0));
    addPoint(Point<double>(70, 30));
    addPoint(Point<double>(30, 30));
    addPoint(Point<double>(30, 60));
    addPoint(Point<double>(70, 60));
    addPoint(Point<double>(70, 90));
    addPoint(Point<double>(185, 90));
    addPoint(Point<double>(185, 120));
    addPoint(Point<double>(70, 120));
    addPoint(Point<double>(70, 150));
    addPoint(Point<double>(125, 150));
    addPoint(Point<double>(125, 180));
    addPoint(Point<double>(135, 180));
    addPoint(Point<double>(135, 210));
    //Lekukan bawah
    addPoint(Point<double>(165, 210));
    addPoint(Point<double>(165, 180));
    addPoint(Point<double>(205, 180));
    addPoint(Point<double>(205, 210));
    //Lekukan bawah
    addPoint(Point<double>(255, 210));
    addPoint(Point<double>(255, 240));
    addPoint(Point<double>(355, 240));
    addPoint(Point<double>(355, 270));
    addPoint(Point<double>(410, 270));
    addPoint(Point<double>(410, 300));
    addPoint(Point<double>(420, 300));
    addPoint(Point<double>(420, 330));
    addPoint(Point<double>(445, 330));
    addPoint(Point<double>(445, 360));
    addPoint(Point<double>(490, 360));
    addPoint(Point<double>(490, 390));
    addPoint(Point<double>(515, 390));
    addPoint(Point<double>(515, 420));
    addPoint(Point<double>(555, 420));
    addPoint(Point<double>(555, 450));
    addPoint(Point<double>(580, 450));
    addPoint(Point<double>(580, 480));
    //Kanan
    addPoint(Point<double>(600, 480));
    addPoint(Point<double>(600, 150));
    addPoint(Point<double>(600, 120));
    addPoint(Point<double>(530, 120));
    addPoint(Point<double>(530, 90));
    addPoint(Point<double>(445, 90));
    addPoint(Point<double>(445, 60));
    //Lekukan Atas
    addPoint(Point<double>(385, 60));
    addPoint(Point<double>(385, 90));
    addPoint(Point<double>(310, 90));
    addPoint(Point<double>(310, 120));
    addPoint(Point<double>(285, 120));
    addPoint(Point<double>(285, 150));
    addPoint(Point<double>(250, 150));
    addPoint(Point<double>(250, 120));
    addPoint(Point<double>(215, 120));
    addPoint(Point<double>(215, 90));
    addPoint(Point<double>(190, 90));
    addPoint(Point<double>(190, 60));
    //lekukan Atas
    addPoint(Point<double>(210, 60));
    addPoint(Point<double>(210, 30));
    addPoint(Point<double>(160, 30));
    addPoint(Point<double>(160, 0));
  }
};

#endif
