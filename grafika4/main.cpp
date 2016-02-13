#include "lib/polygon.h"
#include <iostream>
#include "lib/conio2.h"
#include <unistd.h>
using namespace std;
int targetx, tembakanx;
int boolrubah, booltembak=0,tertembak=0;
FrameBuffer fb;
Polygon* printBaling(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(400,350));
    pol->addPoint(Point(634,493));
    pol->addPoint(Point(664,406));
    pol->addPoint(Point(444,275));
    pol->addPoint(Point(450,0));
    pol->addPoint(Point(350,0));
    pol->addPoint(Point(356,275));
    pol->addPoint(Point(115,406));
    pol->addPoint(Point(150,493));
    return pol;
}
Polygon* printBelakang(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0,0));
    pol->addPoint(Point(0,600));
    pol->addPoint(Point(800,600));
    pol->addPoint(Point(800,0));
    return pol;
}

Polygon* printTanahIjo(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(0,500));
    pol->addPoint(Point(0,600));
    pol->addPoint(Point(800,600));
    pol->addPoint(Point(800,500));
    return pol;
}

Polygon* printJendela(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(350,280));
    pol->addPoint(Point(450,280));
    pol->addPoint(Point(450,320));
    pol->addPoint(Point(350,320));
    return pol;
}

Polygon* printPesawat(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(450,200));
    pol->addPoint(Point(460,200));
    pol->addPoint(Point(460,210));
    pol->addPoint(Point(470,210));
    pol->addPoint(Point(470,220));
    pol->addPoint(Point(480,220));
    pol->addPoint(Point(480,230));
    pol->addPoint(Point(490,230));
    pol->addPoint(Point(490,240));
    pol->addPoint(Point(500,240));
    pol->addPoint(Point(500,250));
    pol->addPoint(Point(500,290));
    pol->addPoint(Point(750,290));
    pol->addPoint(Point(750,300));
    pol->addPoint(Point(700,300));
    pol->addPoint(Point(700,310));
    pol->addPoint(Point(500,310));
    pol->addPoint(Point(500,350));
    pol->addPoint(Point(500,360));
    pol->addPoint(Point(490,360));
    pol->addPoint(Point(490,370));
    pol->addPoint(Point(480,370));
    pol->addPoint(Point(480,380));
    pol->addPoint(Point(470,380));
    pol->addPoint(Point(470,390));
    pol->addPoint(Point(460,390));
    pol->addPoint(Point(460,400));
    pol->addPoint(Point(450,400));
    pol->addPoint(Point(350,400));
    pol->addPoint(Point(340,400));
    pol->addPoint(Point(340,390));
    pol->addPoint(Point(330,390));
    pol->addPoint(Point(330,380));
    pol->addPoint(Point(320,380));
    pol->addPoint(Point(320,370));
    pol->addPoint(Point(310,370));
    pol->addPoint(Point(310,360));
    pol->addPoint(Point(300,360));
    pol->addPoint(Point(300,350));
    pol->addPoint(Point(300,310));
    pol->addPoint(Point(100,310));
    pol->addPoint(Point(100,300));
    pol->addPoint(Point(50,300));
    pol->addPoint(Point(50,290));
    pol->addPoint(Point(300,290));
    pol->addPoint(Point(300,250));
    pol->addPoint(Point(300,240));
    pol->addPoint(Point(310,240));
    pol->addPoint(Point(310,230));
    pol->addPoint(Point(320,230));
    pol->addPoint(Point(320,220));
    pol->addPoint(Point(330,220));
    pol->addPoint(Point(330,210));
    pol->addPoint(Point(340,210));
    pol->addPoint(Point(340,200));
    pol->addPoint(Point(350,200));
    pol->addPoint(Point(390,200));
    pol->addPoint(Point(390,140));
    pol->addPoint(Point(395,140));
    pol->addPoint(Point(395,100));
    pol->addPoint(Point(405,100));
    pol->addPoint(Point(405,140));
    pol->addPoint(Point(410,140));
    pol->addPoint(Point(410,200));
    return pol;
}

