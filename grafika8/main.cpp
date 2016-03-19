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
  AulaBaratTimur* pp = new AulaBaratTimur();
	//lantai satu
	//bawah
	
  while (1) {
	pp->print(fb);
	fb.print();
	cmd = getch();  
    fb.clear();
    system("clear");
      if (cmd == 'q' || cmd == 'Q') {
	        pp->rotate(0,Point<double>(425,275,25),-1,0);
	      }
      else if (cmd == 'w' || cmd == 'W') {
			pp->rotate(0,Point<double>(425,275,25),1,0);
		  }
      else if (cmd == 'a' || cmd == 'A') {        
			pp->rotate(1,Point<double>(425,275,25),0,0);
          }
      else if (cmd == 's' || cmd == 'S') {
			pp->rotate(-1,Point<double>(425,275,25),0,0);
		  }
      else if (cmd == 'z' || cmd == 'Z') {
			pp->rotate(0,Point<double>(425,275,25),0,1);
		  }
      else if (cmd == 'x' || cmd == 'X') {
			pp->rotate(0,Point<double>(425,275,25),0,-1);
		  }	 
      pp->print(fb);
      fb.print();
      fb.clear();
      usleep(75000);
    }
  return 0;
}
