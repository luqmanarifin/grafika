#include "../lib/polygon.h"
#include <iostream>
using namespace std;

FrameBuffer fb;
Polygon* printA(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(0, 600));
    pol->addPoint(Point<double>(150, 600));
    pol->addPoint(Point<double>(300, 370));
    pol->addPoint(Point<double>(400, 370));
    pol->addPoint(Point<double>(400, 270));
    pol->addPoint(Point<double>(330, 270));
    pol->addPoint(Point<double>(400, 140));
    pol->addPoint(Point<double>(470, 270));
    pol->addPoint(Point<double>(400, 270));
    pol->addPoint(Point<double>(400, 370));
    pol->addPoint(Point<double>(500, 370));
    pol->addPoint(Point<double>(650, 600));
    pol->addPoint(Point<double>(800, 600));
    pol->addPoint(Point<double>(400, 0));
    return pol;
}
Polygon* printZ(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(0, 0));
    pol->addPoint(Point<double>(800, 0));
    pol->addPoint(Point<double>(800, 100));
    pol->addPoint(Point<double>(200, 500));
    pol->addPoint(Point<double>(800, 500));
    pol->addPoint(Point<double>(800, 600));
    pol->addPoint(Point<double>(0, 600));
    pol->addPoint(Point<double>(0, 500));
     pol->addPoint(Point<double>(600, 100));
    pol->addPoint(Point<double>(0, 100));
    return pol;
}
Polygon* printN(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(0, 0));
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(700, 450));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(800, 0));
    pol->addPoint(Point<double>(800, 600));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(100, 150));
    pol->addPoint(Point<double>(100, 600));
    pol->addPoint(Point<double>(0, 600));
    return pol;
}
Polygon* printD(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(200, 0));
    pol->addPoint(Point<double>(300, 0));
    pol->addPoint(Point<double>(300, 500));
    pol->addPoint(Point<double>(450, 450));
    pol->addPoint(Point<double>(500, 425));
    pol->addPoint(Point<double>(500, 175));
    pol->addPoint(Point<double>(450, 150));
    pol->addPoint(Point<double>(300, 100));
     pol->addPoint(Point<double>(300, 0));
    pol->addPoint(Point<double>(450, 50));
    pol->addPoint(Point<double>(600, 175));
    pol->addPoint(Point<double>(600, 425));
    pol->addPoint(Point<double>(450, 550));
    pol->addPoint(Point<double>(300, 600));
    pol->addPoint(Point<double>(200, 600));
    return pol;
}
Polygon* printI(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(350, 0));
    pol->addPoint(Point<double>(450, 0));
    pol->addPoint(Point<double>(450, 600));
    pol->addPoint(Point<double>(350, 600));
    return pol;
}
Polygon* printL(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(200, 0));
    pol->addPoint(Point<double>(300, 0));
    pol->addPoint(Point<double>(300, 500));
    pol->addPoint(Point<double>(600, 500));
    pol->addPoint(Point<double>(600, 600));
    pol->addPoint(Point<double>(200, 600));
    return pol;
}
Polygon* printU(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(200, 0));
    pol->addPoint(Point<double>(200, 500));
    pol->addPoint(Point<double>(600, 500));
    pol->addPoint(Point<double>(600, 0));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(100, 600));
    return pol;
}
Polygon* printC(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(100, 50));
    pol->addPoint(Point<double>(150, 0));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(700, 100));
    pol->addPoint(Point<double>(200, 100));
    pol->addPoint(Point<double>(200, 500));
    pol->addPoint(Point<double>(700, 500));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(150, 600));
    pol->addPoint(Point<double>(100, 550));
    return pol;
}

