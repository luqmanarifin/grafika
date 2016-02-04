#include "lib/polygon.h"

using namespace std;

FrameBuffer fb;

int main() {
  system("clear");
  while(1) {
    Polygon pol;
    pol.addPoint(Point(100, 500));
    pol.addPoint(Point(300, 300));
    pol.addPoint(Point(500, 500));
    pol.print(fb);
  }
  return 0;
}