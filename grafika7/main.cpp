#include "../lib/curve.h"
#include "../lib/polygon.h"
#include "../lib/line.h"
#include "../lib/conio2.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
  FrameBuffer fb;
  // fb.clear();
  system("clear");
  /*
  //rambut
  
  
  Polygon* mulut = new Polygon();
  //mulut
  //bawah
  mulut->addCurve(Point<double>(330, 500), Point<double>(380, 570), Point<double>(430, 570), Point<double>(480, 500));
  mulut->setColor(112,65,67,0);
  mulut->print(fb);
  
  Polygon* mata = new Polygon();
  //mulut
  //bawah
  mata->addCurve(Point<double>(330, 400), Point<double>(350, 330), Point<double>(410, 330), Point<double>(430, 400));
  mata->addCurve(Point<double>(430, 400), Point<double>(410, 470), Point<double>(350, 470), Point<double>(330, 400));
  mata->setColor(255,255,255,0);
  mata->print(fb);
  
  
  //line lin(10,10,100,100);
  //lin.print(fb);
  */
  //Kepala
  Polygon* kepala = new Polygon();
  //ndas
  //bawah
  kepala->addCurve(Point<double>(100, 500), Point<double>(210, 630), Point<double>(310, 630), Point<double>(420, 500));
  kepala->addPoint(Point<double>(420, 500));
  kepala->addPoint(Point<double>(420, 400));
  //kiri
  kepala->addCurve(Point<double>(420, 400), Point<double>(430, 390), Point<double>(420, 360), Point<double>(410, 350));
  //atas
  kepala->addCurve(Point<double>(410, 350), Point<double>(360, 70), Point<double>(160, 70), Point<double>(110, 350));
  //kanan
  kepala->addCurve(Point<double>(110, 350), Point<double>(90, 360), Point<double>(110, 390), Point<double>(100, 400));
  kepala->addPoint(Point<double>(100, 400));
  kepala->addPoint(Point<double>(100, 500));
  kepala->setColor(255,229,220,0);
  kepala->print(fb);
  //Mata Kiri
  Polygon* matakiri = new Polygon();
  matakiri->addCurve(Point<double>(140, 335), Point<double>(160, 305), Point<double>(210, 305), Point<double>(230, 335));
  matakiri->addCurve(Point<double>(230, 335), Point<double>(210, 365), Point<double>(160, 365), Point<double>(140, 335));
  matakiri->setColor(255,255,255,0);
  matakiri->print(fb);
  //Bolamata kiri
  Polygon* bolakiri = new Polygon();
  bolakiri->addCurve(Point<double>(160, 335), Point<double>(180, 305), Point<double>(190, 305), Point<double>(210, 335));
  bolakiri->addCurve(Point<double>(210, 335), Point<double>(190, 365), Point<double>(180, 365), Point<double>(160, 335));
  bolakiri->setColor(87,59,12,0);
  bolakiri->print(fb);
  //Mata Kanan
  Polygon* matakanan = new Polygon();
  matakanan->addCurve(Point<double>(290, 335), Point<double>(310, 305), Point<double>(360, 305), Point<double>(380, 335));
  matakanan->addCurve(Point<double>(380, 335), Point<double>(360, 365), Point<double>(310, 365), Point<double>(290, 335));
  matakanan->setColor(255,255,255,0);
  matakanan->print(fb);
  //Bolamata kanan
  Polygon* bolakanan = new Polygon();
  bolakanan->addCurve(Point<double>(310, 335), Point<double>(330, 305), Point<double>(340, 305), Point<double>(360, 335));
  bolakanan->addCurve(Point<double>(360, 335), Point<double>(340, 365), Point<double>(330, 365), Point<double>(310, 335));
  bolakanan->setColor(87,59,12,0);
  bolakanan->print(fb);
  //mulut
  Polygon* mulut = new Polygon();
  //bawah
  mulut->addCurve(Point<double>(210, 500), Point<double>(230, 570), Point<double>(280, 570), Point<double>(330, 500));
  mulut->setColor(112,65,67,0);
  mulut->print(fb);
  //Rambut
  Polygon* rambut = new Polygon();
  //kanan
  rambut->addCurve(Point<double>(310, 30), Point<double>(420, 100), Point<double>(460, 170), Point<double>(470, 320));
  //last point 
  //rambut->addPoint(Point<double>(470, 320));
  rambut->addPoint(Point<double>(470, 400));
  rambut->addPoint(Point<double>(460, 400));
  //rambut->addCurve(Point<double>(460, 480), Point<double>(470, 490), Point<double>(480, 500), Point<double>(490, 520));
  //kiri
  rambut->addPoint(Point<double>(460, 500));
  //rambut->addPoint(Point<double>(490, 520));
  rambut->addPoint(Point<double>(450, 500));
  //rambut->addPoint(Point<double>(450, 550));
  rambut->addCurve(Point<double>(450, 550), Point<double>(460, 570), Point<double>(470, 580), Point<double>(480, 600));
  rambut->addCurve(Point<double>(480, 600), Point<double>(460, 626), Point<double>(440, 650), Point<double>(470, 660));
  rambut->addCurve(Point<double>(470, 660), Point<double>(440, 650), Point<double>(420, 640), Point<double>(380, 620));
  //rambut->addPoint(Point<double>(380, 620));
  rambut->addCurve(Point<double>(380, 570), Point<double>(400, 540), Point<double>(410, 530), Point<double>(420, 500));
  rambut->addPoint(Point<double>(420, 500));
  rambut->addPoint(Point<double>(420, 380));
  //rambut->addPoint(Point<double>(390, 400));
  rambut->addCurve(Point<double>(390, 400), Point<double>(380, 260), Point<double>(360, 210), Point<double>(320, 160));
  rambut->addCurve(Point<double>(320, 160), Point<double>(270, 200), Point<double>(230, 240), Point<double>(190, 320));
  rambut->addCurve(Point<double>(190, 320), Point<double>(190, 270), Point<double>(140, 280), Point<double>(200, 250));
  rambut->addCurve(Point<double>(200, 250), Point<double>(160, 270), Point<double>(140, 280), Point<double>(100, 370));
  rambut->addPoint(Point<double>(100, 370));
  //rambut->addPoint(Point<double>(100, 460));
  rambut->addCurve(Point<double>(100, 460), Point<double>(110, 550), Point<double>(120, 670), Point<double>(180, 730));
  rambut->addCurve(Point<double>(180, 730), Point<double>(10, 690), Point<double>(50, 660), Point<double>(10, 600));
  rambut->addCurve(Point<double>(10, 600), Point<double>(30, 590), Point<double>(40, 580), Point<double>(20, 560));
  rambut->addCurve(Point<double>(20, 560), Point<double>(40, 500), Point<double>(30, 440), Point<double>(10, 350));
  rambut->addCurve(Point<double>(10, 350), Point<double>(40, 170), Point<double>(100, 100), Point<double>(250, 30));	
  rambut->addPoint(Point<double>(250, 30));
  //rambut->addPoint(Point<double>(310, 30));
  //last point
  rambut->setColor(217,62,20,0);
  rambut->print(fb);
  while (true) { fb.print();}
  return 0;
}
