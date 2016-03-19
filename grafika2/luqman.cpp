#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/conio2.h"
//#include "../lib/bitmap.h"
#include "../lib/framebuffer.h"
#include "../lib/point.h"
#include <pthread.h>
using namespace std;
int px,py;
FrameBuffer fb;
int targetx,tembakanx;
int width, height;
vector<Point> dotLine, dotShip;

/* set warna pada koordinat tertentu (x, y) */
void setWarna(int x, int y) {
  fb.set(x, y, 100, 15+(x-100)/2, 200-(y-100)/5, 0);
} 
/**
 * MULAI ICAL EDIT
 */
/* mengembalikan sign dari suatu angka */
inline int sign(int x) { return (x > 0) - (x < 0); }

/* membentuk garis dari koordinat (x0, y0) sampai (x1, y1) */
void line(int x0, int y0, int x1, int y1)
{
  int deltax = x1 - x0;
  int adx = abs(deltax);
  int dx = sign(deltax);

  int deltay = y1 - y0;
  int ady = abs(deltay);
  int dy = sign(deltay);

  setWarna(x0, y0);
  dotLine.push_back(Point(x0, y0));
  if (adx < ady) {
    int D = 2 * adx - ady;
    int x = x0;
    if (D > 0) {
      x += dx;
      D -= 2 * ady;
    }

    for (int y = y0 + dy; y != y1; y += dy) {
      setWarna(x, y);
      dotLine.push_back(Point(x, y));
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
      setWarna(x, y);
      dotLine.push_back(Point(x, y));
      D += 2 * ady;
      while (D > 0) {
        y += dy;
        D -= 2 * adx;
      }
    }
  }
}
/**
 * AKHIR
 */

/* membentuk gambar kapal */
void fun1(int px, int py) {
  int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
    i++;
    for (x = 100; x < 1000; x++) {
      
      if(y>=160&&y<=200&&x>=160&&x<=240){
        setWarna(px+x,py+y);
        dotShip.push_back(Point(px+x,py+y));
      }
      if(x>=240&&x<=290-(i-60)&&i<105&&y>=160){
          setWarna(px+x,py+y);
          dotShip.push_back(Point(px+x,py+y));
      }
      if(x>=110+(i-60)&&x<=160&&i<110&&y<=200&&y>=160){
          setWarna(px+x,py+y);
          dotShip.push_back(Point(px+x,py+y));
      }
      
    }
  }
}

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{    
  int cmd = ' ';
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
     else {
       if (cmd == 'a' || cmd == 'A' || cmd == -4) {
         if(targetx>0)
         targetx-=10;
       }
       else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
         if(targetx<1366)
         targetx+=10;
       }
       else if (cmd == 'q' || cmd == 'Q' || cmd == -1) {
         if(tembakanx>0)
         tembakanx-=10;
       }
       else if (cmd == 'e' || cmd == 'E' || cmd == -2) {
         if(tembakanx<1366)
         tembakanx+=10;
       }
       fb.clear(dotLine);
       line(tembakanx,height -100,targetx,-40);
   }

  }
  /* the function must return something - NULL will do */
  return NULL;

}



int main(int argc, char** argv) {
  // screen size
  width = fb.getXSize();
  height = fb.getYSize();

  // position for color pallette
  px = width, py = -20;
  int x=0;
  int position = 0, mode = 0;
  targetx = width/2,tembakanx = width/2;
  // tampilkan informasi
  system("clear");
  puts("Tekan wsda/arrow key untuk mengubah arah.");
  // puts("Tekan enter untuk masuk mode memilih warna.");
  // puts("Tekan escape 2 kali untuk keluar.");
  // puts("Pada mode memilih warna:");
  // puts("- Tekan wsda/arrow key untuk mengubah warna.");
  // puts("- Tekan enter untuk mengetahui warna pada titik tersebut.");
 
  pthread_t inc_x_thread;
  if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {

      fprintf(stderr, "Error creating thread\n");
      return 1;

  }

  while (true)
  {
    //fb.refresh();
    fun1(px,py);
    // baca piilhan
    px--;
    if(px<-100){
      px= fb.getXSize();
    }
    fb.clear(dotShip);
  }
  return 0;
}
