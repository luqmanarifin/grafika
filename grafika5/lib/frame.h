#ifndef FRAME_H__
#define FRAME_H__

class Frame {
public:
  virtual void set(int x, int y, Color c) = 0;
  virtual void set(Point<int> p, Color c) = 0;
  virtual void set(int x, int y, char red, char green, char blue, char alpha = 0) = 0;
  virtual Color get(Point<int> p) = 0;
  virtual Color get(int x, int y) = 0;
  virtual int getXSize() = 0;
  virtual int getYSize() = 0;
};

#endif