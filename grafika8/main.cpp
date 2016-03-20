#include "../lib/curve.h"
#include "../lib/polygon.h"
#include "../lib/line.h"
#include "../lib/conio2.h"
#include "objects/pln.h"
#include "objects/gedung.h"
#include "objects/perpus.h"
#include "objects/aulabarattimur.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
FrameBuffer fb;

int main(int argc, char const *argv[])
{
  int cmd = ' ';
  // fb.clear();
  system("clear");
  ITB* pp = new ITB();
  Point<double> center (512,560,200);
	//lantai satu
	//bawah
	pp->rotate(0,center,-140,0);
  while (1) {
	pp->print(fb);
	fb.print();
	cmd = getch();  
    fb.clear();
    system("clear");
      if (cmd == 'q' || cmd == 'Q') {
	        pp->rotate(0,center,-10,0);
	      }
      else if (cmd == 'w' || cmd == 'W') {
			pp->rotate(0,center,10,0);
		  }
      else if (cmd == 'p' || cmd == 'P') {
			  break;
		  }
      else if (cmd == 'a' || cmd == 'A') {        
			pp->rotate(10,center,0,0);
          }
      else if (cmd == 's' || cmd == 'S') {
			pp->rotate(-10,center,0,0);
		  }
      else if (cmd == 'z' || cmd == 'Z') {
			pp->rotate(0,center,0,10);
		  }
      else if (cmd == 'x' || cmd == 'X') {
			pp->rotate(0,center,0,-10);
		  }	 
      pp->print(fb);
      fb.print();
      fb.clear();
      usleep(75000);
    }
  return 0;
}
