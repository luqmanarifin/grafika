#ifndef __KALIMANTAN_H_
#define __KALIMANTAN_H_

#include "../lib/polygon.h" 

struct Kalimantan : public Polygon {
  Kalimantan() {
    //Kiri
    addPoint(Point<double>(480, 0));
    //addPoint(Point<double>(480, 30));
    addPoint(Point<double>(470, 30));
    //addPoint(Point<double>(470, 60));
    addPoint(Point<double>(445, 60));
    //addPoint(Point<double>(445, 90));
    addPoint(Point<double>(440, 90));
    //addPoint(Point<double>(440, 120));
    addPoint(Point<double>(415, 120));
    //addPoint(Point<double>(415, 150));    
    //Lekukan Atas
    //addPoint(Point<double>(405, 150));
    addPoint(Point<double>(405, 180));
    addPoint(Point<double>(325, 180));
    addPoint(Point<double>(310, 150));
    addPoint(Point<double>(275, 150));
    addPoint(Point<double>(265, 180));
    addPoint(Point<double>(215, 195));
    addPoint(Point<double>(200, 210));
    addPoint(Point<double>(160, 210));
    addPoint(Point<double>(145, 195));
    addPoint(Point<double>(135, 180));
    addPoint(Point<double>(105, 175));
    addPoint(Point<double>(75, 150));
    //addPoint(Point<double>(75, 180));
    //Lekukan Atas
    addPoint(Point<double>(85, 180));
    //addPoint(Point<double>(85, 210));
    addPoint(Point<double>(110, 210));
    //addPoint(Point<double>(110, 240));
    addPoint(Point<double>(125, 240));
    //addPoint(Point<double>(125, 270));
    addPoint(Point<double>(150, 270));
    //addPoint(Point<double>(150, 300));
    addPoint(Point<double>(160, 300));
    //addPoint(Point<double>(160, 330));
    addPoint(Point<double>(185, 330));
    //addPoint(Point<double>(185, 360));
    addPoint(Point<double>(160, 360));
    addPoint(Point<double>(175, 390));
    //Lekukan bawah
    addPoint(Point<double>(230, 390));
    addPoint(Point<double>(245, 420));
    addPoint(Point<double>(305, 420));
    addPoint(Point<double>(320, 390));
    addPoint(Point<double>(370, 390));
    addPoint(Point<double>(385, 420));
    //lekukan bawah
    addPoint(Point<double>(415, 420));
    addPoint(Point<double>(430, 450));
    //Kanan
    addPoint(Point<double>(490, 450));
    addPoint(Point<double>(505, 420));
    //addPoint(Point<double>(515, 420));
    addPoint(Point<double>(515, 390));
    //addPoint(Point<double>(545, 390));
    addPoint(Point<double>(545, 360));
    //addPoint(Point<double>(535, 360));
    addPoint(Point<double>(535, 330));
    //addPoint(Point<double>(540, 330));
    addPoint(Point<double>(540, 300));
    //addPoint(Point<double>(565, 300));
    addPoint(Point<double>(565, 270));
    //addPoint(Point<double>(610, 270));
    addPoint(Point<double>(610, 240));
    //addPoint(Point<double>(600, 240));
    addPoint(Point<double>(600, 210));
    //addPoint(Point<double>(610, 210));
    addPoint(Point<double>(610, 180));
    //addPoint(Point<double>(665, 180));
    addPoint(Point<double>(665, 150));
    //addPoint(Point<double>(640, 150));
    addPoint(Point<double>(640, 120));
    //addPoint(Point<double>(630, 120));
    addPoint(Point<double>(630, 90));
    //addPoint(Point<double>(605, 90));
    addPoint(Point<double>(605, 60));
    //addPoint(Point<double>(595, 60));
    addPoint(Point<double>(595, 30));
    //addPoint(Point<double>(600, 30));
    addPoint(Point<double>(600, 0));
  }
};

#endif
