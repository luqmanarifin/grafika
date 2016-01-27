#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/conio2.h"
//#include "lib/bitmap.h"
#include "lib/framebuffer.h"
#include <pthread.h>
using namespace std;
int px,py;
FrameBuffer fb;
int targetx,tembakanx;
void borderedRectangle(int x1, int y1, int x2, int y2, 
  Color p = Color::WHITE, int width = 1) 
{
  for (int x = x1; x <= x2; ++x) {
    for (int y = -width; y <= width; ++y) {
      fb.set(x, y1 + y, p);
      fb.set(x, y2 + y, p);
    }
  }
  for (int y = y1; y <= y2; ++y) {
    for (int x = -width; x <= width; ++x) {
      fb.set(x + x1, y, p);
      fb.set(x + x2, y, p);
    }
  }
}

void setWarna(int x, int y) {
  fb.set(x, y, 100, 15+(x-100)/2, 200-(y-100)/5, 0);
} 
/**
 * MULAI ICAL EDIT
 */
inline int sign(int x) { return (x > 0) - (x < 0); }
void line(int x0, int y0, int x1, int y1)
{
  int deltax = x1 - x0;
  int adx = abs(deltax);
  int dx = sign(deltax);

  int deltay = y1 - y0;
  int ady = abs(deltay);
  int dy = sign(deltay);

  setWarna(x0, y0);
  if (adx < ady) {
    int D = 2 * adx - ady;
    int x = x0;
    if (D > 0) {
      x += dx;
      D -= 2 * ady;
    }

    for (int y = y0 + dy; y != y1; y += dy) {
      setWarna(x, y);
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
void fun1(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
      
			if(y>=160&&y<=200&&x>=160&&x<=240){
				setWarna(px+x,py+y);
			}
			if(x>=240&&x<=290-(i-60)&&i<105&&y>=160){
				  setWarna(px+x,py+y);
			}
			if(x>=110+(i-60)&&x<=160&&i<110&&y<=200&&y>=160){
				  setWarna(px+x,py+y);
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
     else if (cmd == 'a' || cmd == 'A' || cmd == -4) {
       if(targetx>0)
       targetx-=10;
     }
     else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
       if(targetx<800)
       targetx+=10;
     }
     else if (cmd == 'q' || cmd == 'Q' || cmd == -1) {
       if(tembakanx>0)
       tembakanx-=10;
     }
     else if (cmd == 'e' || cmd == 'E' || cmd == -2) {
       if(tembakanx<800)
       tembakanx+=10;
     }

  }
  /* the function must return something - NULL will do */
  return NULL;

}



int main(int argc, char** argv) {
  // screen size
  int width = fb.getXSize();
  int height = fb.getYSize();

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
    line(tembakanx,height -100,targetx,-40);
    fb.refresh();
    fun1(px,py);
    // baca piilhan
    px--;
    if(px<-100){
      px= fb.getXSize();
    }
    fb.clear();
  }
  return 0;
}
