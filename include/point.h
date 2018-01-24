#ifndef POINT_H__
#define POINT_H__

#include <bits/stdc++.h>
#include <geo.h>

using namespace std;

const double eps = 1e-2;

/**
 * Class that represents 2D point
 */
template<class T>
class Point {
public:
  Point<T>() : x(0), y(0), z(0) {}
  Point<T>(T _x, T _y, T _z = 0) : x(_x), y(_y), z(_z) {}
  Point<T>(const Point<T>& p) : x(p.x), y(p.y), z(p.z) {}

  Point<T>& operator+=(const Point<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  Point<T>& operator+(const Point<T>& rhs) {
    Point<T>* tmpres = new Point<T>(x+rhs.x, y+rhs.y, z+rhs.z);
    return *tmpres;
  }

  Point<T>& operator-=(const Point<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  Point<T>& operator-(const Point<T>& rhs) {
    Point<T>* tmpres = new Point<T>(x-rhs.x, y-rhs.y, z-rhs.z);
    return *tmpres;
  }

  Point<T>& operator*=(const double factor) {
    this->x = this->x * factor;
    this->y = this->y * factor;
    this->z = this->z * factor;
    return *this;
  }

  Point<T>& operator*(const double factor) {
    Point<T>* tmpres = new Point<T>(this->x * factor, this->y * factor, this->z * factor);
    return *tmpres;
  }

  Point<T>& operator=(const Point<T>& p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return *this;
  }
  
  bool operator==(const Point<T>& p) {
    return abs(this->x-p.x) < eps && abs(this->y-p.y) < eps && abs(this->z-p.z) < eps;
  }
  bool operator!=(const Point<T>& p) {
    return !(*this == p);
  }

  Point<T>& rotate(double degreeZ, const Point<T>& center = Point<T>(0, 0), double degreeX = 0, double degreeY = 0) {
    *this -= center;
    Point<T> temp = *this;

    double radX = degToRad(degreeX);
    double radY = degToRad(degreeY);
    double radZ = degToRad(degreeZ);

    // depend on which axis
    // versi cacat
    // ga pake komposisi
    // mlz
    // @icalF 
    if (degreeZ) {
      x = temp.x*cos(radZ)-temp.y*sin(radZ);
      y = temp.x*sin(radZ)+temp.y*cos(radZ);
    } else if (degreeY) {
      x = temp.z*sin(radY)+temp.x*cos(radY);
      z = temp.z*cos(radY)-temp.x*sin(radY);
    } else {
      y = temp.y*cos(radX)-temp.z*sin(radX);
      z = temp.y*sin(radX)+temp.z*cos(radX);
    }

    *this += center;
    return *this;
  }

  Point<T>& scale(double factorx, const Point<T>& center = Point<T>(0,0), double factory = 1.0, double factorz = 1.0) 
  {
    if (!factory) factory = factorx;

    double dz = this->z - center.z;
    double dy = this->y - center.y;
    double dx = this->x - center.x;
    double _dx = dx*factorx;
    double _dy = dy*factory;
    double _dz = dz*factory;

    // set position
    this->x = center.x + _dx;
    this->y = center.y + _dy;
    this->z = center.z + _dz;

    return *this;
  }

  Point<T>& move(T x, T y = 0, T z = 0) {
    this->x += x;
    this->y += y;
    this->z += z;
    return *this;
  }

  friend ostream& operator<< (ostream& stream, const Point<T>& p) {
    stream << "(" << p.x << ", " << p.y << ", " << p.z << ")";
  }

  T x, y, z;
};

#endif
