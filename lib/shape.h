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
    if ( polygons != NULL) delete[] polygons;
    polygons = new Polygon[size];
    for(int i=0;i<size;i++){
      polygons[i]=Polygon(_shape.polygons[i]);
    }    
  }
  ~Shape() {
    if ( polygons != NULL) delete[] polygons;
  }
  Shape& addPolygon(const Polygon& p) {
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
    center.z *= (size - 1);
    center.z += p.center.z;
    center.z /= size;

    return *this;
  }


  ///////////
  /* Print */
  ///////////

  Shape& print(FrameBuffer& fb) {
    for (int i = 0; i < size; ++i) {
      Vector<double> norm = polygons[i].norm;
      if (norm.z * Vector<double>::dot(norm, Vector<double>(polygons[i].points[0], center)) < 0) {
        polygons[i].print(fb);
      }
    }
    return *this;
  }
  Shape& printframe(FrameBuffer& fb) {
    for (int i = 0; i < size; ++i) {
      Vector<double> norm = polygons[i].norm;
      if (norm.z * Vector<double>::dot(norm, Vector<double>(polygons[i].points[0], center)) < 0) {
        polygons[i].print_frame(fb,255,255,255,0);
      }
    }
    return *this;
  }
  Shape& setColor(int red, int green, int blue, int alpha = 1.0) { 
    for (int i = 0; i < size; ++i) {
        polygons[i].setColor(Color(red, green, blue, alpha));
    }
    return *this; 
  }
  Shape& setColor(const Color& color) { 
    for (int i = 0; i < size; ++i) {
        polygons[i].setColor(color);
    }
    return *this; 
  }

  ////////////////
  /* Boundaries */
  ////////////////
  
  int MaxX() {
    if (maxX != DUMMY) return maxX;

    int Max = 0;
    for(int i = 0; i < size; i++) {
      if(polygons[i].MaxX() > Max) {
        Max = polygons[i].MaxX();
      }
    } 
    return maxX = Max;
  }
  int MaxY() {
    if (maxY != DUMMY) return maxY;

    int Max = 0;
    for(int i = 0; i < size; i++) {
      if(polygons[i].MaxY() > Max) {
        Max = polygons[i].MaxY();
      }
    } 
    return maxY = Max;
  }
  int MaxZ() {
    if (maxZ != DUMMY) return maxZ;

    int Max = DUMMY + 1;
    for(int i = 0; i < size; i++) {
      if(polygons[i].MaxZ() > Max) {
        Max = polygons[i].MaxZ();
      }
    } 
    return maxZ = Max;
  }
  
  int MinX() {
    if (minX != DUMMY) return minX;

    int Min = 1400;
    for(int i = 0; i < size; i++) {
      if(polygons[i].MinX() < Min) {
        Min = polygons[i].MinX();
      }
    } 
    return minX = Min;
  }
  int MinY() {
    if (minY != DUMMY) return minY;

    int Min = 800;
    for(int i = 0; i < size; i++) {
      if(polygons[i].MinY() < Min) {
        Min = polygons[i].MinY();
      }
    } 
    return minY = Min;
  }
  int MinZ() {
    if (minZ != DUMMY) return minZ;

    int Min = DUMMY - 1;              // overflow cycle (min - 1 = max) :P
    for(int i = 0; i < size; i++) {
      if(polygons[i].MinZ() < Min) {
        Min = polygons[i].MinZ();
      }
    } 
    return minZ = Min;
  }

  void resetBoundaries() {
    minX = DUMMY;
    minY = DUMMY;
    minZ = DUMMY;
    maxX = DUMMY;
    maxY = DUMMY;
    maxZ = DUMMY;
  }
/*
  friend bool operator<(const Polygon& l, const Polygon& r) {
    return l.MaxZ() < r.MaxZ();
  }*/

  Shape& resize(double factor, const Point<double>& center = Point<double>()) {
    for (int i = 0; i < size; ++i) {
      polygons[i].resize(factor, center);
    }
    this->center.scale(factor, center);
    resetBoundaries();
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
    resetBoundaries();
    return *this;
  }
  Shape& rotate(double degreeZ, const Point<double>& center = Point<double>(0, 0), double degreeX = 0, double degreeY = 0) {
    for (int i = 0; i < size; ++i) {
      polygons[i].rotate(degreeZ, center, degreeX, degreeY);
    }
    this->center.rotate(degreeZ, center, degreeX, degreeY);
    resetBoundaries();
    return *this;
  }
  Shape& rotateCenter(double degreeZ, double degreeX = 0, double degreeY = 0) {
    return rotate(degreeZ, this->center, degreeX, degreeY);
  }

  Polygon* polygons;
  int size;
  Point<double> center;

private:
  // Memo
  const int DUMMY = 0x80000000;
  int minX = DUMMY;
  int minY = DUMMY;
  int minZ = DUMMY;
  int maxX = DUMMY;
  int maxY = DUMMY;
  int maxZ = DUMMY;
};

#endif
