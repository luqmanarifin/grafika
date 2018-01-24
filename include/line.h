#ifndef LINE_H_
#define LINE_H_ 1

#include <framebuffer.h>

class line
{
public:
  line(const Point<int>& p0, const Point<int>& p1, Color _color);
  line(int _x0, int _y0, int _z0, int _x1, int _y1, int _z1, Color _color);
  ~line() {}
  inline int sign(int x) { return (x > 0) - (x < 0); }
  void print(FrameBuffer& fb);
  Point<int>* generate(int&);

  int x0, y0, z0, x1, y1, z1;
  Color color;
};

#endif
