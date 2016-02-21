#ifndef __SULAWESI_H_
#define __SULAWESI_H_

#include "../lib/polygon.h" 

struct Sulawesi : public Polygon {
  Sulawesi() {
    //Kiri
    addPoint(Point<double>(420, 0));
    addPoint(Point<double>(420, 30));
    //Lekukan Atas
    addPoint(Point<double>(410, 30));
    addPoint(Point<double>(410, 60));
    addPoint(Point<double>(290, 60));
    addPoint(Point<double>(290, 30));
    //lekukan Atas
    addPoint(Point<double>(215, 30));
    addPoint(Point<double>(215, 60));
    addPoint(Point<double>(190, 60));
    addPoint(Point<double>(190, 90));
    addPoint(Point<double>(180, 90));
    addPoint(Point<double>(180, 120));
    addPoint(Point<double>(155, 120));
    addPoint(Point<double>(155, 150));
    addPoint(Point<double>(145, 150));
    addPoint(Point<double>(145, 180));
    addPoint(Point<double>(160, 180));
    addPoint(Point<double>(160, 210));
    addPoint(Point<double>(145, 210));
    addPoint(Point<double>(145, 240));
    addPoint(Point<double>(120, 240));
    addPoint(Point<double>(120, 270));
    addPoint(Point<double>(110, 270));
    addPoint(Point<double>(110, 300));
    addPoint(Point<double>(155, 300));
    addPoint(Point<double>(155, 330));
    addPoint(Point<double>(140, 330));
    addPoint(Point<double>(140, 360));
    addPoint(Point<double>(155, 360));
    addPoint(Point<double>(155, 390));
    addPoint(Point<double>(140, 390));
    addPoint(Point<double>(140, 420));
    //Kanan
    //Lekukan Bawah
    addPoint(Point<double>(200, 420));
    addPoint(Point<double>(200, 390));
    addPoint(Point<double>(215, 390));
    addPoint(Point<double>(215, 360));
    addPoint(Point<double>(200, 360));
    addPoint(Point<double>(200, 330));
    addPoint(Point<double>(215, 330));
    addPoint(Point<double>(215, 300));
    addPoint(Point<double>(200, 300));
    addPoint(Point<double>(200, 270));
    addPoint(Point<double>(235, 270));
    addPoint(Point<double>(235, 300));
    addPoint(Point<double>(245, 300));
    addPoint(Point<double>(245, 330));
    addPoint(Point<double>(270, 330));
    addPoint(Point<double>(270, 360));
    addPoint(Point<double>(300, 360));
    addPoint(Point<double>(300, 330));
    addPoint(Point<double>(335, 330));
    addPoint(Point<double>(335, 360));
    //lekukan Bawah
    addPoint(Point<double>(365, 360));
    addPoint(Point<double>(365, 330));
    addPoint(Point<double>(340, 330));
    addPoint(Point<double>(340, 300));
    addPoint(Point<double>(330, 300));
    addPoint(Point<double>(330, 270));
    addPoint(Point<double>(295, 270));
    addPoint(Point<double>(295, 240));
    addPoint(Point<double>(290, 240));
    addPoint(Point<double>(290, 210));
    addPoint(Point<double>(305, 210));
    addPoint(Point<double>(305, 180));
    addPoint(Point<double>(390, 180));
    addPoint(Point<double>(390, 150));
    addPoint(Point<double>(215, 150));
    addPoint(Point<double>(215, 120));
    addPoint(Point<double>(210, 120));
    addPoint(Point<double>(210, 90));
    addPoint(Point<double>(415, 90));
    addPoint(Point<double>(415, 60));
    addPoint(Point<double>(440, 60));
    addPoint(Point<double>(440, 30));
    addPoint(Point<double>(450, 30));
    addPoint(Point<double>(450, 0));
  }
};

#endif
