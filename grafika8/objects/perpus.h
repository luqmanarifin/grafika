#ifndef __Perpus_H_
#define __Perpus_H_

#include "../../lib/shape.h" 
struct Perpus : public Shape {
  int x1,x2;
  int y1,y2;
  int z1,z2; 
  int s;
  Perpus(int _s) {
    s = _s;
    x1 = 310;
    x2=350;
    y1=335;
    y2=300;
    z1 =0; 
    z2 = _s;
    
    addPolygon(Polygon() 
         // sisi depan
      .addCurve(Point<double>(x1, y1,z1), Point<double>(x1, y1-5,z1), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y2,z2))
      .addPoint(Point<double>(x1, y1-35,z1+s+35))
      .addCurve(Point<double>(x1, y1-35,z1+s+35), Point<double>(x1, y1-40,z1+s+35), Point<double>(x1, y2-30,z2/3+s+35), Point<double>(x1, y2-35,z2+s+35))
      .addPoint(Point<double>(x1, y2-35,z2+s+150))
      .addPoint(Point<double>(x1, y1,z2+s+150))
    );
    addPolygon(Polygon() 
         // sisi depan
      .addCurve(Point<double>(x1, y1,z1), Point<double>(x1, y1-5,z1), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y2,z2))
      .addPoint(Point<double>(x1, y1-35,z1+s+35))
      .addCurve(Point<double>(x1, y1-35,z1+s+35), Point<double>(x1, y1-40,z1+s+35), Point<double>(x1, y2-30,z2/3+s+35), Point<double>(x1, y2-35,z2+s+35))
      .addPoint(Point<double>(x1, y2-35,z2+s+70))
      .addPoint(Point<double>(x2, y2-35,z2+s+70))
      .addCurve(Point<double>(x2, y2-35,z2+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y1-35,z1+s+35))
      .addPoint(Point<double>(x2, y2,z1+s+35))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .setColor(233,233,233,0)
    );
    
    x1+=40;
    x2+=40;
    z1 -=s;
    z2 -=s;
    
    addPolygon(Polygon() 
         // sisi depan
      .addCurve(Point<double>(x1, y1,z1), Point<double>(x1, y1-5,z1), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y2,z2))
      .addPoint(Point<double>(x1, y1-35,z1+s+35))
      .addCurve(Point<double>(x1, y1-35,z1+s+35), Point<double>(x1, y1-40,z1+s+35), Point<double>(x1, y2-30,z2/3+s+35), Point<double>(x1, y2-35,z2+s+35))
       .addPoint(Point<double>(x1, y2-35,z2+s+70))
       .addPoint(Point<double>(x2, y2-35,z2+s+70))
      .addCurve(Point<double>(x2, y2-35,z2+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y1-35,z1+s+35))
      .addPoint(Point<double>(x2, y2,z1+s+35))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .setColor(233,233,233,0)
    );
    
    addPolygon(Polygon() 
         // sisi depan
      //.addPoint(Point<double>(x2, y2-35,z2+s+70))
      
      .addCurve(Point<double>(x2, y2-35,z2+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y1-35,z1+s+35))
      .addPoint(Point<double>(x2, y2,z1+s+35))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      
      
      .addCurve(Point<double>(x2, y1,z1+s), Point<double>(x2, y1-5,z1+s), Point<double>(x2, y2+5,z2/3+s), Point<double>(x2, y2,z2+s))
      .addPoint(Point<double>(x2, y2,z1+2*s+35))
      .addCurve(Point<double>(x2, y1-35,z1+2*s+35), Point<double>(x2, y1-40,z1+2*s+35), Point<double>(x2, y2-30,z2/3+2*s+35), Point<double>(x2, y2-35,z2+2*s+35))
      
      //.addPoint(Point<double>(x2, y1,z2+s+70))
      
      .setColor(200,200,200,0)
    );
    addPolygon(Polygon()
    
      .addPoint(Point<double>(x2, y2-35,z2+s+70))
      
      .addCurve(Point<double>(x2, y2-35,z2+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y1-35,z1+s+35))
      .addPoint(Point<double>(x2, y2,z1+s+35))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .addPoint(Point<double>(x2, y1,z2+s+70))
      );
    x1+=40;
    x2+=40;
    z1 -=s;
    z2 -=s;
    
    addPolygon(Polygon() 
         // sisi depan
      //.addPoint(Point<double>(x1, y2-35,z2+s+70))
      
      .addCurve(Point<double>(x1, y2-35,z2+s+35), Point<double>(x1, y2-30,z2/3+s+35), Point<double>(x1, y1-40,z1+s+35), Point<double>(x1, y1-35,z1+s+35))
      .addPoint(Point<double>(x1, y2,z1+s+35))
      .addCurve(Point<double>(x1, y2,z2), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y1-5,z1), Point<double>(x1, y1,z1))
      
      
      .addCurve(Point<double>(x1, y1,z1+s), Point<double>(x1, y1-5,z1+s), Point<double>(x1, y2+5,z2/3+s), Point<double>(x1, y2,z2+s))
      .addPoint(Point<double>(x1, y2,z1+2*s+35))
      .addCurve(Point<double>(x1, y1-35,z1+2*s+35), Point<double>(x1, y1-40,z1+2*s+35), Point<double>(x1, y2-30,z2/3+2*s+35), Point<double>(x1, y2-35,z2+2*s+35))
      
      //.addPoint(Point<double>(x1, y1,z2+s+70))
      
      .setColor(200,200,200,0)
    );
    addPolygon(Polygon() 
         // sisi depan
      .addCurve(Point<double>(x1, y1,z1), Point<double>(x1, y1-5,z1), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y2,z2))
      .addPoint(Point<double>(x1, y1-35,z1+s+35))
      .addCurve(Point<double>(x1, y1-35,z1+s+35), Point<double>(x1, y1-40,z1+s+35), Point<double>(x1, y2-30,z2/3+s+35), Point<double>(x1, y2-35,z2+s+35))
       .addPoint(Point<double>(x1, y2-35,z2+s+70))
       .addPoint(Point<double>(x2, y2-35,z2+s+70))
      .addCurve(Point<double>(x2, y2-35,z2+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y1-35,z1+s+35))
      .addPoint(Point<double>(x2, y2,z1+s+35))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .setColor(233,233,233,0)
    );
    
        
    
    
    
    addPolygon(Polygon() 
      .addCurve(Point<double>(x2, y1,z1), Point<double>(x2, y1-5,z1), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y2,z2))
      .addPoint(Point<double>(x2, y1-35,z1+s+35))
      .addCurve(Point<double>(x2, y1-35,z1+s+35), Point<double>(x2, y1-40,z1+s+35), Point<double>(x2, y2-30,z2/3+s+35), Point<double>(x2, y2-35,z2+s+35))
      .addPoint(Point<double>(x2, y2-35,z2+2*s+150))
      .addPoint(Point<double>(x2, y1,z2+2*s+150))
    );
    addPolygon(Polygon() 
      .addPoint(Point<double>(x2, y2-35,z2+2*s+150))
      .addPoint(Point<double>(x2, y1,z2+2*s+150))
      .addPoint(Point<double>(x2-120, y1,z2+2*s+150))
      .addPoint(Point<double>(x2-120, y2-35,z2+2*s+150))
    );
    
    
    /*y1 += 35; 
    y2 += 35;
    z1 +=s;
    z2 +=s;
    addPolygon(Polygon()          // sisi depan
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .setColor(233,233,233,0)
    );
    y1 += 35; 
    y2 += 35;
    z1 -=s;
    z2-=s;
    addPolygon(Polygon()          // sisi depan
      .addCurve(Point<double>(x1, y1,z1), Point<double>(x1, y1-5,z1), Point<double>(x1, y2+5,z2/3), Point<double>(x1, y2,z2))
      .addCurve(Point<double>(x2, y2,z2), Point<double>(x2, y2+5,z2/3), Point<double>(x2, y1-5,z1), Point<double>(x2, y1,z1))
      .setColor(233,233,233,0)
    );*/
    /*
    addPolygon(Polygon()          // sisi samping
      .addCurve(Point<double>(x1, y1,0), Point<double>(x1, y1-5,0), Point<double>(x1, y2+5,s/3), Point<double>(x1, y2,s))
      .addPoint(Point<double>(x1, y1,s))
      .setColor(Color::WHITE)
    );
    addPolygon(Polygon()          // sisi samping
      .addCurve(Point<double>(x2, y1,0), Point<double>(x2, y1-5,0), Point<double>(x2, y2+5,s/3), Point<double>(x2, y2,s))
      .addPoint(Point<double>(x2, y1,s))
      .setColor(Color::WHITE)
    );
    addPolygon(Polygon()          // sisi samping
      .addPoint(Point<double>(x2, y2,s))
      .addPoint(Point<double>(x2, y1,s))
      .addPoint(Point<double>(x1, y1,s))
      .addPoint(Point<double>(x1, y2,s))
      .setColor(Color:: BLUE)
    );
    addPolygon(Polygon()          // sisi samping
      .addPoint(Point<double>(x2, y1,0))
      .addPoint(Point<double>(x2, y1,s))
      .addPoint(Point<double>(x1, y1,s))
      .addPoint(Point<double>(x1, y1,0))
      .setColor(Color:: BLUE)
    );*/
    
  }
  
};

#endif
