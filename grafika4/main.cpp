#include "lib/polygon.h"
#include <iostream>
#include <unistd.h>
#include "lib/conio2.h"

#include "objects/baling.h"
#include "objects/belakang.h"
#include "objects/tanahijo.h"
#include "objects/jendela.h"
#include "objects/pesawat.h"
#include "objects/orang.h"
#include "objects/sijagur.h"
#include "objects/roda.h"
#include "objects/boom.h"
#include "objects/parachute.h"
using namespace std;
int targetx, tembakanx;
int boolrubah, booltembak=0,tertembak=0;
FrameBuffer fb;

inline int sign(int x) { return (x > 0) - (x < 0); }
void line(int x0, int y0, int x1, int y1,int red, int green, int blue )
{
  
  int deltax = x1 - x0;
  int adx = abs(deltax);
  int dx = sign(deltax);

  int deltay = y1 - y0;
  int ady = abs(deltay);
  int dy = sign(deltay);
  fb.set(x0,y0,red,green,blue,0);
  if (adx < ady) {
    int D = 2 * adx - ady;
    int x = x0;
    if (D > 0) {
      x += dx;
      D -= 2 * ady;
    }

    for (int y = y0 + dy; y != y1; y += dy) {
      fb.set(x,y,red,green,blue,0);
      D += 2 * adx;
      while (D > 0) {
        x += dx;
        D -= 2 * ady;
      }
    }
  }
  else {
    int D = 2 * ady - adx;    
    int y = y0;
    if (D > 0) {
      y += dy;
      D -= 2 * adx;
    }

    for (int x = x0 + dx; x != x1; x += dx) {
      fb.set(x,y,red,green,blue,0);
      D += 2 * ady;
      while (D > 0) {
        y += dy;
        D -= 2 * adx;
      }
    }
  }
}

Pesawat* p = new Pesawat();
void *inc_x(void *x_void_ptr)
{    
  
  int cmd = ' ';
  while(tertembak==0){
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
       if(targetx>tembakanx-20)
       targetx-=10;
       boolrubah=1;
     }
     else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
       if(targetx<tembakanx+130)
       targetx+=10;
       boolrubah=1;
     }
     else if (cmd == 'q' || cmd == 'q' || cmd == -1) {
       if(tembakanx>50){
        tembakanx-=10;
        if(targetx>50)
          targetx-=10;
       }
       boolrubah=1;
     }
     else if (cmd == 'e' || cmd == 'E' || cmd == -2) {
       if(tembakanx<650){
        if(targetx<650)
          targetx+=10;
        tembakanx+=10;
       }
       boolrubah=1;
     }
     else if (cmd == 's' || cmd == 'S' ) {
       booltembak=1;
       if(p->MinX()<targetx && targetx<p->MaxX()){
            tertembak=1;
            break;
        }
     }

  }
  /* the function must return something - NULL will do */
  return NULL;

}

