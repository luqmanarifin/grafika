#ifndef __PAPUA_H_
#define __PAPUA_H_

#include "../../lib/polygon.h" 

struct Papua : public Polygon {
  Papua() {
    //Kiri
    addPoint(Point<double>(70, 0));
    //addPoint(Point<double>(70, 30));
    addPoint(Point<double>(30, 30));
    //addPoint(Point<double>(30, 60));
    addPoint(Point<double>(70, 60));
    addPoint(Point<double>(60, 90));
    addPoint(Point<double>(150, 90));
    addPoint(Point<double>(165, 120));
    addPoint(Point<double>(70, 120));
    addPoint(Point<double>(85, 150));
    addPoint(Point<double>(125, 150));
    //addPoint(Point<double>(125, 180));
    addPoint(Point<double>(135, 180));
    //addPoint(Point<double>(135, 210));
    //Lekukan bawah
    addPoint(Point<double>(165, 210));
    addPoint(Point<double>(170, 170));
    addPoint(Point<double>(200, 180));
    addPoint(Point<double>(205, 210));
    //Lekukan bawah
    //addPoint(Point<double>(255, 210));
    addPoint(Point<double>(255, 240));
    //addPoint(Point<double>(355, 240));
    addPoint(Point<double>(355, 270));
    //addPoint(Point<double>(410, 270));
    addPoint(Point<double>(410, 300));
    //addPoint(Point<double>(420, 300));
    addPoint(Point<double>(420, 330));
    //addPoint(Point<double>(445, 330));
    addPoint(Point<double>(445, 360));
    //addPoint(Point<double>(490, 360));
    addPoint(Point<double>(490, 390));
    //addPoint(Point<double>(515, 390));
    addPoint(Point<double>(515, 420));
    //addPoint(Point<double>(555, 420));
    addPoint(Point<double>(555, 450));
    //addPoint(Point<double>(580, 450));
    addPoint(Point<double>(580, 480));
    //Kanan
    addPoint(Point<double>(600, 480));
    addPoint(Point<double>(600, 150));
    //addPoint(Point<double>(600, 120));
    addPoint(Point<double>(530, 120));
    //addPoint(Point<double>(530, 90));
    addPoint(Point<double>(455, 90));
    addPoint(Point<double>(445, 60));
    //Lekukan Atas
    addPoint(Point<double>(385, 60));
    addPoint(Point<double>(375, 90));
    addPoint(Point<double>(320, 90));
    addPoint(Point<double>(310, 120));
    addPoint(Point<double>(295, 120));
    addPoint(Point<double>(285, 150));
    addPoint(Point<double>(235, 150));
    addPoint(Point<double>(225, 120));
    //addPoint(Point<double>(215, 120));
    addPoint(Point<double>(200, 90));
    //addPoint(Point<double>(190, 90));
    addPoint(Point<double>(175, 60));
    //lekukan Atas
    //addPoint(Point<double>(210, 60));
    addPoint(Point<double>(195, 30));
    //addPoint(Point<double>(160, 30));
    addPoint(Point<double>(160, 0));
  }
};

#endif
