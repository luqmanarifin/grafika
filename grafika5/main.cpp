#include "lib/polygon.h"
#include <iostream>
#include <unistd.h>
#include "lib/conio2.h"

#include "objects/belakang.h"
#include "objects/window.h"
#include "objects/Indonesia.h"


const Point<int> window_corner_a = Point<int>(966, 518);
const Point<int> window_corner_b = Point<int>(1400, 1000);
const int MAKS_ZOOM = 3;
const int MIN_ZOOM = -1;

using namespace std;

FrameBuffer fb;
Window* window;

int main() {  
  system("clear");
  int cmd = ' ';
  window = new Window(window_corner_a.x, window_corner_a.y);
  Indonesia* indo = new Indonesia();
  indo->print(fb, new Belakang());
  fb.print_exclude(window_corner_a, window_corner_b);
  
  Indonesia* small_indo = new Indonesia();
  small_indo->resize(0.3);
  small_indo->move(675, 300);
  small_indo->print(fb, window, 255, 0, 0, 0);
  fb.print_include(window_corner_a, window_corner_b);

  int zoom = 0;
  while(true){ 
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
      indo->move(-10,0);
    }
    else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
      indo->move(10,0);
    }
    else if (cmd == 'w' || cmd == 'W' || cmd == -1) {        
      indo->move(0,-10);
    }
    else if (cmd == 's' || cmd == 'S' || cmd == -2) {
      indo->move(0,10);
    }

    else if (cmd == 'q' || cmd == 'Q' ) {
      if(zoom < MAKS_ZOOM) {
        indo->resize(1.1);
        zoom++;
      }
    }
    else if (cmd == 'e' || cmd == 'E' ) {
      if(zoom > MIN_ZOOM) { 
        indo->resize(0.9);
        zoom--;
      }
    }
    fb.clear();
    indo->print(fb, new Belakang());
    fb.print_exclude(window_corner_a, window_corner_b);
    small_indo->print(fb, window, 255, 0, 0, 0);
    fb.print_include(window_corner_a, window_corner_b);
  }
  return 0;
}

