#ifndef POINT_H__
#define POINT_H__

#include <bits/stdc++.h>
using namespace std;

/**
 * Class that represents 2D point
 */
template<class T>
class Point {
public:
  Point<T>() : x(0), y(0) {}
  Point<T>(T _x, T _y) : x(_x), y(_y) {}
  Point<T>(const Point<T>& p) : x(p.x), y(p.y) {}

  Point<T> operator+=(const Point<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Point<T> operator+(const Point<T>& rhs) {
    return Point<T>(x+rhs.x, y+rhs.y);
  }

  Point<T> operator-=(const Point<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Point<T> operator-(const Point<T>& rhs) {
    return Point<T>(x-rhs.x, y-rhs.y);
  }

  Point<T> operator=(const Point<T>& p) {
    this->x = p.x;
    this->y = p.y;
    return *this;
  }
  
  Point<T> rotate(double degree, const Point<T>& center = Point<T>(0, 0)) {
    *this -= center;
    Point<T> temp = *this;

    double rad = degree * 3.14159265358979323846 / 180.0 *0.99;
    x = temp.x*cos(rad)-temp.y*sin(rad);
    y = temp.x*sin(rad)+temp.y*cos(rad);

    *this += center;
    return *this;
  }

  Point<T> scale(double factorx, const Point<T>& center = Point<T>(0,0), double factory = 0) 
  {
    if (!factory) factory = factorx;

    double dy = this->y - center.y;
    double dx = this->x - center.x;
    double _dx = dx*factorx;
    double _dy = dy*factory;

    // set position
    this->x = center.x + _dx;
    this->y = center.y + _dy;

    return *this;
  }

  Point<T> move(T x, T y) {
    this->x += x;
    this->y += y;
    return *this;
  }

  friend ostream& operator<< (ostream& stream, const Point<T>& p) {
    stream << "<" << p.x << ", " << p.y << ">\n";
  }

  double x, y;
};

#endif
