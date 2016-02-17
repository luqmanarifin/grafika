#include <bits/stdc++.h>
#include "lib/point.h"

int main(int argc, char const *argv[])
{
  Point p (1,2);
  Point q (p);
  q.rotate(90.0);
  cout << p << q << endl;
  return 0;
}