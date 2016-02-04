#include "lib/polygon.h"

using namespace std;

FrameBuffer fb;
Polygon printA(){
    Polygon pol;
    pol.addPoint(Point(0, 600));
    pol.addPoint(Point(150, 600));
    pol.addPoint(Point(300, 370));
    pol.addPoint(Point(500, 370));
    pol.addPoint(Point(650, 600));
    pol.addPoint(Point(800, 600));
    pol.addPoint(Point(400, 0));
    //printf("Masuk 1\n");
    return pol;
}
Polygon printZ(){
    Polygon pol;
    pol.addPoint(Point(0, 0));
    pol.addPoint(Point(800, 0));
    pol.addPoint(Point(800, 100));
    pol.addPoint(Point(200, 500));
    pol.addPoint(Point(800, 500));
    pol.addPoint(Point(800, 600));
    pol.addPoint(Point(0, 600));
    pol.addPoint(Point(0, 500));
     pol.addPoint(Point(600, 100));
    pol.addPoint(Point(0, 100));
    //printf("Masuk 1\n");
    return pol;
}
Polygon printN(){
    Polygon pol;
    pol.addPoint(Point(0, 0));
    pol.addPoint(Point(100, 0));
    pol.addPoint(Point(700, 450));
    pol.addPoint(Point(700, 0));
    pol.addPoint(Point(800, 0));
    pol.addPoint(Point(800, 600));
    pol.addPoint(Point(700, 600));
    pol.addPoint(Point(100, 150));
    pol.addPoint(Point(100, 600));
    pol.addPoint(Point(0, 600));
    
    //printf("Masuk 1\n");
    return pol;
}
Polygon printD(){
    Polygon pol;
    pol.addPoint(Point(200, 0));
    pol.addPoint(Point(300, 0));
    pol.addPoint(Point(450, 50));
    pol.addPoint(Point(600, 175));
    pol.addPoint(Point(600, 425));
    pol.addPoint(Point(450, 550));
    pol.addPoint(Point(300, 600));
    pol.addPoint(Point(200, 600));
    
    //printf("Masuk 1\n");
    return pol;
}
Polygon printI(){
    Polygon pol;
    pol.addPoint(Point(350, 0));
    pol.addPoint(Point(450, 0));
    pol.addPoint(Point(450, 600));
    pol.addPoint(Point(350, 600));
    
    //printf("Masuk 1\n");
    return pol;
}
Polygon printL(){
    Polygon pol;
    pol.addPoint(Point(200, 0));
    pol.addPoint(Point(300, 0));
    pol.addPoint(Point(300, 500));
    pol.addPoint(Point(600, 500));
    pol.addPoint(Point(600, 600));
    pol.addPoint(Point(200, 600));
    
    //printf("Masuk 1\n");
    return pol;
}
Polygon printU(){
    Polygon pol;
    pol.addPoint(Point(100, 0));
    pol.addPoint(Point(200, 0));
    pol.addPoint(Point(200, 500));
    pol.addPoint(Point(600, 500));
    pol.addPoint(Point(600, 0));
    pol.addPoint(Point(700, 0));
    pol.addPoint(Point(700, 600));
    pol.addPoint(Point(100, 600));
    
    //printf("Masuk 1\n");
    return pol;
}
Polygon printC(){
    Polygon pol;
    pol.addPoint(Point(100, 50));
    pol.addPoint(Point(150, 0));
    pol.addPoint(Point(700, 0));
    pol.addPoint(Point(700, 100));
    pol.addPoint(Point(200, 100));
    pol.addPoint(Point(200, 500));
    pol.addPoint(Point(700, 500));
    pol.addPoint(Point(700, 600));
    pol.addPoint(Point(150, 600));
    pol.addPoint(Point(100, 550));
    //printf("Masuk 1\n");
    return pol;
}

Polygon printQ(){
    Polygon pol;
    pol.addPoint(Point(0, 50));
    pol.addPoint(Point(50, 0));
    pol.addPoint(Point(500, 0));
    pol.addPoint(Point(500, 100));
    pol.addPoint(Point(100, 100));
    pol.addPoint(Point(100, 500));
    pol.addPoint(Point(500, 500));
    pol.addPoint(Point(500, 0));
    pol.addPoint(Point(600, 0));
    pol.addPoint(Point(600, 400));
    pol.addPoint(Point(800, 600));
    pol.addPoint(Point(700, 600));
    pol.addPoint(Point(600, 520));
    pol.addPoint(Point(600, 600));
    pol.addPoint(Point(50, 600));
    pol.addPoint(Point(0, 550));
    //printf("Masuk 1\n");
    return pol;
}
Polygon printM(){
    Polygon pol;
    pol.addPoint(Point(0, 0));
    pol.addPoint(Point(100, 0));
    pol.addPoint(Point(400, 200));
    pol.addPoint(Point(700, 0));
    pol.addPoint(Point(800, 0));
    pol.addPoint(Point(800, 600));
    pol.addPoint(Point(700, 600));
    pol.addPoint(Point(700, 100));
    pol.addPoint(Point(400, 300));
    pol.addPoint(Point(100, 100));
    pol.addPoint(Point(100, 600));
    pol.addPoint(Point(0, 600));
    //printf("Masuk 1\n");
    return pol;
}
int main() {
  system("clear");
  while(1) {
    printU().print(fb);;
  }
  return 0;
}
