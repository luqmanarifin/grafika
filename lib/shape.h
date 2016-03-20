#ifndef _SHAPE_H_
#define _SHAPE_H_ 1

#include "polygon.h"

struct Shape {
  ///////////////
  /* OOP basic */
  ///////////////
  
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
    if (polygons != NULL) delete[] polygons;
    polygons = new Polygon[size];
    for(int i=0;i<size;i++){
      polygons[i]=Polygon(_shape.polygons[i]);
    }    
  }
  ~Shape() {
    if (polygons != NULL) delete[] polygons;
  }
  Shape& addPolygon(const Polygon& p) {
    Polygon* newPolygons = new Polygon[size + 1];
    for(int i = 0; i < size; i++) {
      newPolygons[i] = polygons[i];
    }
    newPolygons[size++] = p;
    if (polygons != NULL) delete[] polygons;
    polygons = newPolygons;

    return *this;
  }


  Shape& setColor(int red, int green, int blue, int alpha = 1.0) { 
    for (int i = 0; i < size; ++i) {
      polygons[i].setColor(red+(10*i), green+(15*i), blue+(15*i), alpha);
    }
    return *this; 
  }
  Shape& setColor(const Color& color) { 
    for (int i = 0; i < size; ++i) {
      polygons[i].setColor(color);
    }
    return *this; 
  }
  ///////////
  /* Print */
  ///////////

  Shape& print(FrameBuffer& fb) {
    for (int i = 0; i < size; ++i) {
      polygons[i].print(fb);
    }
    return *this;
  }
  Shape& printframe(FrameBuffer& fb) {
    for (int i = 0; i < size; ++i) {
      polygons[i].print_frame(fb,255,255,255,0);
    }
    return *this;
  }

  /**
   * Transformation
   */

  Shape& resize(double factor, const Point<double>& center = Point<double>()) {
    for (int i = 0; i < size; ++i) {
      polygons[i].resize(factor, center);
    }
    this->center.scale(factor, center);
    
    return *this;
  }
  Shape& resizeCenter(double factor) {  
    return resize(factor, this->center);
  }
  Shape& move(int x, int y) {
    for (int i = 0; i < size; ++i) {
      polygons[i].move(x, y);
    }
    center.move(x, y);
    
    return *this;
  }
  Shape& rotate(double degreeZ, const Point<double>& center = Point<double>(0, 0), double degreeX = 0, double degreeY = 0) {
    for (int i = 0; i < size; ++i) {
      polygons[i].rotate(degreeZ, center, degreeX, degreeY);
    }
    this->center.rotate(degreeZ, center, degreeX, degreeY);
    
    return *this;
  }
  Shape& rotateCenter(double degreeZ, double degreeX = 0, double degreeY = 0) {
    return rotate(degreeZ, this->center, degreeX, degreeY);
  }

  
  
  
  Polygon* polygons;
  int size;
  Point<double> center;
};

#endif
