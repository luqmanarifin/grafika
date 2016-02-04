#ifndef __POLYGON_H
#define __POLYGON_H

#include "point.h"
#include "framebuffer.h"
#include "color.h"

using namespace std;

struct Polygon {
  Polygon() {
    points = NULL;
  }
  Polygon(Point* _points, int _size) {
    points = _points;
    size = _size;
  }

  void addPoint(Point p) {
    Point* newPoints = new Point[size + 1];
    for(int i = 0; i < size; i++) {
      newPoints[i] = points[i];
    }
    newPoints[size++] = p;
    delete[] points;
    points = newPoints;
  }
  void print(FrameBuffer& fb) {
    for(int y = 0; y < 768; y++) {
      int sz = 0;
      int* a = new int[size];
      for(int i = 0; i < size; i++) {
        int j = (i + 1) % size;
        int l = min(points[i].y, points[j].y);
        int r = max(points[i].y, points[j].y);
        if(l <= y && y <= r) {
          int la = min(points[i].x, points[j].x);
          int ra = max(points[i].x, points[j].x);
          if(l == r) {
            for(int k = la; k <= ra; k++) {
              fb.set(k, y, Color::WHITE);
            }
          } else {
            a[sz++] = la + (y - l)*(ra - la)/(r - l);
          }
        }
      }
      sort(a, a + sz);
      for(int i = 0; i + 1 < sz; i++) {
        for(int j = a[i]; j <= a[i + 1]; j++) {
          fb.set(j, y, Color::WHITE);
        }
      }
      delete [] a;
    }
  }
  Point* points;
  int size;
};

#endif