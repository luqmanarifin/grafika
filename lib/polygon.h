#ifndef __POLYGON_H
#define __POLYGON_H

#include <cassert>

#include "point.h"
#include "framebuffer.h"
#include "color.h"
#include "vector.h"

using namespace std;

const double eps = 1e-13;
inline int sign(int x) { return (x > 0) - (x < 0); }

void line(FrameBuffer fb, int x0, int y0, int x1, int y1, Color color)
{
  int deltax = x1 - x0;
  int adx = abs(deltax);
  int dx = sign(deltax);

  int deltay = y1 - y0;
  int ady = abs(deltay);
  int dy = sign(deltay);

  fb.set(x0, y0, color);
  if (adx < ady) {
    int D = 2 * adx - ady;
    int x = x0;
    if (D > 0) {
      x += dx;
      D -= 2 * ady;
    }

    for (int y = y0 + dy; y != y1; y += dy) {
      fb.set(x, y, color);
      D += 2 * adx;
      while (D > 0) {
        x += dx;
        D -= 2 * ady;
      }
    }
  }
  else {
    int D = 2 * ady - adx;    
    int y = y0;
    if (D > 0) {
      y += dy;
      D -= 2 * adx;
    }

    for (int x = x0 + dx; x != x1; x += dx) {
      fb.set(x, y, color);
      D += 2 * ady;
      while (D > 0) {
        y += dy;
        D -= 2 * adx;
      }
    }
  }
}

struct Polygon {
  Polygon() {
    warna = Color::WHITE;
    points = NULL;
    size = 0;
  }
  Polygon(Point<double>* _points, int _size) {
    warna = Color::WHITE;
    points = _points;
    size = _size;
    if (size > 2) generateNormal();
  }
  Polygon(const Polygon& _polygon) {   
    warna = _polygon.warna;
    size = _polygon.size;
    points = new Point<double>[size];
    for(int i=0;i<size;i++){
      points[i]=Point<double>(_polygon.points[i]);
    }    
    if (size > 2) generateNormal();
  }
  Polygon& operator=(const Polygon& _polygon) {
    warna = _polygon.warna;
    size = _polygon.size;
    if ( points != NULL) delete[] points;
    points = new Point<double>[size];
    for(int i=0;i<size;i++){
      points[i]=Point<double>(_polygon.points[i]);
    }    
    if (size > 2) generateNormal();
    return *this;
  }
  ~Polygon() {
    if ( points != NULL) delete[] points;
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
    // cout << center << endl;

    if (size > 2) generateNormal();
    return *this;
  }

  // Set Color
  Polygon& setColor(int red, int green, int blue, int alpha) { warna = Color(red, green, blue, alpha); return *this; }
  Polygon& setColor(const Color& color) { warna = color; return *this; }

  static bool same(double a, double b) {
    return fabs(a - b) < eps;
  }
  
  void print_frame(FrameBuffer& fb, int red, int green, int blue, int alpha) {
    for(int i = 0; i < size; i++) {
      int j = (i + 1) % size;
      line(fb, (int) points[i].x, (int) points[i].y, (int) points[j].x, (int) points[j].y, Color(red, green, blue, alpha));
    }
  }
  Polygon& print(FrameBuffer& fb) {
    double ymin = 1e9, ymak = -1e9;
    for(int i = 0; i < size; i++) {
      ymin = min(ymin, points[i].y);
      ymak = max(ymak, points[i].y);
    }

    double* a = new double[2 * size];
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
      for(int i = 0; i + 1 < sz; i += 2) {
        for(int j = (int) a[i]; j <= a[i + 1]; j++) {
          fb.set(j, y, warna);
        }
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
      for(int i = 0; i + 1 < sz; i += 2) {
        for(int j = (int) a[i]; j <= a[i + 1]; j++) {
          fb.set(b, j, warna);
        }
      }
    }
    if ( a != NULL) delete[] a;
    print_frame(fb,255,255,255,0);
    return *this;
  }
  int MaxX(){
    int Max=0;
    for(int  i=0;i <size;i++){
       if(points[i].x>Max){
          Max = points[i].x;
       }
    } 
    return Max;
  }
  int MaxY(){
    int Max=0;
    for(int  i=0;i <size;i++){
       if(points[i].y>Max){
          Max = points[i].y;
       }
    } 
    return Max;
  }
  
  int MinX(){
    int Min=1400;
    for(int  i=0;i <size;i++){
       if(points[i].x<Min){
          Min = points[i].x;
       }
    } 
    return Min;
  }
  int MinY(){
    int Min=800;
    for(int  i=0;i <size;i++){
       if(points[i].y<Min){
          Min = points[i].y;
       }
    } 
    return Min;
  }
  
  Polygon& resize(double factor, const Point<double>& center = Point<double>()) {
    for (int i = 0; i < size; ++i) {
      points[i].scale(factor, center);
    }
    this->center.scale(factor, center);
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
    return *this;
  }
  Polygon& rotate(double degreeZ, const Point<double>& center = Point<double>(0, 0), double degreeX = 0, double degreeY = 0) {
    for (int i = 0; i < size; ++i) {
      points[i].rotate(degreeZ, center, degreeX, degreeY);
    }
    this->center.rotate(degreeZ, center, degreeX, degreeY);

    if (size > 2) norm.rotate(degreeZ, degreeX, degreeY);
    return *this;
  }
  Polygon& rotateCenter(double degreeZ, double degreeX = 0, double degreeY = 0) {
    return rotate(degreeZ, this->center, degreeX, degreeY);
  }
  Polygon& generateNormal() {
    assert(this->size > 2);
    norm = Vector<double>::cross(Vector<double>(points[0],points[1]), Vector<double>(points[0], points[2]));
    return *this;
  }

  Point<double>* points;
  int size;
  Point<double> center;
  Vector<double> norm;
  Color warna;
};

#endif
