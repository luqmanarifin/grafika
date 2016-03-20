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

#define UJUNG_X2 1100
#define UJUNG_Y2 100
#define FONT_SIZE 8
#define FONT_SIZE2 3

/**
 * 0 : all 
 * 1 : jalan
 * 2 : gedung
 */
int mode = 0;
Font font;
KumpulanKubus* kubus;
void print_all() {
  font.print(fb, "ALL ABOUT ITB", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

void print_jalan() {
  font.print(fb, "JALAN", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}

void print_gedung() {
  font.print(fb, "GEDUNG", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
}
void print_keterangan() {
  kubus->print(fb);
  font.print(fb, "STEI", UJUNG_X2, UJUNG_Y2, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FMIPA", UJUNG_X2, UJUNG_Y2+20, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FSRD", UJUNG_X2, UJUNG_Y2+40, FONT_SIZE2, Color::WHITE);
  font.print(fb, "SAPPK", UJUNG_X2, UJUNG_Y2+60, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FTTM", UJUNG_X2, UJUNG_Y2+80, FONT_SIZE2, Color::WHITE);
  font.print(fb, "SITH", UJUNG_X2, UJUNG_Y2+100, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FTI", UJUNG_X2, UJUNG_Y2+120, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FITB", UJUNG_X2, UJUNG_Y2+140, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FTMD", UJUNG_X2, UJUNG_Y2+160, FONT_SIZE2, Color::WHITE);
  font.print(fb, "FTSL", UJUNG_X2, UJUNG_Y2+180, FONT_SIZE2, Color::WHITE);
  font.print(fb, "SF", UJUNG_X2, UJUNG_Y2+200, FONT_SIZE2, Color::WHITE);
  font.print(fb, "SBM", UJUNG_X2, UJUNG_Y2+220, FONT_SIZE2, Color::WHITE);
  font.print(fb, "UMUM", UJUNG_X2, UJUNG_Y2+240, FONT_SIZE2, Color::WHITE);
  font.print(fb, "OTHER", UJUNG_X2, UJUNG_Y2+260, FONT_SIZE2, Color::WHITE);
}
int main(int argc, char const *argv[])
{
  int cmd = ' ';  
  kubus=new KumpulanKubus();
  Point<double> center (550,560,140);
  //fb.clear();
  system("clear");
  ITB* pp = new ITB();
	//lantai satu
	//bawah
	pp->rotate(0,center,-140,0);
	//pp->print(fb,mode);
  print_all();
  //fb.print();
  //fb.clear();
  print_keterangan();
  while (1) {
    	pp->print(fb,mode);
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
      else if (cmd == 'e' || cmd == 'E') {
			pp->resize(1.1);
		  }
      else if (cmd == 'r' || cmd == 'R') {
			pp->resize(0.9);
		  }	 
      else if (cmd == 'd' || cmd == 'D') {
			  int i=0;
			  while(i<18){
        	pp->print(fb,mode);
        	fb.print();
          fb.clear();
          system("clear");
			    pp->rotate(0,center,0,-10);
          switch(mode) {
            case 0 : print_all(); break;
            case 1 : print_jalan(); break;
            case 2 : print_gedung(); break;
          }    
          pp->print(fb,mode);
          fb.print();
          fb.clear();
          i++;
			  }
		  }	 
      else if(cmd == 'y' || cmd == 'Y') {
        mode = (mode + 1) % 3;
      }
      switch(mode) {
        case 0 : print_all(); break;
        case 1 : print_jalan(); break;
        case 2 : print_gedung(); break;
      }
      pp->print(fb,mode);
      print_keterangan();
      fb.print();
      fb.clear();
      usleep(75000);
    }
  return 0;
}
