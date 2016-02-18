#ifndef __RUMAHGAZANDI_H_
#define __RUMAHGAZANDI_H_

#include "../lib/polygon.h" 

struct RumahGazandi : public Polygon {
  RumahGazandi() {
    //Kiri
    addPoint(Point(70, 0));
    addPoint(Point(70, 30));
    addPoint(Point(30, 30));
    addPoint(Point(30, 60));
    addPoint(Point(70, 60));
    addPoint(Point(70, 90));
    addPoint(Point(185, 90));
    addPoint(Point(185, 120));
    addPoint(Point(70, 120));
    addPoint(Point(70, 150));
    addPoint(Point(125, 150));
    addPoint(Point(125, 180));
    addPoint(Point(135, 180));
    addPoint(Point(135, 210));
    //Lekukan bawah
    addPoint(Point(165, 210));
    addPoint(Point(165, 180));
    addPoint(Point(205, 180));
    addPoint(Point(205, 210));
    //Lekukan bawah
    addPoint(Point(255, 210));
    addPoint(Point(255, 240));
    addPoint(Point(355, 240));
    addPoint(Point(355, 270));
    addPoint(Point(410, 270));
    addPoint(Point(410, 300));
    addPoint(Point(420, 300));
    addPoint(Point(420, 330));
    addPoint(Point(445, 330));
    addPoint(Point(445, 360));
    addPoint(Point(490, 360));
    addPoint(Point(490, 390));
    addPoint(Point(515, 390));
    addPoint(Point(515, 420));
    addPoint(Point(555, 420));
    addPoint(Point(555, 450));
    addPoint(Point(580, 450));
    addPoint(Point(580, 480));
    //Kanan
    addPoint(Point(600, 480));
    addPoint(Point(600, 150));
    addPoint(Point(600, 120));
    addPoint(Point(530, 120));
    addPoint(Point(530, 90));
    addPoint(Point(445, 90));
    addPoint(Point(445, 60));
    //Lekukan Atas
    addPoint(Point(385, 60));
    addPoint(Point(385, 90));
    addPoint(Point(310, 90));
    addPoint(Point(310, 120));
    addPoint(Point(285, 120));
    addPoint(Point(285, 150));
    addPoint(Point(250, 150));
    addPoint(Point(250, 120));
    addPoint(Point(215, 120));
    addPoint(Point(215, 90));
    addPoint(Point(190, 90));
    addPoint(Point(190, 60));
    //lekukan Atas
    addPoint(Point(210, 60));
    addPoint(Point(210, 30));
    addPoint(Point(160, 30));
    addPoint(Point(160, 0));
  }
};

#endif
