#ifndef __POLYGON_H
#define __POLYGON_H

#include "point.h"
#include "framebuffer.h"
#include "color.h"

using namespace std;

struct Polygon {
  Polygon() {
    points = NULL;
    size = 0;
  }
  Polygon(Point* _points, int _size) {
    points = _points;
    size = _size;
  }
  ~Polygon() {
    delete [] points;
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
        int l = points[i].y;
        int r = points[j].y;
        if(min(l, r) <= y && y <= max(l, r)) {
          int la = points[i].x;
          int ra = points[j].x;
          if(l == r) {
            for(int k = la; k <= ra; k++) {
              fb.set(k, y, Color::WHITE);
            }
          } else {
            int d = abs(l - y)*abs(la - ra)/abs(l - r);
            a[sz++] = la + (la < ra? d : -d);
          }
        }
      }
      sort(a, a + sz);
      /*
      if(sz) {
        printf("%d : ", y);
        for(int i = 0; i < sz; i++) {
          printf("%d ", a[i]);
        }
        printf("\n");
      }
      */
      for(int i = 0; i + 1 < sz; i += 2) {
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