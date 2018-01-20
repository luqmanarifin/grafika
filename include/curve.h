#ifndef CURVE_H_
#define CURVE_H_ 1

#include <bits/stdc++.h>
#include "point.h"
#include "line.h"
#include "vector.h"
#include "framebuffer.h"

class curve
{
public:
  curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d,  Color _color);
  curve(const curve& c);
  curve& operator=(const curve& c);
  curve& setColor(Color _color);
  curve& createBezier(Point<double> a, Point<double> b, Point<double> c, Point<double> d);
  curve& print(FrameBuffer& fb);
  double ratio(double a, double b);
  vector< Point<double> > points;
private:
  Color color;
};

curve& curve::setColor(Color _color) { color = _color; return *this; }

double curve::ratio(double a, double b) { return abs(a / b); }

curve::curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d, Color _color = Color::WHITE) : color(_color) { createBezier(a, b, c, d); }
curve::curve(const curve& c) : color(c.color), points(c.points) {}

curve& curve::operator= (const curve& c) {
  color = c.color;
  points = c.points;
}


curve& curve::createBezier(Point<double> a, Point<double> b, Point<double> c, Point<double> d) {
  Vector<double> ab(a, b); 
  Vector<double> bc(b, c); 
  Vector<double> cd(c, d);
  double magn1 = ab.magnitude * bc.magnitude;
  double magn2 = bc.magnitude * cd.magnitude;

  // if (ratio( Vector<double>::dot( ab, bc ), magn1 ) > 0.3 &&
  //     ratio( Vector<double>::dot( bc, cd ), magn2 ) > 0.3 ) {
  if (ab.magnitude < 1.5 || bc.magnitude < 1.5 || cd.magnitude < 1.5) {
    // straightLine = new line((int)round(a.x), (int)round(a.y), (int)round(d.x), (int)round(d.y), color);
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
  } else {
    Point<double> d1 = (a + b) * 0.5;
    Point<double> d2 = (b*2 + a + c) * 0.25;
    Point<double> d3 = (a + b*3 + c*3 + d) * 0.125;
    Point<double> d4 = (c*2 + b + d) * 0.25;
    Point<double> d5 = (c + d) * 0.5;

    createBezier(a, d1, d2, d3);
    createBezier(d3, d4, d5, d);
  }
}

// curve& curve::print(FrameBuffer& fb) {
//   if (straightLine != NULL) {
//     straightLine->print(fb);
//   } else {
//     leftChild->print(fb);
//     rightChild->print(fb);
//   }
//   return *this;
// }

#endif
