#ifndef HULL_
#define HULL_ 1

#include <algorithm>
#include <vector>
#include "point.h"
using namespace std;

typename <class T>
vector< Point<T> >& make_convex_hull (vector< Point<T> > P) 
{
  int n = P.size(), k = 0;
  vector< Point<T> > H(2*n);

  // Sort points lexicographically
  sort(P.begin(), P.end());

  // Build lower hull
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  H.resize(k);
  return H;
}

#endif