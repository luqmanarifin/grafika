#include <bits/stdc++.h>
#include <unistd.h>

#include "../lib/curve.h"
#include "../lib/polygon.h"
#include "../lib/line.h"
#include "../lib/conio2.h"
#include "../lib/font.h"

#include "objects/pln.h"
#include "objects/gedung.h"
#include "objects/perpus.h"
#include "objects/aulabarattimur.h"

using namespace std;
FrameBuffer fb;

#define UJUNG_X 50
#define UJUNG_Y 100
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
  font.print(fb, "ALL", UJUNG_X, UJUNG_Y, FONT_SIZE, Color::WHITE);
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

int main() {
  int cmd = ' ';
  system("clear");
  
  print_all();
  while(1) {
    system("clear");
    fb.print();
    fb.clear();
    cmd = getch();
    if(cmd == 'y' || cmd == 'Y') {
      mode = (mode + 1) % 4;
      switch(mode) {
        case 0 : print_all(); break;
        case 1 : print_jalan(); break;
        case 2 : print_gedung(); break;
        case 3 : print_jalur_teduh(); break;
      }
    }
  }
  
  return 0;
}