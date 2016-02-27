#ifndef _SHAPE_H_
#define _SHAPE_H_ 1

#include "polygon.h"

struct Shape {
  Shape() {
    polygons = NULL;
    size = 0;
  }
  Shape(Polygon* polygons, int _size) {
    polygons = polygons;
    size = _size;
  }
  Shape(const Shape& _shape) {   
    size = _shape.size;
    polygons = new Polygon[size];
    for(int i=0;i<size;i++){
      polygons[i]=Polygon(_shape.polygons[i]);
    }    
  }
  void operator=(const Shape& _shape) {
    size = _shape.size;
    if ( polygons != NULL) delete[] polygons;
    polygons = new Polygon[size];
    for(int i=0;i<size;i++){
      polygons[i]=Polygon(_shape.polygons[i]);
    }    
  }
  ~Shape() {
    if ( polygons != NULL) delete[] polygons;
  }
  Shape& addPoint(const Polygon& p) {
    Polygon* newPolygons = new Polygon[size + 1];
    for(int i = 0; i < size; i++) {
      newPolygons[i] = polygons[i];
    }
    newPolygons[size++] = p;
    if ( polygons != NULL) delete[] polygons;
    polygons = newPolygons;

    // update center
    // ONLY VALID ON SYMMETRICAL SHAPE
    center.x *= (size - 1);
    center.x += p.center.x;
    center.x /= size;
    center.y *= (size - 1);
    center.y += p.center.y;
    center.y /= size;

    return *this;
  }
  Shape& print(FrameBuffer& fb) {
    return print(fb, 255, 255, 255, 0);
  }  
  Shape& print(FrameBuffer& fb, int red, int green, int blue, int alpha) {
    for (int i = 0; i < size; ++i) {
      if (polygons[i].norm.z > 0)
        polygons[i].print(fb, red, green, blue, alpha);
    }
    return *this;
  }

  Polygon* polygons;
  int size;
  Point center;
};

#endif