Polygon* printOrang(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(412,300));
    pol->addPoint(Point(420,300));
    pol->addPoint(Point(420,308));
    pol->addPoint(Point(428,308));
    pol->addPoint(Point(428,316));
    pol->addPoint(Point(437,316));
    pol->addPoint(Point(437,325));
    pol->addPoint(Point(437,350));
    pol->addPoint(Point(437,358));
    pol->addPoint(Point(429,358));
    pol->addPoint(Point(429,366));
    pol->addPoint(Point(421,366));
    pol->addPoint(Point(421,375));
    pol->addPoint(Point(412,375));
    pol->addPoint(Point(454,375));
    pol->addPoint(Point(454,385));
    pol->addPoint(Point(462,385));
    pol->addPoint(Point(462,467));
    pol->addPoint(Point(464,467));
    pol->addPoint(Point(464,490));
    pol->addPoint(Point(443,490));
    pol->addPoint(Point(443,467));
    pol->addPoint(Point(445,467));
    pol->addPoint(Point(445,400));
    pol->addPoint(Point(437,400));
    pol->addPoint(Point(437,590));
    pol->addPoint(Point(445,590));
    pol->addPoint(Point(445,600));
    pol->addPoint(Point(410,600));
    pol->addPoint(Point(410,520));
    pol->addPoint(Point(400,510));
    pol->addPoint(Point(390,520));
    pol->addPoint(Point(390,600));
    pol->addPoint(Point(355,600));
    pol->addPoint(Point(355,590));
    pol->addPoint(Point(363,590));
    pol->addPoint(Point(363,400));
    pol->addPoint(Point(355,400));
    pol->addPoint(Point(355,467));
    pol->addPoint(Point(357,467));
    pol->addPoint(Point(357,490));
    pol->addPoint(Point(336,490));
    pol->addPoint(Point(336,467));
    pol->addPoint(Point(336,467));
    pol->addPoint(Point(338,467));
    pol->addPoint(Point(338,385));
    pol->addPoint(Point(346,385));
    pol->addPoint(Point(346,375));
    pol->addPoint(Point(354,375));
    pol->addPoint(Point(392,375));
    pol->addPoint(Point(383,375));
    pol->addPoint(Point(374,375));
    pol->addPoint(Point(374,366));
    pol->addPoint(Point(366,366));
    pol->addPoint(Point(366,358));
    pol->addPoint(Point(358,358));
    pol->addPoint(Point(358,350));
    pol->addPoint(Point(358,325));
    pol->addPoint(Point(358,316));
    pol->addPoint(Point(366,316));
    pol->addPoint(Point(366,308));
    pol->addPoint(Point(374,308));
    pol->addPoint(Point(374,300));
    return pol;
}
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


Polygon* p = printPesawat();
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

Polygon* printpeluru(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(300,600));
    pol->addPoint(Point(500,600));
    pol->addPoint(Point(500,200));
    pol->addPoint(Point(550,200));
    pol->addPoint(Point(450,0));
    pol->addPoint(Point(350,0));
    pol->addPoint(Point(250,200));
    pol->addPoint(Point(300,200));
    return pol;
}

Polygon* printsijagur(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(800,600));
    pol->addPoint(Point(800,500));
    pol->addPoint(Point(700,500));
    pol->addPoint(Point(700,300));
    pol->addPoint(Point(600,300));
    pol->addPoint(Point(600,0));
    pol->addPoint(Point(500,0));
    pol->addPoint(Point(500,200));
    pol->addPoint(Point(300,200));
    pol->addPoint(Point(300,0));
    pol->addPoint(Point(200,0));
    pol->addPoint(Point(200,500));
    pol->addPoint(Point(200,300));
    pol->addPoint(Point(100,300));
    pol->addPoint(Point(100,500));
    pol->addPoint(Point(0,500));
    pol->addPoint(Point(0,600));
    return pol;
}

