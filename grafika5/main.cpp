#include "lib/polygon.h"
#include <iostream>
#include <unistd.h>
#include "lib/conio2.h"

#include "objects/Indonesia.h"

using namespace std;

FrameBuffer fb;

int main() {  
  system("clear");
  int cmd = ' ';
  Indonesia* indo = new Indonesia();
  indo->print(fb);
  fb.print();
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
        indo->resize(1.1);
     }
     else if (cmd == 'e' || cmd == 'E' ) {
        indo->resize(0.9);
     }
     indo->print(fb);
    //Halmahera2* ambon = new Halmahera2();
    fb.print();
    usleep(50000);
  }
  return 0;
}

