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
  blok* jalanboulevard;
  blok* jalankirigku;
  blok* jalanmesinmatik;
  blok* jalanintel;
  blok* jalantaman;
  blok* jalansunken;
  blok* jalanseblabtek;
  blok* jalansetlabtek;
  blok* jalansebperpus;
  blok* gangkanan;
  //blok* atap;
  Jalan(){
    jalanparkirankekiri = new blok(100,560,480,10,1,1,56);
    jalanparkirankekanan = new blok(100,560,0,10,1,1,20);
    jalanparkiran = new blok(100,560,0,10,1,48,1);
    jalanparkiranbelakang = new blok(650,560,120,10,1,36,1); 
    jalanboulevard = new blok(100,560,240,10,1,2,20); 
    jalankirigku = new blok(100,560,400,10,1,1,25);
    jalanintel = new blok(300,560,235,10,1,3,12);
    jalanmesinmatik = new blok(400,560,360,10,1,1,16);
    jalantaman = new blok(430,560,235,10,1,3,12);
    jalansunken = new blok(560,560,230,10,1,4,9);
    jalanseblabtek = new blok(300,560,0,10,1,48,1);
    jalansetlabtek = new blok(420,560,120,10,1,25,1);
    jalansebperpus = new blok(550,560,120,10,1,25,1);
    gangkanan = new blok(300,560,120,10,1,1,40);
  }
  void print(FrameBuffer& fb){
    jalanparkiran->print(fb);
    jalanparkiranbelakang->print(fb);
    jalanparkirankekiri->print(fb);
    jalanparkirankekanan->print(fb);
    jalankirigku->print(fb);
    jalanboulevard->print(fb);
    jalanintel->print(fb);
    jalanmesinmatik->print(fb);
    jalantaman->print(fb);
    jalansunken->print(fb);
    jalanseblabtek->print(fb);
    jalansetlabtek->print(fb);
    jalansebperpus->print(fb);
    gangkanan->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    jalanparkiran->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkiranbelakang->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekiri->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekanan->rotate(degreeZ,center,degreeX,degreeY);
    jalankirigku->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard->rotate(degreeZ,center,degreeX,degreeY);
    jalanintel->rotate(degreeZ,center,degreeX,degreeY);
    jalanmesinmatik->rotate(degreeZ,center,degreeX,degreeY);
    jalantaman->rotate(degreeZ,center,degreeX,degreeY);
    jalansunken->rotate(degreeZ,center,degreeX,degreeY);
    jalanseblabtek->rotate(degreeZ,center,degreeX,degreeY);
    jalansetlabtek->rotate(degreeZ,center,degreeX,degreeY);
    jalansebperpus->rotate(degreeZ,center,degreeX,degreeY);
    gangkanan->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif



