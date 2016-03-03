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
  curve cur(Point<double>(390, 360), Point<double>(405, 438), Point<double>(477, 456), Point<double>(330, 465));
  cur.print(fb);
  // line lin(Point<double>(10,10), Point<double>(100,100));
  // lin.print(fb);
  fb.print();
  while (true) {}
  return 0;
}