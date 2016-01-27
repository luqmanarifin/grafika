#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/conio2.h"
//#include "lib/bitmap.h"
#include "lib/framebuffer.h"

using namespace std;

FrameBuffer fb;

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

void fun1(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
      if(x>=160&&x<=170&&y<=160){
				setWarna(px+x,py+y);
			}
			if(y>=100&&y<=110&&x>=160&&x<=200){
				setWarna(px+x,py+y);
			}
			if(y>=120&&y<=130&&x>=160&&x<=200){
				setWarna(px+x,py+y);
			}
			if(x>=190&&x<=200&y<=160){
				setWarna(px+x,py+y);
			}
			if(y>=100&&y<=110&&x<=150){
					setWarna(px+x,py+y);
				}
			if(y>=150&&y<=160&&x<=150){
					setWarna(px+x,py+y);
				}
			if(x>=150-i&&x<=160-i&&i<50&&y>=110){
				  setWarna(px+x,py+y);
			}
			if(x>=210&&x<=220&&y<=160){
                setWarna(px+x,py+y);
				}
				
				if(x>=210+i&&x<=220+i&&i<50){
                setWarna(px+x,py+y);
				}

				if(x>=260&&x<=270&y<=160){
                setWarna(px+x,py+y);
				}	
			if(x>=280&&x<=290&&y<=160){
                setWarna(px+x,py+y);
			}
			if(x>=280+i&&x<=290+i&&i<30){
                setWarna(px+x,py+y);
			}
			if(x>=310-(i-30)&&x<=320-(i-30)&&i<60&&y>=130){
                setWarna(px+x,py+y);
			}
			if(x>=280&&x<=290&&y<=160){
                setWarna(px+x,py+y);
			}
			if(x>=280+i&&x<=290+i&&i<30){
                setWarna(px+x,py+y);
			}
			if(x>=310-(i-30)&&x<=320-(i-30)&&i<60&&y>=130){
                setWarna(px+x,py+y);
			}
			if(x>=330&&x<=340&&y<=160){
                setWarna(px+x,py+y);
				}
    }
  }
}

void fun2(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
				if(x>=100&&x<=110&&y>=170&&y<=230){
                setWarna(px+x,py+y);
				}
				if(x>=280&&x<=290&&y<=160){
                setWarna(px+x,py+y);
				}
				if(x>=280+i&&x<=290+i&&i<30){
                setWarna(px+x,py+y);
				}
				if(x>=310-(i-30)&&x<=320-(i-30)&&i<60&&y>=130){
                setWarna(px+x,py+y);
				}
				if(x>=120&&x<=130&&y>=170&&y<=230){
                setWarna(px+x,py+y);
				}
				if(y>=170&&y<=180&&x>=130&&x<=160){
       
                setWarna(px+x,py+y);
				}
				if(x>=170&&x<=180&&y>=170&&y<=230){
                setWarna(px+x,py+y);
				}
				if(y>=170&&y<=180&&x>=170&&x<=210){
                setWarna(px+x,py+y);
				}
				if(y>=190&&y<=200&&x>=170&&x<=210){
				setWarna(px+x,py+y);
				}				
				if(x>=200&&x<=210&&y>=170&&y<=230){
				setWarna(px+x,py+y);
				}
				if(y>=220&&y<=230&&x>=120&&x<=160){
                setWarna(px+x,py+y);
				}
				if(x>=220&&x<=230&&y>=170&&y<=230){
                setWarna(px+x,py+y);
				}
				if(y>=220&&y<=230&&x>=220&&x<=260){
                setWarna(px+x,py+y);
				}
    }
  }
}


