#ifndef CURVE_H_
#define CURVE_H_ 1

#include <bits/stdc++.h>
#include "point.h"
#include "line.h"
#include "vector.h"
#include "framebuffer.h"

class curve
{
public:
  curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d,  Color _color);
  ~curve();
  curve& setColor(Color _color);
  void print(FrameBuffer& fb);
  double ratio(double a, double b);
private:
  double errorRatio(double a, double b);
  curve* leftChild = NULL;
  curve* rightChild = NULL;
  line* straightLine = NULL;
  Color color;
};

curve::~curve() {
  if (leftChild != NULL) delete(leftChild);
  if (rightChild != NULL) delete(rightChild);
  if (straightLine != NULL) delete(straightLine);
}

curve& curve::setColor(Color _color) { color = _color; return *this; }

double curve::ratio(double a, double b) { return abs(a / b); }

curve::curve(Point<double> a, Point<double> b, Point<double> c, Point<double> d,  Color _color = Color::WHITE) 
{
  Vector<double> ab(a, b); 
  Vector<double> bc(b, c); 
  Vector<double> cd(c, d);
  double magn1 = ab.magnitude * bc.magnitude;
  double magn2 = bc.magnitude * cd.magnitude;
  color = _color;
 // printf("%d %d %d",color.red,color.green,color.blue);
  //cout << color.red << " " <<color.green<<" " <<color.blue<<endl;
  
  //cout << ratio( Vector<double>::dot( ab, bc ), magn1 ) << " " << ratio( Vector<double>::dot( bc, cd ), magn2 ) <<endl; 
  if (ratio( Vector<double>::dot( ab, bc ), magn1 ) > 0.995 &&
      ratio( Vector<double>::dot( bc, cd ), magn2 ) > 0.995 ) {
      straightLine = new line((int)round(a.x), (int)round(a.y), (int)round(d.x), (int)round(d.y), color);
      //cout << "sL " <<straightLine->x0<<","<<straightLine->y0<<" "<<straightLine->x1<<","<<straightLine->y1<<endl;
      //straightLine->print(fb);
  } else {
    Point<double> d1 = (a + b) * 0.5;
    Point<double> d2 = (b*2 + a + c) * 0.25;
    Point<double> d3 = (a + b*3 + c*3 + d) * 0.125;
    Point<double> d4 = (c*2 + b + d) * 0.25;
    Point<double> d5 = (c + d) * 0.5;

    leftChild = new curve(a, d1, d2, d3,  _color);
    rightChild = new curve(d3, d4, d5, d,  _color);
  }
}

void curve::print(FrameBuffer& fb) {
  if (straightLine != NULL) {
    //cout<<straightLine->x0<<","<<straightLine->y0<<" "<<straightLine->x1<<","<<straightLine->y1<<endl;
    straightLine->print(fb);
  }
  else{
    //cout<<"masih di looping"<<endl;
    leftChild->print(fb);
    rightChild->print(fb);
    
  }
}

#endif
