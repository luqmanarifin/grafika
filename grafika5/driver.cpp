#include <bits/stdc++.h>
#include "../lib/polygon.h"
#include "../lib/framebuffer.h"

int main(int argc, char const *argv[])
{
  system("clear");
  Polygon *p = new Polygon();
  p->addPoint(Point<double>(300,200));
  p->addPoint(Point<double>(200,220));
  p->addPoint(Point<double>(500,300));
  p->addPoint(Point<double>(340,520));
  p->addPoint(Point<double>(500,500));
  p->addPoint(Point<double>(200,380));
  FrameBuffer fb;
  p->print(fb);
  fb.print();
  while (true) {}
  return 0;
}