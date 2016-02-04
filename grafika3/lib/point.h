#ifndef POINT_H__
#define POINT_H__

#include <bits/stdc++.h>
using namespace std;

/**
 * Class that represents 2D point
 */
class Point {
public:
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}

  Point operator+=(const Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Point operator+(const Point& rhs) {
    return Point(x+rhs.x, y+rhs.y);
  }

  Point operator-=(const Point& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Point operator-(const Point& rhs) {
    return Point(x-rhs.x, y-rhs.y);
  }

  Point rotate(int degree, const Point& center = Point(0, 0)) {
    *this -= center;
    Point temp = *this;

    float rad = degree*3.14159265/180.0;
    x = temp.x*cos(rad)-temp.y*sin(rad);
    y = temp.x*sin(rad)+temp.y*cos(rad);

    *this += center;
    return *this;
  }

  Point scale(const Point& center, double factor) {
    int dy = this->y - center.y;
    int dx = this->x - center.x;
    double _dx = dx*factor;
    double _dy = dy*factor;

    // rounding to nearest pixel
    dx = (int)(2 * _dx - (int)_dx);   
    dy = (int)(2 * _dy - (int)_dy);

    // set position
    this->x = center.x + dx;
    this->y = center.y + dy;

    return *this;
  }

  friend ostream& operator<< (ostream& stream, const Point& p) {
    stream << "<" << p.x << ", " << p.y << ">\n";
  }

  int x, y;
};

#endif