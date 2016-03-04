#include "../lib/curve.h"
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
  //ndas
  //bawah
  curve cur(Point<double>(250, 460), Point<double>(330, 700), Point<double>(480, 700), Point<double>(550, 460));
  cur.print(fb);
  //kiri
  curve cur3(Point<double>(250, 460), Point<double>(230, 430), Point<double>(230, 400), Point<double>(250, 360));
  cur3.print(fb);
  //kanan
  curve cur4(Point<double>(550, 460), Point<double>(570, 430), Point<double>(570, 400), Point<double>(550, 360));
  cur4.print(fb);
  //atas
  curve cur2(Point<double>(250, 360), Point<double>(290, 100), Point<double>(510, 100), Point<double>(550, 360));
  cur2.print(fb);
  
  //mulut
  //bawah
  curve curs(Point<double>(330, 500), Point<double>(380, 570), Point<double>(430, 570), Point<double>(480, 500));
  curs.print(fb);
  //atas
  curve curs2(Point<double>(330, 500), Point<double>(380, 500), Point<double>(430, 500), Point<double>(480, 500));
  curs2.print(fb);
  
  
  line lin(10,10,100,100);
  //lin.print(fb);
  fb.print();
  while (true) { fb.print();}
  return 0;
}
