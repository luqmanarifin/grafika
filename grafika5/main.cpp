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
#include "objects/Sumatra.h"
#include "objects/kalimantan.h"
#include "objects/Jawa.h"
#include "objects/Sulawesi.h"
#include "objects/rumahgazandi.h"

using namespace std;
FrameBuffer fb;
int main() {
  system("clear");
  RumahGazandi* sumatra = new RumahGazandi();
  sumatra->print(fb);
  fb.print();
  return 0;
}

