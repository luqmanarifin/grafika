#include "lib/polygon.h"

using namespace std;

FrameBuffer fb;

int main() {
  system("clear");
  while(1) {
    Polygon pol;
    pol.addPoint(Point(300, 200));
    pol.addPoint(Point(400, 200));
    pol.addPoint(Point(500, 400));
    pol.print(fb);
  }
  return 0;
}