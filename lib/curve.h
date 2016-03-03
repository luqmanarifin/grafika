#ifndef CURVE_H_
#define CURVE_H_ 1

#include <cmath>
#include <cstdlib>
#include "point.h"
#include "line.h"
#include "vector.h"
#include "framebuffer.h"

class curve
{
public:
  curve(const Point<double>& a, const Point<double>& b, const Point<double>& c, const Point<double>& d, Color _color);
  ~curve();
  curve& setColor(Color _color);
  void print(FrameBuffer& fb);
private:
  double errorRatio(double a, double b);
  curve* leftChild;
  curve* rightChild;
  line* straightLine;
  Color color;
};

curve::~curve() {
  if (leftChild != NULL) delete(leftChild);
  if (rightChild != NULL) delete(rightChild);
  if (straightLine != NULL) delete(straightLine);
}

curve& curve::setColor(Color _color) { color = _color; return *this; }

double curve::errorRatio(double a, double b) { return abs(a-b) / b; }

curve::curve(const Point<double>& a, const Point<double>& b, const Point<double>& c, const Point<double>& d, Color _color = Color::WHITE) 
{
  Vector<double> ab(a, b); 
  Vector<double> bc(b, c); 
  Vector<double> cd(c, d);
  Vector<double> va(a.x, a.y);
  Vector<double> vb(b.x, b.y);
  Vector<double> vc(c.x, c.y);
  Vector<double> vd(d.x, d.y);
  double magn1 = ab.magnitude * bc.magnitude;
  double magn2 = bc.magnitude * cd.magnitude;

  if (errorRatio( Vector<double>::dot( ab, bc ), magn1 ) < 0.1 &&
      errorRatio( Vector<double>::dot( bc, cd ), magn2 ) < 0.1 ) {
    straightLine = new line(a, d, color);
  }

  Vector<double> d1 = (va + vb) * 0.5;
  Vector<double> d2 = (vb*2 + va + vc) * 0.25;
  Vector<double> d3 = (va + vb*3 + vc*3 + vd) * 0.125;
  Vector<double> d4 = (vc*2 + vb + vd) * 0.25;
  Vector<double> d5 = (vc + vd) * 0.5;

  leftChild = new curve(a, d1, d2, d3);
  rightChild = new curve(d3, d4, d5, d);
}

void curve::print(FrameBuffer& fb) {
  if (straightLine != NULL) straightLine->print(fb);
  else {
    leftChild->print(fb);
    rightChild->print(fb);
  }
}

#endif