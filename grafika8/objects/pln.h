#ifndef __Pln_H_
#define __Pln_H_

#include <shape.h> 

struct Pln : public Shape {
  int x,s,y,z;
  Pln(int _x,int _y, int _z, int _s, int h,int mode){
    x=_x;
    y=_y;
    s=_s;
    //miring kiri depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,s+z))
      .addPoint(Point<double>(x+s,y,+z))
      .addPoint(Point<double>(x+s,y+h,+z))
      .addPoint(Point<double>(x,y+h,s+z))
    );
    //depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x+s,y,+z))
      .addPoint(Point<double>(x+(2*s),y,+z))
      .addPoint(Point<double>(x+(2*s),y+h,+z))
      .addPoint(Point<double>(x+s,y+h,+z))
    ); 
    //miring kanan depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y,+z))
      .addPoint(Point<double>(x+(4*s),y,(2*s+z)))
      .addPoint(Point<double>(x+(4*s),y+h,(2*s+z)))
      .addPoint(Point<double>(x+(2*s),y+h,+z))
    );
    //dekor
    if(mode==1){
      //tengah atas
      addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y+h,+z+s/2))
      .addPoint(Point<double>(x+(4*s),y+h,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s)-s/2,y+h-s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(2*s)+s/2,y+h-s/4,+z+s/2))
      );
      //tengah bawah
      addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y,+z+s/2))
      .addPoint(Point<double>(x+(4*s),y,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s)-s/2,y+s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(2*s)+s/2,y+s/4,+z+s/2))
      );
      //tengah 
      addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s)+s/2,y+s/4,+z+s/2))
      .addPoint(Point<double>(x+(4*s)-s/2,y+s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s)-s/2,y+h-s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(2*s)+s/2,y+h-s/4,+z+s/2))
      );
      //samping kiri
      addPolygon(Polygon()
        .addPoint(Point<double>(x+(2*s),y+h,+z+s/2))
        .addPoint(Point<double>(x+(2*s)+s/2,y+h-s/4,+z+s/2))
        .addPoint(Point<double>(x+(2*s)+s/2,y+s/4,+z+s/2))
        .addPoint(Point<double>(x+(2*s),y,+z+s/2))
      );
      //samping kanan
      addPolygon(Polygon()
      .addPoint(Point<double>(x+(4*s),y+h,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s)-s/2,y+h-s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s)-s/2,y+s/4,(2*s+z-s/2)))
      .addPoint(Point<double>(x+(4*s),y,(2*s+z-s/2)))
      
      );
    }
    //samping kanan
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(4*s),y,(2*s+z)))
      .addPoint(Point<double>(x+(4*s),y,(6*s+z)))
      .addPoint(Point<double>(x+(4*s),y+h,(6*s+z)))
      .addPoint(Point<double>(x+(4*s),y+h,(2*s+z)))
    );
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(4*s),y,(6*s+z)))
      .addPoint(Point<double>(x,y,(6*s+z)))
      .addPoint(Point<double>(x,y+h,(6*s+z)))
      .addPoint(Point<double>(x+(4*s),y+h,(6*s+z)))
    );
    //samping kiri
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,(6*s+z)))
      .addPoint(Point<double>(x,y,s+z))
      .addPoint(Point<double>(x,y+h,s+z))
      .addPoint(Point<double>(x,y+h,(6*s+z)))
    );
    //bawah
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y+h,s+z))
      .addPoint(Point<double>(x+s,y+h,+z))
      .addPoint(Point<double>(x+(2*s),y+h,+z))
      .addPoint(Point<double>(x+(4*s),y+h,(2*s+z)))
      .addPoint(Point<double>(x+(4*s),y+h,(6*s+z)))
      .addPoint(Point<double>(x,y+h,(6*s+z)))
      .addPoint(Point<double>(x,y+h,s+z))
    );
    //atas
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,s+z))
      .addPoint(Point<double>(x+s,y,+z))
      .addPoint(Point<double>(x+(2*s),y,+z))
      .addPoint(Point<double>(x+(4*s),y,(2*s+z)))
      .addPoint(Point<double>(x+(4*s),y,(6*s+z)))
      .addPoint(Point<double>(x,y,(6*s+z)))
      .addPoint(Point<double>(x,y,s+z))
    );
  }
};

struct GedungPln  {
  Pln* utama;
  Pln* atap;
  GedungPln(){
    utama = new Pln(150,300,0,50,100,1);
    atap = new Pln(140,270,0-15,55,30,0);
    
  }
  void print(FrameBuffer& fb){
    utama->print(fb);
    atap->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    utama->rotate(degreeZ,center,degreeX,degreeY);
    atap->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif
