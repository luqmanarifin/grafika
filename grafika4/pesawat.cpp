#include "lib/polygon.h"
#include <iostream>
#include "lib/conio2.h"
#include <unistd.h>
#include "objects/orang.h"
#include "objects/roda.h"
#include "objects/pesawat.h"
using namespace std;
FrameBuffer fb;

int main() {
  system("clear");
  Pesawat* orang = new Pesawat();
  orang->print(fb);
  fb.print();
  return 0;
}

