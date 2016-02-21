#ifndef __KALIMANTAN_H_
#define __KALIMANTAN_H_

#include "../lib/polygon.h" 

struct Kalimantan : public Polygon {
  Kalimantan() {
    //Kiri
    addPoint(Point(480, 0));
    addPoint(Point(480, 30));
    addPoint(Point(470, 30));
    addPoint(Point(470, 60));
    addPoint(Point(445, 60));
    addPoint(Point(445, 90));
    addPoint(Point(440, 90));
    addPoint(Point(440, 120));
    addPoint(Point(415, 120));
    addPoint(Point(415, 150));    
    //Lekukan Atas
    addPoint(Point(405, 150));
    addPoint(Point(405, 180));
    addPoint(Point(325, 180));
    addPoint(Point(325, 150));
    addPoint(Point(265, 150));
    addPoint(Point(265, 180));
    addPoint(Point(200, 180));
    addPoint(Point(200, 210));
    addPoint(Point(160, 210));
    addPoint(Point(160, 180));
    addPoint(Point(135, 180));
    addPoint(Point(135, 150));
    addPoint(Point(75, 150));
    addPoint(Point(75, 180));
    //Lekukan Atas
    addPoint(Point(85, 180));
    addPoint(Point(85, 210));
    addPoint(Point(110, 210));
    addPoint(Point(110, 240));
    addPoint(Point(125, 240));
    addPoint(Point(125, 270));
    addPoint(Point(150, 270));
    addPoint(Point(150, 300));
    addPoint(Point(160, 300));
    addPoint(Point(160, 330));
    addPoint(Point(185, 330));
    addPoint(Point(185, 360));
    addPoint(Point(160, 360));
    addPoint(Point(160, 390));
    //Lekukan bawah
    addPoint(Point(245, 390));
    addPoint(Point(245, 420));
    addPoint(Point(305, 420));
    addPoint(Point(305, 390));
    addPoint(Point(385, 390));
    addPoint(Point(385, 420));
    //lekukan bawah
    addPoint(Point(430, 420));
    addPoint(Point(430, 450));
    //Kanan
    addPoint(Point(490, 450));
    addPoint(Point(490, 420));
    addPoint(Point(515, 420));
    addPoint(Point(515, 390));
    addPoint(Point(545, 390));
    addPoint(Point(545, 360));
    addPoint(Point(535, 360));
    addPoint(Point(535, 330));
    addPoint(Point(540, 330));
    addPoint(Point(540, 300));
    addPoint(Point(565, 300));
    addPoint(Point(565, 270));
    addPoint(Point(610, 270));
    addPoint(Point(610, 240));
    addPoint(Point(600, 240));
    addPoint(Point(600, 210));
    addPoint(Point(610, 210));
    addPoint(Point(610, 180));
    addPoint(Point(665, 180));
    addPoint(Point(665, 150));
    addPoint(Point(640, 150));
    addPoint(Point(640, 120));
    addPoint(Point(630, 120));
    addPoint(Point(630, 90));
    addPoint(Point(605, 90));
    addPoint(Point(605, 60));
    addPoint(Point(595, 60));
    addPoint(Point(595, 30));
    addPoint(Point(600, 30));
    addPoint(Point(600, 0));
  }
};

#endif