int main() {
  system("clear");
  SiJagur* meriam = new SiJagur();
  meriam->resizes(0.25);
  targetx = 340;
  tembakanx = 340;
  boolrubah=0;
  meriam->move(0,225);
  int waktutembak=0;
  int x=0;
  int temp = tembakanx;
  Baling* p2 = new Baling();
  Baling* p3 = new Baling();
  pthread_t inc_x_thread;
  if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
      fprintf(stderr, "Error creating thread\n");
      return 1;

  }
  Belakang* bel = new Belakang();
  TanahIjo* ijo = new TanahIjo();
  while(tertembak==0){
    p = new Pesawat();
    p2 = new Baling();
    p3 = new Baling();
    float alpa = 1;
    p->resizes(0.25);
    p2->resizes(0.05);
    p->move(150,-200);
    p2->move(200,-215);
    p3->resizes(0.05);
    p3->move(100,-215);
    int hitung = 1;
    int selesai=0;
    while(selesai<10){
      if(boolrubah==1){
        meriam->move(tembakanx-temp,0);
        temp=tembakanx;
        boolrubah=0;
      }
      bel->print(fb,0,174,239,alpa);
      ijo->print(fb,54,218,22,alpa);
      if(hitung == 3){
        p->resizes(1.1);
        p2->resizes(1.03);
        //p2->resizes(1.15);
        p2->move(6,1);    
        p3->resizes(1.03);
        //p3->resizes(1.15);
        p3->move(-6,1);
        hitung=1;
        selesai++;
      }
      p2->rotates(10);
      p3->rotates(10);
      p->print(fb,252,222,138,alpa);
      p2->print(fb,0,0,0,alpa);
      p3->print(fb,0,0,0,alpa);
      if(booltembak==1){
        for(int j=tembakanx-19;j<tembakanx+19;j++)
          line(j+54,700,targetx+j-tembakanx,0,190,26,31); 
         for(int j=tembakanx-10;j<tembakanx+10;j++)
          line(j+54,700,targetx+j-tembakanx,0,235,215,0); 
        waktutembak++;
        if(waktutembak==6){
          booltembak=0;
          waktutembak=0;
          if(tertembak==1)
            break;
        }
      }
      else{
        for(int j=tembakanx-3;j<tembakanx+3;j++)
          line(targetx+j-tembakanx,70,targetx+j-tembakanx,77,173,26,31); 
       }
      meriam->print(fb,192,192,192,alpa);
      usleep(50000);
      hitung++;
      alpa +=5;
      fb.print();
    }
    fb.print();
  }
  Boom* boom = new Boom();
  Boom* boom2 = new Boom();
  Parachute* parasut = new Parachute();
  Orang* orang = new Orang();
  Roda* ban = new Roda();
  boom->resizes(0.3);
  boom->move(150,-140);
  parasut->resizes(0.1);
  parasut->move(-30,-200);
  ban->resizes(0.1);
  ban->move(-100,-200);
  orang->resizes(0.2);
  orang->move(-30,-260);
  boom2->resizes(0.25);
  boom2->move(150,-140);
  bel->print(fb,0,174,239,0);
  ijo->print(fb,54,218,22,0);
  boom->print(fb,190,26,31,0);
  boom2->print(fb,235,215,0,0);
  usleep(1000000);
  int g=10;
  float mutar=70;
  int buatputar=0;
  int kount=1;
  
  int tinggi=525-ban->MaxY();
  int tahap=1;
  while(true){
    bel->print(fb,0,174,239,0);
    ijo->print(fb,54,218,22,0);
    parasut->print(fb,255,255,255,0);
    orang->print(fb,220,20,60,0);
    if(ban->MaxY()<575&&tahap==1){
      if(tinggi<300)
      ban->move(-3,g/10);
      else
      ban->move(0,g/10);
      g+=10;
    }
    else if(tahap==1&&ban->MaxY()>=575){
      tahap++;
      tinggi=tinggi/1.5;
      if(tinggi<10){
        tahap=0;
        break;
      }
    }
    if(ban->MaxY()>575-tinggi&&tahap==2){
      ban->move(-3,-g/10);
      g-=10;
    }
    else if(tahap==2&&ban->MaxY()<=575-tinggi){
      tahap--;
      
    }
    if(orang->MaxY()<570){
      orang->move(0,5);
      parasut->move(0,5);
      if(buatputar==-5){
        kount=-1;
      }
      else if(buatputar==5){
        kount=1;
      }
      if(kount==-1){
         orang->rotate(-4,Point((parasut->MinX()+parasut->MaxX())/2,parasut->MinY()));
         parasut->rotate(-4, Point((parasut->MinX()+parasut->MaxX())/2,parasut->MinY()));
         buatputar++;
      }
      else if(kount==1){
        orang->rotate(4,Point((parasut->MinX()+parasut->MaxX())/2,parasut->MinY()));
        parasut->rotate(4,Point((parasut->MinX()+parasut->MaxX())/2,parasut->MinY()));
        buatputar--;
      }
    }
    if(p3->MaxY()<525 && mutar>0){
      p3->move(0,g/10);
      p3->rotates(mutar);
      p2->move(0,g/10);
      p2->rotates(mutar);
      mutar-=2;
    }
    ban->print(fb,0,0,0,0);
    p2->print(fb,0,0,0,0);
    p3->print(fb,0,0,0,0);
    fb.print();
    usleep(50000);
  }
  fb.clear();
  return 0;
}

