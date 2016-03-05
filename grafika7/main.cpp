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
  Polygon* kepala = new Polygon();
  //ndas
  //bawah
  kepala->addCurve(Point<double>(550, 460), Point<double>(480, 700), Point<double>(330, 700), Point<double>(250, 460));
  //kiri
  kepala->addCurve(Point<double>(250, 460), Point<double>(230, 430), Point<double>(230, 400), Point<double>(250, 360));
  //atas
  kepala->addCurve(Point<double>(250, 360), Point<double>(290, 100), Point<double>(510, 100), Point<double>(550, 360));
  //kanan
  kepala->addCurve(Point<double>(550, 360), Point<double>(570, 400), Point<double>(570, 430), Point<double>(550, 460));
  kepala->setColor(255,229,220,0);
  kepala->print(fb);
  
  
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
  
  
  line lin(10,10,100,100);
  //lin.print(fb);
  fb.print();
  while (true) { fb.print();}
  return 0;
}