Polygon* printroda(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(325,90));
    pol->addPoint(Point(475,90));
    pol->addPoint(Point(475,120));
    pol->addPoint(Point(535,120));
    pol->addPoint(Point(535,150));
    pol->addPoint(Point(565,150));
    pol->addPoint(Point(565,180));
    pol->addPoint(Point(595,180));
    pol->addPoint(Point(595,210));
    pol->addPoint(Point(625,210));
    pol->addPoint(Point(625,270));
    pol->addPoint(Point(655,270));
    pol->addPoint(Point(655,420));
    pol->addPoint(Point(625,420));
    pol->addPoint(Point(625,480));
    pol->addPoint(Point(595,480));
    pol->addPoint(Point(595,510));
    pol->addPoint(Point(565,510));
    pol->addPoint(Point(565,540));
    pol->addPoint(Point(535,540));
    pol->addPoint(Point(535,570));
    pol->addPoint(Point(475,570));
    pol->addPoint(Point(475,600));
    pol->addPoint(Point(325,600));
    pol->addPoint(Point(325,570));
    pol->addPoint(Point(265,570));
    pol->addPoint(Point(265,540));
    pol->addPoint(Point(235,540));
    pol->addPoint(Point(235,510));
    pol->addPoint(Point(205,510));
    pol->addPoint(Point(205,480));
    pol->addPoint(Point(175,480));
    pol->addPoint(Point(175,420));
    pol->addPoint(Point(145,420));
    pol->addPoint(Point(145,270));
    pol->addPoint(Point(175,270));
    pol->addPoint(Point(175,210));
    pol->addPoint(Point(205,210));
    pol->addPoint(Point(205,180));
    pol->addPoint(Point(235,180));
    pol->addPoint(Point(235,150));
    pol->addPoint(Point(265,150));
    pol->addPoint(Point(265,120));
    pol->addPoint(Point(325,120));
    pol->addPoint(Point(325,390));
    pol->addPoint(Point(355,390));
    pol->addPoint(Point(355,420));
    pol->addPoint(Point(445,420));
    pol->addPoint(Point(445,390));
    pol->addPoint(Point(475,390));
    pol->addPoint(Point(475,300));
    pol->addPoint(Point(445,300));
    pol->addPoint(Point(445,270));
    pol->addPoint(Point(355,270));
    pol->addPoint(Point(355,300));
    pol->addPoint(Point(325,300));
    return pol;
}

