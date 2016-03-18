#include <bits/stdc++.h>
#include "../lib/vector.h"

int main(int argc, char const *argv[])
{
  // system("clear");
  Vector<double> a(1,1,1);
  Vector<double> b(2,-2,2);
  Vector<double> c = Vector<double>::cross(a,b);
  cout << c << endl;
  return 0;
}