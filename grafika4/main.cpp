#include "lib/polygon.h"
#include <iostream>
using namespace std;

FrameBuffer fb;

Polygon* printpeluru(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(300,600));
    pol->addPoint(Point(500,600));
    pol->addPoint(Point(500,200));
    pol->addPoint(Point(550,200));
    pol->addPoint(Point(450,0));
    pol->addPoint(Point(350,0));
    pol->addPoint(Point(250,200));
    pol->addPoint(Point(300,200));
    return pol;
}

Polygon* printsijagur(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(800,600));
    pol->addPoint(Point(800,500));
    pol->addPoint(Point(700,500));
    pol->addPoint(Point(700,300));
    pol->addPoint(Point(600,300));
    pol->addPoint(Point(600,0));
    pol->addPoint(Point(500,0));
    pol->addPoint(Point(500,200));
    pol->addPoint(Point(300,200));
    pol->addPoint(Point(300,0));
    pol->addPoint(Point(200,0));
    pol->addPoint(Point(200,500));
    pol->addPoint(Point(200,300));
    pol->addPoint(Point(100,300));
    pol->addPoint(Point(100,500));
    pol->addPoint(Point(0,500));
    pol->addPoint(Point(0,600));
    return pol;
}

Polygon* printroda(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(325,90));
    pol->addPoint(Point(475,90));
    pol->addPoint(Point(475,120));
    pol->addPoint(Point(535,120));
    pol->addPoint(Point(535,150));
    pol->addPoint(Point(565,150));
    pol->addPoint(Point(565,180));
    pol->addPoint(Point(595,180));
    pol->addPoint(Point(595,210));
    pol->addPoint(Point(625,210));
    pol->addPoint(Point(625,270));
    pol->addPoint(Point(655,270));
    pol->addPoint(Point(655,420));
    pol->addPoint(Point(625,420));
    pol->addPoint(Point(625,480));
    pol->addPoint(Point(595,480));
    pol->addPoint(Point(595,510));
    pol->addPoint(Point(565,510));
    pol->addPoint(Point(565,540));
    pol->addPoint(Point(535,540));
    pol->addPoint(Point(535,570));
    pol->addPoint(Point(475,570));
    pol->addPoint(Point(475,600));
    pol->addPoint(Point(325,600));
    pol->addPoint(Point(325,570));
    pol->addPoint(Point(265,570));
    pol->addPoint(Point(265,540));
    pol->addPoint(Point(235,540));
    pol->addPoint(Point(235,510));
    pol->addPoint(Point(205,510));
    pol->addPoint(Point(205,480));
    pol->addPoint(Point(175,480));
    pol->addPoint(Point(175,420));
    pol->addPoint(Point(145,420));
    pol->addPoint(Point(145,270));
    pol->addPoint(Point(175,270));
    pol->addPoint(Point(175,210));
    pol->addPoint(Point(205,210));
    pol->addPoint(Point(205,180));
    pol->addPoint(Point(235,180));
    pol->addPoint(Point(235,150));
    pol->addPoint(Point(265,150));
    pol->addPoint(Point(265,120));
    pol->addPoint(Point(325,120));
    pol->addPoint(Point(325,390));
    pol->addPoint(Point(355,390));
    pol->addPoint(Point(355,420));
    pol->addPoint(Point(445,420));
    pol->addPoint(Point(445,390));
    pol->addPoint(Point(475,390));
    pol->addPoint(Point(475,300));
    pol->addPoint(Point(445,300));
    pol->addPoint(Point(445,270));
    pol->addPoint(Point(355,270));
    pol->addPoint(Point(355,300));
    pol->addPoint(Point(325,300));
    return pol;
}

Polygon* printparachute(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(75,350));
    pol->addPoint(Point(25,400));
    pol->addPoint(Point(0,200));
    pol->addPoint(Point(50,150));
    pol->addPoint(Point(200,100));
    pol->addPoint(Point(600,100));
    pol->addPoint(Point(750,150));
    pol->addPoint(Point(800,200));
    pol->addPoint(Point(775,400));
    pol->addPoint(Point(725,350));
    pol->addPoint(Point(575,300));
    pol->addPoint(Point(550,600));
    pol->addPoint(Point(525,600));
    pol->addPoint(Point(550,300));
    pol->addPoint(Point(250,300));
    pol->addPoint(Point(275,600));
    pol->addPoint(Point(250,600));
    pol->addPoint(Point(225,300));
    return pol;
}

int main() {
  system("clear");
  printparachute()->print(fb);
  return 0;
}