Polygon* printboom(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(126,468));
    pol->addPoint(Point(126,288));
    pol->addPoint(Point(144,288));
    pol->addPoint(Point(144,270));
    pol->addPoint(Point(126,270));
    pol->addPoint(Point(126,252));
    pol->addPoint(Point(90,252));
    pol->addPoint(Point(90,270-54));//paling kiri
    pol->addPoint(Point(126,270-54));
    pol->addPoint(Point(126,252-54));
    pol->addPoint(Point(180,252-54));
    pol->addPoint(Point(180,234-54));
    pol->addPoint(Point(162,234-54));
    pol->addPoint(Point(162,216-54));
    pol->addPoint(Point(144,216-54));
    pol->addPoint(Point(144,198-54));
    pol->addPoint(Point(126,198-54));
    pol->addPoint(Point(126,180-54));
    pol->addPoint(Point(198,180-54));
    pol->addPoint(Point(198,144-54));
    pol->addPoint(Point(180,144-54));
    pol->addPoint(Point(180,108-54));
    pol->addPoint(Point(162,108-54));
    pol->addPoint(Point(162,72-54));
    pol->addPoint(Point(198,72-54));//pojok kiri atas
    pol->addPoint(Point(198,90-54));
    pol->addPoint(Point(216,90-54));
    pol->addPoint(Point(216,108-54));
    pol->addPoint(Point(252,108-54));
    pol->addPoint(Point(252,126-54));
    pol->addPoint(Point(270,126-54));
    pol->addPoint(Point(270,144-54));
    pol->addPoint(Point(306,144-54));
    pol->addPoint(Point(306,108-54));
    pol->addPoint(Point(288,108-54));
    pol->addPoint(Point(288,54-54));
    pol->addPoint(Point(306,54-54));//paling atas
    pol->addPoint(Point(306,72-54));
    pol->addPoint(Point(324,72-54));
    pol->addPoint(Point(324,90-54));
    pol->addPoint(Point(342,90-54));
    pol->addPoint(Point(342,108-54));
    pol->addPoint(Point(360,108-54));
    pol->addPoint(Point(360,72-54));
    pol->addPoint(Point(378,72-54));
    pol->addPoint(Point(378,108-54));
    pol->addPoint(Point(396,108-54));
    pol->addPoint(Point(396,126-54));
    pol->addPoint(Point(414,126-54));
    pol->addPoint(Point(414,144-54));
    pol->addPoint(Point(450,144-54));
    pol->addPoint(Point(450,126-54));
    pol->addPoint(Point(486,126-54));
    pol->addPoint(Point(486,108-54));
    pol->addPoint(Point(594,108-54));//pojok kanan panjang
    pol->addPoint(Point(594,126-54));
    pol->addPoint(Point(612,126-54));
    pol->addPoint(Point(612,144-54));
    pol->addPoint(Point(630,144-54));
    pol->addPoint(Point(630,180-54));
    pol->addPoint(Point(648,180-54));
    pol->addPoint(Point(648,234-54));
    pol->addPoint(Point(666,234-54));
    pol->addPoint(Point(666,270-54));
    pol->addPoint(Point(684,270-54));
    pol->addPoint(Point(684,306-54));//kiri pertama    
	pol->addPoint(Point(666,306-54));
	pol->addPoint(Point(666,324-54));
	pol->addPoint(Point(684,324-54));
	pol->addPoint(Point(684,360-54));
	pol->addPoint(Point(666,360-54));
	pol->addPoint(Point(666,378-54));
	pol->addPoint(Point(684,378-54));
	pol->addPoint(Point(684,396-54));
	pol->addPoint(Point(666,396-54));
	pol->addPoint(Point(666,414-54));
	pol->addPoint(Point(648,414-54));
	pol->addPoint(Point(648,468-54));
	pol->addPoint(Point(666,468-54));
	pol->addPoint(Point(666,486-54));
	pol->addPoint(Point(684,486-54));
	pol->addPoint(Point(684,522-54));
	pol->addPoint(Point(666,522-54));
	pol->addPoint(Point(666,540-54));
	pol->addPoint(Point(648,540-54));
	pol->addPoint(Point(648,558-54));
	pol->addPoint(Point(666,558-54));
	pol->addPoint(Point(666,594-54));
	pol->addPoint(Point(684,594-54));
	pol->addPoint(Point(684,612-54));//pojok kanan bawah
	pol->addPoint(Point(666,558));
	pol->addPoint(Point(666,540));
	pol->addPoint(Point(630,540));
	pol->addPoint(Point(630,558));
	pol->addPoint(Point(450,558));
	pol->addPoint(Point(450,540));
	pol->addPoint(Point(432,540));
	pol->addPoint(Point(432,558));
	pol->addPoint(Point(252,558));
	return pol;
}

Polygon* printparachute(){
    Polygon* pol = new Polygon();
    pol->addPoint(Point(75,350));
    pol->addPoint(Point(25,400));
    pol->addPoint(Point(0,200));
    pol->addPoint(Point(50,150));
    pol->addPoint(Point(200,100));
    pol->addPoint(Point(600,100));
    pol->addPoint(Point(750,150));
    pol->addPoint(Point(800,200));
    pol->addPoint(Point(775,400));
    pol->addPoint(Point(725,350));
    pol->addPoint(Point(575,300));
    pol->addPoint(Point(550,600));
    pol->addPoint(Point(525,600));
    pol->addPoint(Point(550,300));
    pol->addPoint(Point(250,300));
    pol->addPoint(Point(275,600));
    pol->addPoint(Point(250,600));
    pol->addPoint(Point(225,300));
    return pol;
}

