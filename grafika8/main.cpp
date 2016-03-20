#include "../lib/curve.h"
#include "../lib/font.h"
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

#define UJUNG_X 400
#define UJUNG_Y 50
#define FONT_SIZE 8

/**
 * 0 : all 
 * 1 : jalan
 * 2 : gedung
 * 3 : jalur teduh
 */
int mode = 0;
Font font;

void print_all() {
  font.print(fb, "ALL ABOUT ITB", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

void print_jalan() {
  font.print(fb, "JALAN", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

void print_gedung() {
  font.print(fb, "GEDUNG", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

void print_jalur_teduh() {
  font.print(fb, "JALUR TEDUH", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

int main(int argc, char const *argv[])
{
  int cmd = ' ';
  // fb.clear();
  system("clear");
  ITB* pp = new ITB();
	//lantai satu
	//bawah
	pp->rotate(0,Point<double>(512,400,-200),-140,0);
  print_all();
  while (1) {
  	pp->print(fb);
  	fb.print();
  	cmd = getch();  
    fb.clear();
    system("clear");
      if (cmd == 'q' || cmd == 'Q') {
	        pp->rotate(0,Point<double>(512,400,-200),-10,0);
	      }
      else if (cmd == 'w' || cmd == 'W') {
			pp->rotate(0,Point<double>(512,400,-200),10,0);
		  }
      else if (cmd == 'p' || cmd == 'P') {
			  break;
		  }
      else if (cmd == 'a' || cmd == 'A') {        
			pp->rotate(10,Point<double>(512,400,-200),0,0);
          }
      else if (cmd == 's' || cmd == 'S') {
			pp->rotate(-10,Point<double>(512,400,-200),0,0);
		  }
      else if (cmd == 'z' || cmd == 'Z') {
			pp->rotate(0,Point<double>(512,400,-200),0,10);
		  }
      else if (cmd == 'x' || cmd == 'X') {
			pp->rotate(0,Point<double>(512,400,-200),0,-10);
		  }
      else if(cmd == 'y' || cmd == 'Y') {
        mode = (mode + 1) % 4;
        switch(mode) {
          case 0 : print_all(); break;
          case 1 : print_jalan(); break;
          case 2 : print_gedung(); break;
          case 3 : print_jalur_teduh(); break;
        }
      }
      pp->print(fb);
      fb.print();
      fb.clear();
      usleep(75000);
    }
  return 0;
}
