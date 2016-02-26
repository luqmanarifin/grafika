#ifndef __KUBUS_H_
#define __KUBUS_H_

#include "../../lib/polygon.h" 
struct Kubus : public Polygon {
  Kubus(double x,double y, int s) {
    /*addPoint(Point<double>(x,y,0));
    addPoint(Point<double>(x+s,y,0));
    addPoint(Point<double>(x+s+(s/2),y-(s/2),0));
    addPoint(Point<double>(x+s+(s/2),y-s-(s/2),0));    
    addPoint(Point<double>(x+(s/2),y-s-(s/2),0));
    addPoint(Point<double>(x,y-s,0));*/
    addPoint(Point<double>(x,y,0));
    addPoint(Point<double>(x+s,y,0));
    addPoint(Point<double>(x+s,y,s));
    addPoint(Point<double>(x+s,y-s,s));    
    addPoint(Point<double>(x,y-s,s));
    addPoint(Point<double>(x,y-s,0));
  }
  void move3d() {
    for (int i = 0; i < size; ++i) {
      points[i].move(points[i].z/2, 0-(points[i].z/2));
    }
  }
  void bmove3d() {
    for (int i = 0; i < size; ++i) {
      points[i].move(0-(points[i].z/2), (points[i].z/2));
    }
  }
  void rotate3d(double degreeZ, const Point<double>& center = Point<double>(), double degreeX =0 , double degreeY=0) {
   // Point<double> e = Point<double>(center.x,center.y,center.z);
    for (int i = 0; i < size; ++i) {
      //e.z = points[i].z;
      points[i].rotate(degreeZ, center,degreeX,degreeY);
    }
  }
  void print3d(FrameBuffer& fb, int red, int green, int blue, int alpha) {
    move3d();
    print(fb,red,green,blue,alpha);
    bmove3d();
  }
  void print3d(FrameBuffer& fb) {
    print3d(fb, 255, 255, 255, 0);
  }
  void printpoint() {
    for (int i = 0; i < size; ++i) {
      cout << points[i];
    }
    cout << endl;
  }
  
};

#endif
