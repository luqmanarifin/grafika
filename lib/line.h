#ifndef LINE_H_
#define LINE_H_ 1

#include "framebuffer.h"

class line
{
public:
  line(const Point<int>& p0, const Point<int>& p1, Color _color);
  line(int _x0, int _y0, int _x1, int _y1, Color _color);
  ~line() {}
  inline int sign(int x) { return (x > 0) - (x < 0); }
  void print(FrameBuffer& fb);
//private:
  int x0, y0, x1, y1;
  Color color;
};

line::line(const Point<int>& p0, const Point<int>& p1, Color _color = Color::WHITE) : x0(p0.x), y0(p0.y), x1(p1.x), y1(p1.y), color(_color) {}
line::line(int _x0, int _y0, int _x1, int _y1, Color _color = Color::WHITE) : x0(_x0), y0(_y0), x1(_x1), y1(_y1), color(_color) {}

void line::print(FrameBuffer& fb)
{
  int deltax = x1 - x0;
  int adx = abs(deltax);
  int dx = sign(deltax);

  int deltay = y1 - y0;
  int ady = abs(deltay);
  int dy = sign(deltay);

  fb.set(x0, y0, color);
  if (adx < ady) {
    int D = 2 * adx - ady;
    int x = x0;
    if (D > 0) {
      x += dx;
      D -= 2 * ady;
    }

    for (int y = y0 + dy; y != y1; y += dy) {
      fb.set(x, y, color);
      D += 2 * adx;
      while (D > 0) {
        x += dx;
        D -= 2 * ady;
      }
    }
  }
  else {
    int D = 2 * ady - adx;    
    int y = y0;
    if (D > 0) {
      y += dy;
      D -= 2 * adx;
    }

    for (int x = x0 + dx; x != x1; x += dx) {
      fb.set(x, y, color);
      D += 2 * ady;
      while (D > 0) {
        y += dy;
        D -= 2 * adx;
      }
    }
  }
}

#endif
