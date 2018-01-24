#ifndef __POLYGON_H
#define __POLYGON_H

#include <cassert>

#include <bits/stdc++.h>

#include <point.h>
#include <framebuffer.h>
#include <line.h>
#include <color.h>
#include <curve.h>
#include <vector.h>

using namespace std;


struct Polygon {
  ///////////////
  /* OOP basic */
  ///////////////
  
  Polygon();
  Polygon(Point<double>* _points, int _size);
  Polygon(const Polygon& _polygon);
  Polygon& operator=(const Polygon& _polygon);
  ~Polygon();

  // Set Color
  Polygon& setColor(int red, int green, int blue, int alpha);
  Polygon& setColor(const Color& color);

  double ratio(double a, double b);

  bool isEqueal(Point<double> p1,Point<double> p2);
  Polygon& addCurve(curve c);

  Polygon& addPoint(const Point<double>& p);

  static bool same(double a, double b);
  
  ///////////
  /* Print */
  ///////////
  
  Polygon& print_frame(FrameBuffer& fb, int red, int green, int blue, int alpha);

  Polygon& print(FrameBuffer& fb);

  ////////////////
  /* Boundaries */
  ////////////////
  
  int MaxX();
  int MinX();
  int MaxY();
  int MinY();
  int MinZ();
  
  ////////////////////
  /* Transformation */
  ////////////////////
  
  Polygon& resize(double factor, const Point<double>& center);
  Polygon& resizeCenter(double factor);
  Polygon& move(int x, int y);
  Polygon& rotate(double degreeZ, const Point<double>& center = Point<double>(0, 0), double degreeX = 0, double degreeY = 0);
  Polygon& rotateCenter(double degreeZ, double degreeX = 0, double degreeY = 0);

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
  int maxX = DUMMY;
  int minX = DUMMY;
  int maxY = DUMMY;
  int minY = DUMMY;
  int minZ = DUMMY;
};

#endif