Polygon* printQ(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(0, 50));
    pol->addPoint(Point<double>(50, 0));
    pol->addPoint(Point<double>(500, 0));
    pol->addPoint(Point<double>(500, 100));
    pol->addPoint(Point<double>(100, 100));
    pol->addPoint(Point<double>(100, 500));
    pol->addPoint(Point<double>(500, 500));
    pol->addPoint(Point<double>(500, 0));
    pol->addPoint(Point<double>(600, 0));
    pol->addPoint(Point<double>(600, 400));
    pol->addPoint(Point<double>(800, 600));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(600, 520));
    pol->addPoint(Point<double>(600, 600));
    pol->addPoint(Point<double>(50, 600));
    pol->addPoint(Point<double>(0, 550));
    return pol;
}
Polygon* printM(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(0, 0));
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(400, 200));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(800, 0));
    pol->addPoint(Point<double>(800, 600));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(700, 100));
    pol->addPoint(Point<double>(400, 300));
    pol->addPoint(Point<double>(100, 100));
    pol->addPoint(Point<double>(100, 600));
    pol->addPoint(Point<double>(0, 600));
    return pol;
}
Polygon* printR(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(500, 0));
    pol->addPoint(Point<double>(700, 120));
    pol->addPoint(Point<double>(700, 240));
    pol->addPoint(Point<double>(500, 360));
    pol->addPoint(Point<double>(700, 480));
    pol->addPoint(Point<double>(700, 360));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(500, 600));
    pol->addPoint(Point<double>(500, 480));
    pol->addPoint(Point<double>(301, 480));
    pol->addPoint(Point<double>(301, 240));
    pol->addPoint(Point<double>(500, 240));
    pol->addPoint(Point<double>(500, 120));
    pol->addPoint(Point<double>(301, 120));
    pol->addPoint(Point<double>(300, 480));
    pol->addPoint(Point<double>(300, 600));
    pol->addPoint(Point<double>(100, 600));
    return pol;
}
Polygon* printH(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(300, 0));
    pol->addPoint(Point<double>(300, 200));
    pol->addPoint(Point<double>(500, 200));
    pol->addPoint(Point<double>(500, 0));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(500, 600));
    pol->addPoint(Point<double>(500, 400));
    pol->addPoint(Point<double>(300, 400));
    pol->addPoint(Point<double>(300, 600));
    pol->addPoint(Point<double>(100, 600));
    return pol;
}
Polygon* printE(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point<double>(100, 0));
    pol->addPoint(Point<double>(700, 0));
    pol->addPoint(Point<double>(700, 120));
    pol->addPoint(Point<double>(300, 120));
    pol->addPoint(Point<double>(300, 240));
    pol->addPoint(Point<double>(700, 240));
    pol->addPoint(Point<double>(700, 360));
    pol->addPoint(Point<double>(300, 360));
    pol->addPoint(Point<double>(300, 480));
    pol->addPoint(Point<double>(700, 480));
    pol->addPoint(Point<double>(700, 600));
    pol->addPoint(Point<double>(100, 600));
    return pol;
}
Polygon* proto[30];
Polygon* words[5][10];
string names[] = {"ZANDI", "ICAL", "AZAM", "LUQMAN", "HERI"};

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
  proto['H' - 'A'] = printH();
  proto['E' - 'A'] = printE();
  proto['R' - 'A'] = printR();
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j] = new Polygon(*proto[names[i][j] - 'A']);
      words[i][j]->resize(Point(300, 400), 0.1);
      words[i][j]->move(-100+j*80, -300+(i*70));
    }
  }
}
void print(){
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j]->print(fb);
    }
  }
}
void resize_move(float skala){
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < names[i].size(); j++) {
      words[i][j]->resize(Point(400, 200), skala);
    }
  }
}
void run(){
  init();
  float rasio=1;
  while(rasio<=3) {
    print();
    rasio+=0.1;
    resize_move(1.05);
    usleep(50000);
    fb.clear();
  }
  rasio = 0;
  while(rasio<=3) {
    print();
    rasio+=0.1;
    resize_move(0.95);
    usleep(50000);
    fb.clear();
  }
}
int main() {
  system("clear");
  //printA()->print(fb);
  run();
  return 0;
}
