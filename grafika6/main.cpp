#include "../lib/polygon.h"
#include "../lib/shape.h"
#include <iostream>
#include <unistd.h>
#include "../lib/conio2.h"

//#include "objects/belakang.h"
//#include "objects/window.h"
//#include "objects/Indonesia.h"
//#include "objects/kotak.h"
#include "objects/Kubus.h"

const Point<double> window_corner_a = Point<double>(966, 544);
const Point<double> window_corner_b = Point<double>(1366, 768);
const int MAKS_ZOOM = 15;
const int MIN_ZOOM = -10;

#define ZOOM_IN 1.1
#define ZOOM_OUT 0.9

using namespace std;

FrameBuffer fb;
//Window* window;
//Kotak* kotak = new Kotak(window_corner_a, window_corner_b);

int main() {  
    int x = 400,y=300,s=50;
    Shape* kubus2 = new Shape();
    
    kubus2->addPolygon(Polygon()
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y-s,0))
      .addPoint(Point<double>(x,y-s,0))
    )
    .addPolygon(Polygon()
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y,s))   
      .addPoint(Point<double>(x,y,s))
    )
    .addPolygon( Polygon()
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y,s))
      .addPoint(Point<double>(x+s,y-s,s))  
      .addPoint(Point<double>(x+s,y-s,0))
    )
    .addPolygon( Polygon()
      .addPoint(Point<double>(x,y,s))
      .addPoint(Point<double>(x+s,y,s))
      .addPoint(Point<double>(x+s,y-s,s))
      .addPoint(Point<double>(x,y-s,s))
    )
    
    .addPolygon( Polygon()
      .addPoint(Point<double>(x,y-s,0))
      .addPoint(Point<double>(x+s,y-s,0))
      .addPoint(Point<double>(x+s,y-s,s))   
      .addPoint(Point<double>(x,y-s,s))
    )
    
    .addPolygon( Polygon()
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x,y,s))
      .addPoint(Point<double>(x,y-s,s))  
      .addPoint(Point<double>(x,y-s,0))
    );
    
    system("clear");
    int cmd = ' ';
    kubus2->print(fb);
    /*
    Kubus* kubus = new Kubus(400,300,50);
    while(true){
      //system("clear");
      cmd = getch();
      if (cmd == 27) {
       cmd = getch();
       if (cmd == 27) {
         break;
       }
       else if (cmd == 91) {
         cmd = getch();
         cmd = 64 - cmd;
       }
      }
      else if (cmd == 'a' || cmd == 'A' || cmd == -4) {
        kubus->rotate(0,Point<double>(425,275,25),0,-1);
      }
      else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
        kubus->rotate(0,Point<double>(425,275,25),0,1);
      }
      else if (cmd == 'w' || cmd == 'W' || cmd == -1) {        
        kubus->rotate(0,Point<double>(425,275,25),1,0);
      }
      else if (cmd == 's' || cmd == 'S' || cmd == -2) {
        kubus->rotate(0,Point<double>(425,275,25),-1,0);
      }
      else if (cmd == 'q' || cmd == 'Q') {        
        kubus->rotate(1,Point<double>(425,275,25),0,0);
      }
      else if (cmd == 'e' || cmd == 'E') {
        kubus->rotate(-1,Point<double>(425,275,25),0,0);
      }
      system("clear");
      kubus->printpoint();
      //kubus->rotate(0,Point<double>(425,275,25),0,1);
      //kubus->rotateCenter(1.1);
      kubus->printpoint();
      kubus->print3d(fb,123,12,12,0);
      fb.print();   
      fb.clear();
      usleep(40000);
    }
    */
  fb.print();
  return 0;
}

