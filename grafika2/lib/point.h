#ifndef POINT_H__
#define POINT_H__

/**
 * Class that represents 2D point
 */
class Point {
public:
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  
  void resize(float size, const Point& center = Point()) {
    *this -= center;
    x *= size;
    y *= size;
    *this += center;
  }

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

  void rotate(const int& degree, const Point& offset = Point(0, 0)) {
    *this -= offset;
    Point temp = *this;
    float rad = degree*3.14159265/180.0;
    x = temp.x*cos(rad)-temp.y*sin(rad);
    y = temp.x*sin(rad)+temp.y*cos(rad);
    *this += offset;
  }

  int x, y;
};

#endif