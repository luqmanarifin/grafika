#include "lib/polygon.h"
#include <iostream>
#include <unistd.h>
#include "lib/conio2.h"

#include "objects/Indonesia.h"

using namespace std;

FrameBuffer fb;

int main() {  
  system("clear");
  Indonesia* indo = new Indonesia();
  indo->print(fb);
  //Halmahera2* ambon = new Halmahera2();
  fb.print();
  return 0;
}

