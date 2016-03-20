#ifndef __POLYGON_H
#define __POLYGON_H

#include <cassert>

#include <bits/stdc++.h>
#include "point.h"
#include "framebuffer.h"
#include "line.h"
#include "color.h"
#include "curve.h"
#include "vector.h"

using namespace std;


struct Polygon {
  ///////////////
  /* OOP basic */
  ///////////////
  
  Polygon() {
    warna = Color::WHITE;
    points = NULL;
    size = 0;
    done = new bool*[1366];
    for(int i = 0; i < 1366; i++) done[i] = new bool[768];
  }
  Polygon(Point<double>* _points, int _size) {
    warna = Color::WHITE;
    points = _points;
    size = _size;
    done = new bool*[1366];
    for(int i = 0; i < 1366; i++) done[i] = new bool[768];
  }
  Polygon(const Polygon& _polygon) {   
    warna = _polygon.warna;
    size = _polygon.size;
    points = new Point<double>[size];
    for(int i=0;i<size;i++){
      points[i] = Point<double>(_polygon.points[i]);
    }    
    done = new bool*[1366];
    for(int i = 0; i < 1366; i++) done[i] = new bool[768];
  }
  Polygon& operator=(const Polygon& _polygon) {
    warna = _polygon.warna;
    size = _polygon.size;
    if ( points != NULL) delete[] points;
    points = new Point<double>[size];
    for(int i=0;i<size;i++){
      points[i] = Point<double>(_polygon.points[i]);
    }    
    return *this;
  }
  ~Polygon() {
    if ( points != NULL) delete[] points;
  }

  // Set Color
  Polygon& setColor(int red, int green, int blue, int alpha = 1.0) { warna = Color(red, green, blue, alpha); return *this; }
  Polygon& setColor(const Color& color) { warna = color; return *this; }

  double ratio(double a, double b) { return abs(a / b); }

  bool isEqueal(Point<double> p1,Point<double> p2) {
    return !islessgreater(p1.x,p2.x) && !islessgreater(p1.y,p2.y) && !islessgreater(p1.z,p2.z);
  }
  void addCurve(curve c)
  {
    for (vector< Point<double> >::iterator i = c.points.begin(); i != c.points.end(); ++i)
    {
      Point<double> d = *i;
      if (size > 0) {
        if (points[size - 1] != d) {
          addPoint(d);
        }
      }
      else {
        addPoint(d);
      }
    }
    //return *this;
  }

  Polygon& addPoint(const Point<double>& p) {
    Point<double>* newPoints = new Point<double>[size + 1];
    for(int i = 0; i < size; i++) {
      newPoints[i] = points[i];
    }
    
    newPoints[size++] = p;
    if ( points != NULL) delete[] points;
    points = newPoints;

    // update center
    center.x *= (size - 1);
    center.x += p.x;
    center.x /= size;
    center.y *= (size - 1);
    center.y += p.y;
    center.y /= size;
    center.z *= (size - 1);
    center.z += p.z;
    center.z /= size;
    
    return *this;
  }

  static bool same(double a, double b) {
    return fabs(a - b) < eps;
  }
  
  ///////////
  /* Print */
  ///////////
  
  Polygon& print_frame(FrameBuffer& fb, int red, int green, int blue, int alpha) {
    for(int i = 0; i < size; i++) {
      int j = (i + 1) % size;
      line((int) points[i].x, (int) points[i].y, (int) points[j].x, (int) points[j].y, Color(red, green, blue, alpha)).print(fb, -99999999);
    }
    return *this;
  }