void fun3(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
        if(x>=100&&x<=110&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(y>=290&&y<=300&&x>=100&&x<=140){
                setWarna(px+x,py+y);
				}
				if(x>=150&&x<=160&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(y>=290&&y<=300&&x>=150&&x<=190){
                setWarna(px+x,py+y);
				}
				if(x>=190&&x<=200&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(x>=210&&x<=220&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(y>=240&&y<=250&&x>=210&&x<=250){
                setWarna(px+x,py+y);
				}
				if(y>=290&&y<=300&&x>=210&&x<=250){
                setWarna(px+x,py+y);
				}
				if(x>=250&&x<=260&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}				
				if(x>=235+(i-170)&&x<=245+(i-170)&&i<200&&y>=270&&y<=300){
                setWarna(px+x,py+y);
				}
				/*print M*/
				if(x>=275&&x<=285&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(x>=330&&x<=340&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}				
				if(x>=275+(i-140)&&x<=285+(i-140)&&i<230&&y>=240&&y<=270){
                setWarna(px+x,py+y);
				}
				if(x>=330-(i-140)&&x<=340-(i-140)&&i<230&&y>=240&&y<=270){
                setWarna(px+x,py+y);
				}
				/*print A*/
				if(x>=350&&x<=360&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(y>=240&&y<=250&&x>=350&&x<=390){
                setWarna(px+x,py+y);
				}
				if(y>=260&&y<=270&&x>=350&&x<=390){
                setWarna(px+x,py+y);
				}
				if(x>=390&&x<=400&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				/*print N*/
				if(x>=410&&x<=420&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}
				if(x>=410+(i-140)&&x<=420+(i-140)&&i<230&&y>=240&&y<=290){
                setWarna(px+x,py+y);
				}
				if(x>=460&&x<=470&&y>=240&&y<=300){
                setWarna(px+x,py+y);
				}


    }
  }
}


void fun4(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
				/*print A*/
				if(x>=100&&x<=110&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}
				if(y>=310&&y<=320&&x>=100&&x<=140){
                setWarna(px+x,py+y);
				}

				if(y>=330&&y<=340&&x>=100&&x<=140){
                setWarna(px+x,py+y);
				}
				if(x>=140&&x<=150&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}

				/*print Z*/
				if(y>=310&&y<=320&&x>=160&&x<=210){
                setWarna(px+x,py+y);
				}

				if(y>=360&&y<=370&&x>=160&&x<=210){
                setWarna(px+x,py+y);
				}
				
				if(x>=210-(i-210)&&x<=220-(i-210)&&i<270&&y>=320&&y<=360){
                setWarna(px+x,py+y);
				}
				
				/*print A*/
				if(x>=220&&x<=230&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}
				if(y>=310&&y<=320&&x>=220&&x<=260){
                setWarna(px+x,py+y);
				}
				if(y>=330&&y<=340&&x>=220&&x<=260){
                setWarna(px+x,py+y);
				}
				if(x>=260&&x<=270&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}
				
				/*print M*/
				if(x>=280&&x<=290&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}
				if(x>=330&&x<=340&&y>=310&&y<=370){
                setWarna(px+x,py+y);
				}				
				if(x>=280+(i-210)&&x<=290+(i-210)&&i<240&&y>=310&&y<=340){
                setWarna(px+x,py+y);
				}
				if(x>=330-(i-210)&&x<=340-(i-210)&&i<240&&y>=310&&y<=340){
                setWarna(px+x,py+y);
				}
    }
  }
}


void fun5(int px, int py) {
	int i = 0, x, y;
  // Figure out where in memory to put the pixel
  for (y = 100; y < 1000; y++) {
	  i++;
    for (x = 100; x < 1000; x++) {
				/*print H*/
				if(x>=100&&x<=110&&y>=380&&y<=440){
                setWarna(px+x,py+y);
				}
				if(y>=405&&y<=415&&x>=100&&x<=140){
                setWarna(px+x,py+y);
				}
				if(x>=140&&x<=150&&y>=380&&y<=440){
                setWarna(px+x,py+y);
				}				
				/*print E*/
				if(y>=430&&y<=440&&x>=160&&x<=200){
                setWarna(px+x,py+y);
				}
				if(y>=380&&y<=390&&x>=160&&x<=200){
                setWarna(px+x,py+y);
				}
				if(y>=405&&y<=415&&x>=160&&x<=190){
                setWarna(px+x,py+y);
				}
				if(x>=160&&x<=170&&y>=380&&y<=440){
                setWarna(px+x,py+y);
				}
				/*print R*/
				if(y>=380&&y<=390&&x>=210&&x<=250){
                setWarna(px+x,py+y);
				}
				if(y>=405&&y<=415&&x>=210&&x<=250){
                setWarna(px+x,py+y);
				}
				if(x>=210&&x<=220&&y>=380&&y<=440){
                setWarna(px+x,py+y);
				}
				if(x>=240&&x<=250&&y>=380&&y<=405){
                setWarna(px+x,py+y);
				}
				if(x>=235+(i-335)&&x<=245+(i-335)&&i<365&&y>=405&&y<=440){
                setWarna(px+x,py+y);
				}
				/*print I*/
				if(x>=260&&x<=270&&y>=380&&y<=440){
                setWarna(px+x,py+y);
				}
    }
  }
}




int main(int argc, char** argv) {
  // screen size
  int width = fb.getXSize();
  int height = fb.getYSize();

  // position for color pallette
  int px = 100, py = height;
  int position = 0, mode = 0;

  // tampilkan informasi
  system("clear");
  // puts("Tekan wsda/arrow key untuk mengubah warna.");
  // puts("Tekan enter untuk masuk mode memilih warna.");
  // puts("Tekan escape 2 kali untuk keluar.");
  // puts("Pada mode memilih warna:");
  // puts("- Tekan wsda/arrow key untuk mengubah warna.");
  // puts("- Tekan enter untuk mengetahui warna pada titik tersebut.");

  int cmd = ' ';
  while (py > -100)
  {
    fun1(px,py);
    fun2(px,py);
    fun3(px,py);
    fun4(px,py);
    fun5(px,py);
    
    fb.refresh();

    // baca piilhan
    // cmd = getch();

    // if (cmd == 27) {
    //   cmd = getch();
    //   if (cmd == 27) {
    //     break;
    //   }
    //   else if (cmd == 91) {
    //     cmd = getch();
    //     cmd = 64 - cmd;
    //   }
    // }
    // else if (cmd == 'a' || cmd == 'A' || cmd == -4) {
    //   if (px >= 0) px--;
    // }
    // else if (cmd == 'd' || cmd == 'D' || cmd == -3) {
    //   if (px < sizeX - 1) px++;
    // }
    // else if (cmd == 'w' || cmd == 'W' || cmd == -1) {
    //   if (py >= 0) py--;
    // }
    // else if (cmd == 's' || cmd == 'S' || cmd == -2) {
    //   if (py < sizeY - 1) py++;
    // }

    // reset framebuffer
    usleep(10000);

    fb.clear();
    py--;
  }
  return 0;
}
