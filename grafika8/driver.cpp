#include "../lib/curve.h"
#include "../lib/line.h"
#include "../lib/conio2.h"

#include "../lib/framebuffer.h"
#include <bits/stdc++.h>
#include <unistd.h>
//#include "objects/mata.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Alis* alis = new Alis();
  puts("jancok");
  FrameBuffer fb;
  alis->print(fb);
  system("clear");
  fb.print();
  return 0;
}
