#include <unistd.h>
#include <bits/stdc++.h>

#include <curve.h>
#include <polygon.h>
#include <line.h>
#include <conio2.h>

#include "objects/wajah.h"

using namespace std;
FrameBuffer fb;

int main(int argc, char const *argv[])
{
  int cmd = ' ';
  // fb.clear();
  system("clear");
  Wajah* erz = new Wajah();
  Hidung1* hid = new Hidung1();
  hid->move(400,0);
  erz->move(400,0);
  erz->print(fb);
  hid->print(fb);
  fb.print();
  while (true) { 
       cmd = getch();
       if (cmd == 27) {
        cmd = getch();
        if (cmd == 27) {
          break;
        }
        else  {
          cmd = getch();
        cmd = 64 - cmd;
        }
       }
      if (cmd == 'a' || cmd == 'A' || cmd == -4) {
         erz->jadibiasa();
       }
       else if (cmd == 's' || cmd == 'S' || cmd == -3) {
         erz->jadisenyum();
       }
       else if (cmd == 'd' || cmd == 'D' || cmd == -1) {        
         erz->jadisedih();
       }
       else if (cmd == 'f' || cmd == 'F' || cmd == -1) {        
         erz->jadimerem();
       }
       else if (cmd == 'g' || cmd == 'G' || cmd == -1) {        
         erz->jaditertawa();
       }
       erz->print(fb);
       hid->print(fb);
       system("clear");
       fb.print();
       fb.clear();
  
   }
   
  return 0;
}
