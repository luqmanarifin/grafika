#ifndef CURVE_H_
#define CURVE_H_ 1

#include <bits/stdc++.h>
#include <point.h>
#include <line.h>
#include <vector.h>
#include <framebuffer.h>

class curve
{
public:
  curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d,  Color _color = Color::WHITE);
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

#endif
