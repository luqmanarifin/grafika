#ifndef __gedung_H_
#define __gedung_H_

#include "../../lib/shape.h" 
struct atap_labtek : public Shape {
  int x,s,y,z;
  atap_labtek (int _x,int _y, int _z, int _s, int h,int mode){
    x=_x;
    y=_y;
    s=_s;
    //depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,+z))
      .addPoint(Point<double>(x+(2*s),y,+z))
      .addPoint(Point<double>(x+(2*s),y+h,+z))
      .addPoint(Point<double>(x,y+h,+z))
    ); 
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,(5*s+z)))
      .addPoint(Point<double>(x+(2*s),y,(5*s+z)))
      .addPoint(Point<double>(x+(2*s),y+h,(5*s+z)))
      .addPoint(Point<double>(x,y+h,(5*s+z)))
    ); 
    
    //atas
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y,z))
      .addPoint(Point<double>(x+(2*s),y,(5*s+z)))
      .addPoint(Point<double>(x,y,(5*s+z)))
      .addPoint(Point<double>(x,y,z))
    );
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y+h,z))
      .addPoint(Point<double>(x+(2*s),y+h,(5*s+z)))
      .addPoint(Point<double>(x,y+h,(5*s+z)))
      .addPoint(Point<double>(x,y+h,z))
    );
    //samping kiri
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,(5*s+z)))
      .addPoint(Point<double>(x,y,z))
      .addPoint(Point<double>(x,y+h,z))
      .addPoint(Point<double>(x,y+h,(5*s+z)))
    );
    //samping kanan
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(2*s),y,(5*s+z)))
      .addPoint(Point<double>(x+(2*s),y,z))
      .addPoint(Point<double>(x+(2*s),y+h,z))
      .addPoint(Point<double>(x+(2*s),y+h,(5*s+z)))
    );    
  
  }
};
struct blok : public Shape {
  int x,s,y,z;
  blok(int _x,int _y, int _z, int _s, int h,int p,int l){
    x=_x;
    y=_y;
    s=_s;
    z=_z;
    //depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,+z))
      .addPoint(Point<double>(x+(l*s),y,+z))
      .addPoint(Point<double>(x+(l*s),y+h,+z))
      .addPoint(Point<double>(x,y+h,+z))
    ); 
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,(p*s+z)))
      .addPoint(Point<double>(x+(l*s),y,(p*s+z)))
      .addPoint(Point<double>(x+(l*s),y+h,(p*s+z)))
      .addPoint(Point<double>(x,y+h,(p*s+z)))
    );
    //atas
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(l*s),y,z))
      .addPoint(Point<double>(x+(l*s),y,(p*s+z)))
      .addPoint(Point<double>(x,y,(p*s+z)))
      .addPoint(Point<double>(x,y,z))
    );
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(l*s),y+h,z))
      .addPoint(Point<double>(x+(l*s),y+h,(p*s+z)))
      .addPoint(Point<double>(x,y+h,(p*s+z)))
      .addPoint(Point<double>(x,y+h,z))
    );
    //samping kiri
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,(p*s+z)))
      .addPoint(Point<double>(x,y,z))
      .addPoint(Point<double>(x,y+h,z))
      .addPoint(Point<double>(x,y+h,(p*s+z)))
    );
    //samping kanan
    addPolygon(Polygon()
      .addPoint(Point<double>(x+(l*s),y,(p*s+z)))
      .addPoint(Point<double>(x+(l*s),y,z))
      .addPoint(Point<double>(x+(l*s),y+h,z))
      .addPoint(Point<double>(x+(l*s),y+h,(p*s+z)))
    );
  }
  
};  
struct Gedungcc  {
  blok* utama;
  blok* atap;
  Gedungcc(){
    atap = new blok(145,270,0-15,55,30,5,2); 
    utama = new blok(150,300,0,50,100,5,2);
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

struct Jalan{
  blok* jalanparkiran;
  blok* jalanparkiranbelakang;
  blok* jalanparkirankekiri;
  blok* jalanparkirankekanan;
  //blok* atap;
  Jalan(){  
    
    jalanparkirankekiri = new blok(100,560,480,10,5,1,56);
    jalanparkirankekanan = new blok(100,560,0,10,5,1,56);
    jalanparkiran = new blok(100,560,0,10,5,48,1);
    jalanparkiranbelakang = new blok(650,560,0,10,5,48,1); 
  }
  void print(FrameBuffer& fb){
    jalanparkiran->print(fb);
    jalanparkiranbelakang->print(fb);
    jalanparkirankekiri->print(fb);
    jalanparkirankekanan->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    jalanparkiran->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkiranbelakang->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekiri->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekanan->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif



