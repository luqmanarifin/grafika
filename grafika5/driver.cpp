#include <bits/stdc++.h>
#include "lib/polygon.h"
#include "lib/framebuffer.h"

int main(int argc, char const *argv[])
{
  system("clear");
  Polygon *p = new Polygon();
  p->addPoint(Point(300,200));
  p->addPoint(Point(200,220));
  p->addPoint(Point(500,300));
  p->addPoint(Point(340,520));
  p->addPoint(Point(500,500));
  p->addPoint(Point(200,380));
  FrameBuffer fb;
  p->print(fb);
  fb.print();
  while (true) {}
  return 0;
}