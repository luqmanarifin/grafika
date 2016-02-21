#ifndef __SULAWESI_H_
#define __SULAWESI_H_

#include "../lib/polygon.h" 

struct Sulawesi : public Polygon {
  Sulawesi() {
    //Kiri
    addPoint(Point(420, 0));
    addPoint(Point(420, 30));
    //Lekukan Atas
    addPoint(Point(410, 30));
    addPoint(Point(410, 60));
    addPoint(Point(290, 60));
    addPoint(Point(290, 30));
    //lekukan Atas
    addPoint(Point(215, 30));
    addPoint(Point(215, 60));
    addPoint(Point(190, 60));
    addPoint(Point(190, 90));
    addPoint(Point(180, 90));
    addPoint(Point(180, 120));
    addPoint(Point(155, 120));
    addPoint(Point(155, 150));
    addPoint(Point(145, 150));
    addPoint(Point(145, 180));
    addPoint(Point(160, 180));
    addPoint(Point(160, 210));
    addPoint(Point(145, 210));
    addPoint(Point(145, 240));
    addPoint(Point(120, 240));
    addPoint(Point(120, 270));
    addPoint(Point(110, 270));
    addPoint(Point(110, 300));
    addPoint(Point(155, 300));
    addPoint(Point(155, 330));
    addPoint(Point(140, 330));
    addPoint(Point(140, 360));
    addPoint(Point(155, 360));
    addPoint(Point(155, 390));
    addPoint(Point(140, 390));
    addPoint(Point(140, 420));
    //Kanan
    //Lekukan Bawah
    addPoint(Point(200, 420));
    addPoint(Point(200, 390));
    addPoint(Point(215, 390));
    addPoint(Point(215, 360));
    addPoint(Point(200, 360));
    addPoint(Point(200, 330));
    addPoint(Point(215, 330));
    addPoint(Point(215, 300));
    addPoint(Point(200, 300));
    addPoint(Point(200, 270));
    addPoint(Point(235, 270));
    addPoint(Point(235, 300));
    addPoint(Point(245, 300));
    addPoint(Point(245, 330));
    addPoint(Point(270, 330));
    addPoint(Point(270, 360));
    addPoint(Point(300, 360));
    addPoint(Point(300, 330));
    addPoint(Point(335, 330));
    addPoint(Point(335, 360));
    //lekukan Bawah
    addPoint(Point(365, 360));
    addPoint(Point(365, 330));
    addPoint(Point(340, 330));
    addPoint(Point(340, 300));
    addPoint(Point(330, 300));
    addPoint(Point(330, 270));
    addPoint(Point(295, 270));
    addPoint(Point(295, 240));
    addPoint(Point(290, 240));
    addPoint(Point(290, 210));
    addPoint(Point(305, 210));
    addPoint(Point(305, 180));
    addPoint(Point(390, 180));
    addPoint(Point(390, 150));
    addPoint(Point(215, 150));
    addPoint(Point(215, 120));
    addPoint(Point(210, 120));
    addPoint(Point(210, 90));
    addPoint(Point(415, 90));
    addPoint(Point(415, 60));
    addPoint(Point(440, 60));
    addPoint(Point(440, 30));
    addPoint(Point(450, 30));
    addPoint(Point(450, 0));
  }
};

#endif
