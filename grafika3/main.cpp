#include "lib/polygon.h"
#include <iostream>
using namespace std;

FrameBuffer fb;
Polygon* printA(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0, 600));
    pol->addPoint(Point(150, 600));
    pol->addPoint(Point(300, 370));
    pol->addPoint(Point(500, 370));
    pol->addPoint(Point(650, 600));
    pol->addPoint(Point(800, 600));
    pol->addPoint(Point(400, 0));
    return pol;
}
Polygon* printZ(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0, 0));
    pol->addPoint(Point(800, 0));
    pol->addPoint(Point(800, 100));
    pol->addPoint(Point(200, 500));
    pol->addPoint(Point(800, 500));
    pol->addPoint(Point(800, 600));
    pol->addPoint(Point(0, 600));
    pol->addPoint(Point(0, 500));
     pol->addPoint(Point(600, 100));
    pol->addPoint(Point(0, 100));
    return pol;
}
Polygon* printN(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0, 0));
    pol->addPoint(Point(100, 0));
    pol->addPoint(Point(700, 450));
    pol->addPoint(Point(700, 0));
    pol->addPoint(Point(800, 0));
    pol->addPoint(Point(800, 600));
    pol->addPoint(Point(700, 600));
    pol->addPoint(Point(100, 150));
    pol->addPoint(Point(100, 600));
    pol->addPoint(Point(0, 600));
    return pol;
}
Polygon* printD(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(200, 0));
    pol->addPoint(Point(300, 0));
    pol->addPoint(Point(450, 50));
    pol->addPoint(Point(600, 175));
    pol->addPoint(Point(600, 425));
    pol->addPoint(Point(450, 550));
    pol->addPoint(Point(300, 600));
    pol->addPoint(Point(200, 600));
    return pol;
}
Polygon* printI(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(350, 0));
    pol->addPoint(Point(450, 0));
    pol->addPoint(Point(450, 600));
    pol->addPoint(Point(350, 600));
    return pol;
}
Polygon* printL(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(200, 0));
    pol->addPoint(Point(300, 0));
    pol->addPoint(Point(300, 500));
    pol->addPoint(Point(600, 500));
    pol->addPoint(Point(600, 600));
    pol->addPoint(Point(200, 600));
    return pol;
}
Polygon* printU(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(100, 0));
    pol->addPoint(Point(200, 0));
    pol->addPoint(Point(200, 500));
    pol->addPoint(Point(600, 500));
    pol->addPoint(Point(600, 0));
    pol->addPoint(Point(700, 0));
    pol->addPoint(Point(700, 600));
    pol->addPoint(Point(100, 600));
    return pol;
}
Polygon* printC(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(100, 50));
    pol->addPoint(Point(150, 0));
    pol->addPoint(Point(700, 0));
    pol->addPoint(Point(700, 100));
    pol->addPoint(Point(200, 100));
    pol->addPoint(Point(200, 500));
    pol->addPoint(Point(700, 500));
    pol->addPoint(Point(700, 600));
    pol->addPoint(Point(150, 600));
    pol->addPoint(Point(100, 550));
    return pol;
}

Polygon* printQ(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0, 50));
    pol->addPoint(Point(50, 0));
    pol->addPoint(Point(500, 0));
    pol->addPoint(Point(500, 100));
    pol->addPoint(Point(100, 100));
    pol->addPoint(Point(100, 500));
    pol->addPoint(Point(500, 500));
    pol->addPoint(Point(500, 0));
    pol->addPoint(Point(600, 0));
    pol->addPoint(Point(600, 400));
    pol->addPoint(Point(800, 600));
    pol->addPoint(Point(700, 600));
    pol->addPoint(Point(600, 520));
    pol->addPoint(Point(600, 600));
    pol->addPoint(Point(50, 600));
    pol->addPoint(Point(0, 550));
    return pol;
}
Polygon* printM(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0, 0));
    pol->addPoint(Point(100, 0));
    pol->addPoint(Point(400, 200));
    pol->addPoint(Point(700, 0));
    pol->addPoint(Point(800, 0));
    pol->addPoint(Point(800, 600));
    pol->addPoint(Point(700, 600));
    pol->addPoint(Point(700, 100));
    pol->addPoint(Point(400, 300));
    pol->addPoint(Point(100, 100));
    pol->addPoint(Point(100, 600));
    pol->addPoint(Point(0, 600));
    return pol;
}

Polygon* proto[30];
Polygon* words[5][10];
string names[] = {"ZANDI", "ICAL", "AZAM", "LUQMAN"};

void init() {
  proto['A' - 'A'] = printA();
  proto['Z' - 'A'] = printZ();
  proto['M' - 'A'] = printM();
  proto['N' - 'A'] = printN();
  proto['D' - 'A'] = printD();
  proto['I' - 'A'] = printI();
  proto['C' - 'A'] = printC();
  proto['L' - 'A'] = printL();
  proto['U' - 'A'] = printU();
  proto['Q' - 'A'] = printQ();
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j] = new Polygon(*proto[names[i][j] - 'A']);
      words[i][j]->resize(Point(300, 400), 0.1);
      words[i][j]->move(-100+j*80, -200+(i*70));
    }
  }
}
void print(){
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j]->print(fb);
    }
  }
}
void resize_move(){
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j]->resize(Point(400, 200), 1.05);
    }
  }
}
void run(){
  init();
  int hitung=0;
  float rasio=1;
  while(rasio<=3) {
    print();
    hitung++;
    if(hitung==100){
      rasio+=0.1;
      resize_move();
      hitung=0;
      fb.clear();
    }
  }
}
int main() {
  system("clear");
  run();
  return 0;
}
