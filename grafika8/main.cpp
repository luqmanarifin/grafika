#include "../lib/curve.h"
#include "../lib/polygon.h"
#include "../lib/line.h"
#include "../lib/conio2.h"
#include "objects/pln.h"
#include "objects/gedung.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
FrameBuffer fb;

int main(int argc, char const *argv[])
{
  int cmd = ' ';
  // fb.clear();
  system("clear");
  //Pln* pp = new Pln();
  int x,y,s;
  x=150;
  y=300;
  s=50;
  /*
  Polygon* pp = new Polygon(Polygon()
      .addPoint(Point<double>(x,y,s))
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+(2*s),y,0))
      .addPoint(Point<double>(x+(4*s),y,(2*s)))
      .addPoint(Point<double>(x+(4*s),y+s,(2*s)))
      .addPoint(Point<double>(x+(2*s),y+s,0))
      .addPoint(Point<double>(x+s,y+s,0))
      .addPoint(Point<double>(x,y+s,s))
  );
  */
  ITB* pp = new ITB();
  pp->rotate(0,Point<double>(512,354,240),90,0);
  //while (1) {
    fb.clear();
    system("clear");
    //pp->rotate(0,Point<double>(640,400,240),1,0);
   // pp->rotate(0,Point<double>(340,335,15),0,1);
    pp->print(fb);
    fb.print();
    fb.clear();
    usleep(75000);
  //}
  return 0;
}
