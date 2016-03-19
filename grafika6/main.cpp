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
    int x = 600,y=400,s=200;
    Polygon* belakang = new Polygon()  ;        // sisi depan
      belakang->addPoint(Point<double>(0,0,0))
      .addPoint(Point<double>(0,768,0))
      .addPoint(Point<double>(1366,768,0))
      .addPoint(Point<double>(1366,0,0))
      .setColor(Color::BLACK);
    Shape* kubus2 = new Shape();
    
    kubus2->addPolygon(Polygon()          // sisi depan
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y-s,0))
      .addPoint(Point<double>(x,y-s,0))
      .setColor(Color::RED)
    )
    .addPolygon(Polygon()                 // sisi bawah
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y,s))   
      .addPoint(Point<double>(x,y,s))
      .setColor(Color::BLUE)
    )
    .addPolygon(Polygon()                 // sisi kanan
      .addPoint(Point<double>(x+s,y,0))
      .addPoint(Point<double>(x+s,y,s))
      .addPoint(Point<double>(x+s,y-s,s))  
      .addPoint(Point<double>(x+s,y-s,0))
      .setColor(Color::GREEN)
    )
    .addPolygon(Polygon()                 // sisi belakang
      .addPoint(Point<double>(x,y,s))
      .addPoint(Point<double>(x+s,y,s))
      .addPoint(Point<double>(x+s,y-s,s))
      .addPoint(Point<double>(x,y-s,s))
      .setColor(Color::YELLOW)
    )
    .addPolygon(Polygon()                 // sisi atas
      .addPoint(Point<double>(x,y-s,0))
      .addPoint(Point<double>(x+s,y-s,0))
      .addPoint(Point<double>(x+s,y-s,s))   
      .addPoint(Point<double>(x,y-s,s))
      .setColor(Color::CYAN)
    )
    .addPolygon(Polygon()                 // sisi kiri
      .addPoint(Point<double>(x,y,0))
      .addPoint(Point<double>(x,y,s))
      .addPoint(Point<double>(x,y-s,s))  
      .addPoint(Point<double>(x,y-s,0))
      .setColor(Color::PURPLE)
    );
    //kubus2->resize(3, Point<double>(x+s/2, y-s/2, s/2));
    
    int cmd = ' ';
    /*
    Kubus* kubus = new Kubus(400,300,50);
    while(true){
      //system("clear");
      
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
    }
    */
  system("clear");
  while (1) {
    fb.clear();
    system("clear");
    //belakang->print(fb);
    kubus2->rotate(0,Point<double>(425,275,25),1,0);
    kubus2->rotate(0,Point<double>(425,275,25),0,1);
    kubus2->print(fb);
    //kubus2->printframe(fb);
    fb.print();
    usleep(20000);
  }
  return 0;
}

