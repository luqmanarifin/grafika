#include "../lib/curve.h"
#include "../lib/conio2.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
  FrameBuffer fb;
  curve cur(Point<double>(30, 20), Point<double>(35, 46), Point<double>(59, 52), Point<double>(10, 55));
  cur.print(fb);
  system("clear");
  fb.print();
  while (1) {}
  return 0;
}