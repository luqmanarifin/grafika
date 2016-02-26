#ifndef _SHAPE_H_
#define _SHAPE_H_ 1

#include "polygon.h"

struct Shape : public Polygon {
  void print(FrameBuffer& fb, int red, int green, int blue, int alpha) {
    // sort points increasing by z 
    // for each point
    //    add point to set
    //    create convex hull from set
    // print convex hull
  }
};

#endif