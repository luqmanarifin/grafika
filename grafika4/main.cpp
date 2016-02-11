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

int main() {
  system("clear");
  printpeluru()->print(fb);
  return 0;
}