int main() {
  system("clear");
  Polygon* meriam = printsijagur();
  meriam->resizes(0.25);
  targetx = 340;
  tembakanx = 340;
  boolrubah=0;
  meriam->move(0,225);
  int waktutembak=0;
  int x=0;
  int temp = tembakanx;
  Polygon* p2 = printBaling();
  Polygon* p3 = printBaling();
  pthread_t inc_x_thread;
  if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
      fprintf(stderr, "Error creating thread\n");
      return 1;

  }
  while(tertembak==0){
    p = printPesawat();
    p2 = printBaling();
    p3 = printBaling();
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
      printBelakang()->print(fb,0,174,239,alpa);
      printTanahIjo()->print(fb,54,218,22,alpa);
      if(hitung == 3){
        p->resizes(1.1);
        p2->resizes(1.15);
        p2->move(6,1);    
        p3->resizes(1.15);
        p3->move(-6,1);
        hitung=1;
        selesai++;
      }
      p2->rotates(10);
      p3->rotates(10);
      p->print(fb,252,222,138,alpa);
      //p1->print(fb,0,0,0,0);
      p2->print(fb,0,0,0,alpa);
      p3->print(fb,0,0,0,alpa);
      if(booltembak==1){
        for(int j=tembakanx-19;j<tembakanx+19;j++)
          line(j+54,700,targetx+j-tembakanx,0,190,26,31); 
         for(int j=tembakanx-10;j<tembakanx+10;j++)
          line(j+54,700,targetx+j-tembakanx,0,235,215,0); 
        waktutembak++;
        if(waktutembak==2){
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
      usleep(100000);
      hitung++;
      alpa +=5;
    }
    usleep(100000);
  }
  Polygon* boom = printboom();
  Polygon* boom2 = printboom();
  Polygon* parasut = printparachute();
  Polygon* orang = printOrang();
  Polygon* ban = printroda();
  boom->resizes(0.3);
  boom->move(150,-140);
  parasut->resizes(0.1);
  parasut->move(0,-200);
  ban->resizes(0.1);
  ban->move(-100,-200);
  orang->resizes(0.2);
  orang->move(0,-260);
  boom2->resizes(0.25);
  boom2->move(150,-140);
  printBelakang()->print(fb,0,174,239,0);
  printTanahIjo()->print(fb,54,218,22,0);
  boom->print(fb,190,26,31,0);
  boom2->print(fb,235,215,0,0);
  usleep(500000);
  int g=10;
  float mutar=10;
  int buatputar=0;
  int kount=1;
  
  int tinggi=525-ban->MaxY();
  int tahap=1;
  while(true){
    printBelakang()->print(fb,0,174,239,0);
    printTanahIjo()->print(fb,54,218,22,0);
    parasut->print(fb,255,255,255,0);
    orang->print(fb,220,20,60,0);
    
    if(ban->MaxY()<525&&tahap==1){
      ban->move(0,g/10);
      g+=10;
    }
    else if(tahap==1&&ban->MaxY()>=525){
      tahap++;
      tinggi=tinggi/3;
      if(tinggi<10){
        break;
      }
    }
    if(ban->MaxY()>525-tinggi&&tahap==2){
      ban->move(0,-g/10);
      g-=10;
    }
    else if(tahap==2&&ban->MaxY()<=525-tinggi){
      tahap--;
      tinggi=tinggi/3;
    }
    if(orang->MaxY()<525){
      orang->move(0,10);
      parasut->move(0,10);
      if(buatputar==-5){
        kount=-1;
        orang->resizes(1.3);
        parasut->resizes(1.3);
      }
      else if(buatputar==5){
        kount=1;
        orang->resizes(1.3);
        parasut->resizes(1.3);
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
      p3->move(0,g/4);
      p3->rotates(mutar);
      p3->resizes(1.05);
      p2->move(0,g/4);
      p2->rotates(mutar);
      p2->resizes(1.05);
      mutar-=0.25;
    }
    ban->print(fb,0,0,0,0);
    p2->print(fb,0,0,0,0);
    p3->print(fb,0,0,0,0);
    usleep(500000);
  }
  fb.clear();
  return 0;
  //printBaling()->print(fb);
  //run();
}

