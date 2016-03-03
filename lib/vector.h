#ifndef _VECTOR_H
#define _VECTOR_H 1

#include <cmath>
#include "point.h"
using namespace std;

template<class T>
class Vector : public Point<T> {
public:
  Vector<T>() : x(0), y(0), z(0) { setMagnitude(); }
  Vector<T>(T _x, T _y, T _z = 0) : x(_x), y(_y), z(_z) { setMagnitude(); }
  Vector<T>(const Point<T>& u, const Point<T>& v) : x(v.x - u.x), y(v.y - u.y), z(v.z - u.z) { setMagnitude(); }
  Vector<T>(const Vector<T>& p) : x(p.x), y(p.y), z(p.z) { setMagnitude(); }
  Vector<T>& operator+=(const Vector<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    setMagnitude();
    return *this;
  }

  Vector<T>& operator+(const Vector<T>& rhs) {
    Vector<T> tmpres(x+rhs.x, y+rhs.y, z+rhs.z);
    return tmpres;
  }

  Vector<T>& operator-=(const Vector<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    setMagnitude();
    return *this;
  }

  Vector<T>& operator-(const Vector<T>& rhs) {
    Vector<T> tmpres(x-rhs.x, y-rhs.y, z-rhs.z);
    return tmpres;
  }

  Vector<T>& operator=(const Vector<T>& p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    setMagnitude();
    return *this;
  }

  Vector<T>& operator*=(const double factor) {
    this->x = this->x * factor;
    this->y = this->y * factor;
    this->z = this->z * factor;
    setMagnitude();
    return *this;
  }

  Vector<T>& operator*(const double factor) {
    Vector<T> tmpres(this->x * factor, this->y * factor, this->z * factor);
    return tmpres;
  }

  Vector<T>& rotate(double degreeZ, double degreeX = 0, double degreeY = 0) {
    double radX = degreeX * 3.14159265358979323846 / 180.0 *0.9999;
    double radY = degreeY * 3.14159265358979323846 / 180.0 *0.9999;
    double radZ = degreeZ * 3.14159265358979323846 / 180.0 *0.9999;

    if (degreeZ) {
      x = x*cos(radZ)-y*sin(radZ);
      y = x*sin(radZ)+y*cos(radZ);
    } else if (degreeY) {
      x = z*sin(radY)+x*cos(radY);
      z = z*cos(radY)-x*sin(radY);
    } else {
      y = y*cos(radX)-z*sin(radX);
      z = y*sin(radX)+z*cos(radX);
    }

    return *this;
  }

  void setMagnitude() { 
    sqrMagnitude = x*x + y*y + z*z;
    magnitude = sqrt(sqrMagnitude); 
  }


  /////////////////////////////////
  /** analytic geometry methods **/
  /////////////////////////////////

  Vector<T>& normalized() {
    Vector res(*this);
    double len = res.length();
    res.x /= len;
    res.y /= len;
    res.z /= len;
    return res;
  }
  static Vector<T> cross(const Vector<T>& a, const Vector<T>& b) {
    return Vector<T>(a.y*b.z - b.y*a.z, a.z*b.x - b.z*a.x, a.x*b.y - b.x*a.y);
  }
  static T dot(const Vector<T>& a, const Vector<T>& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

  friend ostream& operator<< (ostream& stream, const Vector<T>& p) {
    stream << "<" << p.x << ", " << p.y << ", " << p.z << ">";
  }

  T x, y, z;
  double magnitude, sqrMagnitude;
};

#endif