  Polygon& print(FrameBuffer& fb) 
  {
    print_frame(fb,0,0,0,0);
    double* a = new double[2 * size];

    double ymin = 1e9, ymak = -1e9;
    for(int i = 0; i < size; i++) {
      ymin = min(ymin, points[i].y);
      ymak = max(ymak, points[i].y);
    }

    for(int y = ymin; y <= ymak; y++) {
      int sz = 0;
      for(int i = 0; i < size; i++) {
        int j = (i + 1) % size;
        double l = points[i].y;
        double r = points[j].y;
        if(min(l, r) <= y && y <= max(l, r)) {
          double la = points[i].x;
          double ra = points[j].x;
          if(same(l, r)) {
            a[sz++] = min(la, ra);
            a[sz++] = max(la, ra);
          } else {
            double d = fabs(l - y)*fabs(la - ra)/fabs(l - r);
            a[sz++] = la + (la < ra? d : -d);
          }
        }
      }
      sort(a, a + sz);
      sz = unique(a,a+sz)-a;
      for(int i = 0; i + 1 < sz; i += 2) {
        fb.hset(MinZ(), y, (int)round(a[i]), (int)round(a[i+1]), warna);
      }
    }
    
    double bmin = 1e9, bmak = -1e9;
    for(int i = 0; i < size; i++) {
      bmin = min(bmin, points[i].x);
      bmak = max(bmak, points[i].x);
    }

    for(int b = bmin; b <= bmak; b++) {
      int sz = 0;
      for(int i = 0; i < size; i++) {
        int j = (i + 1) % size;
        double l = points[i].x;
        double r = points[j].x;
        if(min(l, r) <= b && b <= max(l, r)) {
          double la = points[i].y;
          double ra = points[j].y;
          if(same(l, r)) {
            a[sz++] = min(la, ra);
            a[sz++] = max(la, ra);
          } else {
            double d = abs(l - b)*abs(la - ra)/abs(l - r);
            a[sz++] = la + (la < ra? d : -d);
          }
        }
      }
      sort(a, a + sz);
      sz = unique(a,a+sz)-a;
      for(int i = 0; i + 1 < sz; i += 2) {
        fb.vset(MinZ(), b, (int)round(a[i]), (int)round(a[i+1]), warna);
      }
    }

    if (a != NULL) delete[] a;
    return *this;
  }

  ////////////////
  /* Boundaries */
  ////////////////
  
  int MinZ() {
    if (minZ != DUMMY) return minZ;

    int Min = DUMMY - 1;              // overflow cycle (min - 1 = max) :P
    for(int i = 0; i < size; i++) {
      int rounded = (int)round(points[i].z);
      if(rounded < Min) {
        Min = rounded;
      }
    } 
    return minZ = Min;
  }
  
  ////////////////////
  /* Transformation */
  ////////////////////
  
  Polygon& resize(double factor, const Point<double>& center = Point<double>()) {
    for (int i = 0; i < size; ++i) {
      points[i].scale(factor, center);
    }
    this->center.scale(factor, center);
    minZ = DUMMY;
    return *this;
  }
  Polygon& resizeCenter(double factor) {
    return resize(factor, this->center);
  }
  Polygon& move(int x, int y) {
    for (int i = 0; i < size; ++i) {
      points[i].move(x, y);
    }
    center.move(x, y);
    minZ = DUMMY;
    return *this;
  }
  Polygon& rotate(double degreeZ, const Point<double>& center = Point<double>(0, 0), double degreeX = 0, double degreeY = 0) {
    for (int i = 0; i < size; ++i) {
      points[i].rotate(degreeZ, center, degreeX, degreeY);
    }
    this->center.rotate(degreeZ, center, degreeX, degreeY);
    minZ = DUMMY;

    return *this;
  }
  Polygon& rotateCenter(double degreeZ, double degreeX = 0, double degreeY = 0) {
    return rotate(degreeZ, this->center, degreeX, degreeY);
  }

  /**
   * Fields
   */

  Point<double>* points;
  int size;
  Point<double> center;
  Color warna;

  // properties for dfs
  bool** done;

private:
  // Memo
  const int DUMMY = 0x80000000;
  int minZ = DUMMY;
};

#endif
