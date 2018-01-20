#ifndef __POLYGON_H
#define __POLYGON_H

#include <cassert>

#include <bits/stdc++.h>
#include "point.h"
#include "framebuffer.h"
#include "line.h"
#include "color.h"
#include "vector.h"

using namespace std;

const double eps = 1e-13;

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
  double ratio(double a, double b) { return abs(a / b); }
  void addCurve(curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d) )
  {
    Vector<double> ab(a, b); 
    Vector<double> bc(b, c); 
    Vector<double> cd(c, d);
    double magn1 = ab.magnitude * bc.magnitude;
    double magn2 = bc.magnitude * cd.magnitude;
    //warna = _color;
    if (ratio( Vector<double>::dot( ab, bc ), magn1 ) > 0.995 &&
        ratio( Vector<double>::dot( bc, cd ), magn2 ) > 0.995 ) {
        //straightLine = new line((int)round(a.x), (int)round(a.y), (int)round(d.x), (int)round(d.y), color);
        addPoint(a);
        addPoint(d);
    } else {
      Point<double> d1 = (a + b) * 0.5;
      Point<double> d2 = (b*2 + a + c) * 0.25;
      Point<double> d3 = (a + b*3 + c*3 + d) * 0.125;
      Point<double> d4 = (c*2 + b + d) * 0.25;
      Point<double> d5 = (c + d) * 0.5;
      addCurve(curve(a, d1, d2, d3));
      addCurve(curve(d3, d4, d5, d));
    }
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
      line((int) points[i].x, (int) points[i].y, (int) points[j].x, (int) points[j].y, Color(red, green, blue, alpha)).print(fb);
    }
  }

  void dfs(FrameBuffer& fb, int a, int b) {
    if(done[a][b]) return;
    done[a][b] = 1;
    printf("%d %d\n", a, b);
    fb.set(a, b, warna);
    dfs(fb, a, b + 1);
    dfs(fb, a, b - 1);
    dfs(fb, a + 1, b);
    dfs(fb, a - 1, b);
  }

  // normalize the point to be printed
  // this method does not change the properties of polygon
  // parameter : the new normalized point that will be printed
  // return the new size of point
  int normalize(Point<int>* p) {
    int sz = 0;
    Point<int>* tmp = new Point<int>[size];
    for(int i = 0; i < size; i++) {
      Point<int> temp = Point<int>((int)(points[i].x + 0.5), (int)(points[i].y + 0.5), (int)(points[i].z + 0.5));
      tmp[sz++] = temp;
    }
    sz = 0;
    for(int i = 0; i < size; i++) {
      if(sz >= 2) {
        if(tmp[i].y == p[sz-1].y && tmp[i].y == p[sz-2].y) {
          if(p[sz-2].x <= p[sz-1].x && p[sz-1].x <= tmp[i].x) {
            p[sz-1] = tmp[i];
            continue;
          }
          if(p[sz-2].x >= p[sz-1].x && p[sz-1].x >= tmp[i].x) {
            p[sz-1] = tmp[i];
            continue;
          }
        }
        if(tmp[i].x == p[sz-1].x && tmp[i].x == p[sz-2].x) {
          if(p[sz-2].y <= p[sz-1].y && p[sz-1].y <= tmp[i].y) {
            p[sz-1] = tmp[i];
            continue;
          }
          if(p[sz-2].y >= p[sz-1].y && p[sz-1].y >= tmp[i].y) {
            p[sz-1] = tmp[i];
            continue;
          }
        }
      }
      p[sz++] = tmp[i];
    }
    return sz;
  }

  // normalize polygon and print. normalize : removing redundant point
  Polygon& normalize_and_print(FrameBuffer& fb) {
    Point<int>* points = new Point<int>[size];
    int size = normalize(points);
 
    int ymin = 1e9, ymak = -1e9;
    for(int i = 0; i < size; i++) {
      ymin = min(ymin, points[i].y);
      ymak = max(ymak, points[i].y);
    }

    int* a = new int[2 * size];
    for(int y = ymin; y <= ymak; y++) {
      int sz = 0;
      for(int i = 0; i < size; i++) {
        int j = (i + 1) % size;
        int l = points[i].y;
        int r = points[j].y;
        if(min(l, r) <= y && y <= max(l, r)) {
          int la = points[i].x;
          int ra = points[j].x;
          if(same(l, r)) {
            a[sz++] = min(la, ra);
            a[sz++] = max(la, ra);
          } else {
            int d = (int)round((double) fabs(l - y)*fabs(la - ra)/fabs(l - r));
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
    
    int bmin = 1e9, bmak = -1e9;
    for(int i = 0; i < size; i++) {
      bmin = min(bmin, points[i].x);
      bmak = max(bmak, points[i].x);
    }

    for(int b = bmin; b <= bmak; b++) {
      int sz = 0;
      for(int i = 0; i < size; i++) {
        int j = (i + 1) % size;
        int l = points[i].x;
        int r = points[j].x;
        if(min(l, r) <= b && b <= max(l, r)) {
          int la = points[i].y;
          int ra = points[j].y;
          if(same(l, r)) {
            a[sz++] = min(la, ra);
            a[sz++] = max(la, ra);
          } else {
            int d = (int)round((double)abs(l - b)*abs(la - ra)/abs(l - r));
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
    //print_frame(fb,255,255,255,0);
    return *this;
  }

  // the casual method of print polygon. working nice in moving object 
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
  void print_dfs(FrameBuffer& fb) {
    printf("%d\n", this->size);
    Point<int>* p = new Point<int>[this->size];
    int size = normalize(p);
    int a_min = 1e9, a_mak = -1e9, b_min = 1e9, b_mak = -1e9;
    for(int i = 0; i < size; i++) {
      a_min = min(a_min, p[i].x);
      a_mak = max(a_mak, p[i].x);
      b_min = min(b_min, p[i].y);
      b_mak = max(b_mak, p[i].y);
    }
    for(int i = a_min; i <= a_mak; i++) {
      for(int j = b_min; j <= b_mak; j++) {
        done[i][j] = 0;
      }
    }
    int* up = new int[768];
    int* down = new int[768];
    int* lef = new int[1366];
    int* rig = new int[1366];
    fill(up, up + 768, 1e9);
    fill(down, down + 768, -1e9);
    fill(lef, lef + 1366, 1e9);
    fill(rig, rig + 1366, -1e9);
    for(int i = 0; i < size; i++) {
      int j = (i + 1) % size;
      // printf("aku suka asi %d from %d\n", i, size);

      line* garis = new line(p[i], p[j], warna);
      int size_line;
      Point<int>* tmp = garis->generate(size_line);
      //printf("%d\n", tmp);
      // printf("size line jadi %d : %d %d to %d %d\n", size_line, p[i].x, p[i].y, p[j].x, p[j].y);
      // for(int k = 0; k < size_line; k++) printf("%d %d\n", tmp[k].x, tmp[k].y);
      for(int k = 0; k < size_line; k++) {
        int a = tmp[k].x, b = tmp[k].y;
        done[a][b] = 1;
        up[a] = min(up[a], b);
        down[a] = max(down[a], b);
        lef[b] = min(lef[b], a);
        rig[b] = max(rig[b], a);
        fb.set(a, b, warna);
      }
      delete[] tmp;
      delete garis;
    }
    printf("done print tepi %d-%d %d-%d\n", a_min, a_mak, b_min, b_mak);
    bool found = 0;
    for(int i = a_min; i <= a_mak && !found; i++) {
      for(int j = b_min; j <= b_mak & !found; j++) {
        if(up[i] < i && i < down[i] && lef[j] < j && j < rig[j] && !done[i][j]) {
          dfs(fb, i, j);
          found = 1;
        }
      }
    }
    printf("dfs done\n");
    puts("done print polygon");
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
