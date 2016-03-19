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
  
struct KumpulanGedung  {
  blok* labtekV;
  blok* labtekVI;
  blok* labtekVII;
  blok* labtekVIII;
  blok* kontrolPower;
  KumpulanGedung(){
    kontrolPower =  new blok(310,560,350,10,100,7,2);
    kontrolPower->setColor(200,200,0);
    labtekV =  new blok(320,560,230,10,100,11,3);
    labtekV->setColor(200,200,0);
    labtekVI =  new blok(370,560,230,10,100,11,3);
    labtekVI->setColor(200,200,0);
    labtekVII =  new blok(370,560,70,10,100,11,3);
    labtekVII->setColor(200,200,0);
    labtekVIII =  new blok(320,560,70,10,100,11,3);
    labtekVIII->setColor(200,200,0);
  }
  void print(FrameBuffer& fb){
    kontrolPower->print(fb);
    labtekV->print(fb);
    labtekVI->print(fb);
    labtekVII->print(fb);
    labtekVIII->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    kontrolPower->rotate(degreeZ,center,degreeX,degreeY);
    labtekV->rotate(degreeZ,center,degreeX,degreeY);
    labtekVI->rotate(degreeZ,center,degreeX,degreeY);
    labtekVII->rotate(degreeZ,center,degreeX,degreeY);
    labtekVIII->rotate(degreeZ,center,degreeX,degreeY);
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
  blok* jalangkumesin;
  blok* jalangkutokema;
  blok* jalansetlabtek;
  blok* jalansebperpus;
  blok* gangkanan;
  blok* jalansebgang1;
  blok* jalansebgang2;
  blok* jalansebgang3;
  //blok* atap;
  Jalan(){
    jalanparkirankekiri = new blok(100,560,480,10,1,1,56);
    jalanparkirankekanan = new blok(100,560,0,10,1,1,20);
    jalanparkiran = new blok(100,560,0,10,1,48,1);
    jalanparkiranbelakang = new blok(650,560,50,10,1,43,1);
    jalanseblabtek = new blok(300,560,0,10,1,48,1); 
    jalanboulevard = new blok(100,560,200,10,1,2,20); 
    jalankirigku = new blok(100,560,420,10,1,1,25);
    jalanintel = new blok(300,560,195,10,1,3,12);
    jalangkutokema = new blok(300,560,340,10,1,1,10);
    jalanmesinmatik = new blok(400,560,360,10,1,1,16);
    jalantaman = new blok(430,560,195,10,1,3,12);
    jalansunken = new blok(560,560,190,10,1,4,9);
    jalangkumesin = new blok(400,560,340,10,1,14,1);
    jalansetlabtek = new blok(420,560,50,10,1,32,1);
    jalansebperpus = new blok(550,560,50,10,1,32,1);
    gangkanan = new blok(300,560,50,10,1,1,40);
    jalansebgang1 = new blok(470,560,-70,10,1,13,1);
    jalansebgang1->rotate(0,Point<double>(475,560,-5),0,15);
    jalansebgang2 = new blok(520,560,-70,10,1,13,1);
    jalansebgang2->rotate(0,Point<double>(525,560,-5),0,15);
    jalansebgang3 = new blok(610,560,-70,10,1,13,2);
    jalansebgang3->rotate(0,Point<double>(610,560,-5),0,15);
  }
  ~Jalan(){
    delete jalanparkirankekiri;
    delete jalanparkirankekanan;
    delete jalanparkiran;
    delete jalanparkiranbelakang;
    delete jalanseblabtek;
    delete jalanboulevard;
    delete jalankirigku;
    delete jalanintel;
    delete jalangkutokema;
    delete jalanmesinmatik;
    delete jalantaman;
    delete jalansunken;
    delete jalangkumesin;
    delete jalansetlabtek;
    delete jalansebperpus;
    delete gangkanan;
    delete jalansebgang1; 
    delete jalansebgang2; 
    delete jalansebgang3; 
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
    jalangkumesin->print(fb);
    jalangkutokema->print(fb);
    jalantaman->print(fb);
    jalansunken->print(fb);
    jalanseblabtek->print(fb);
    jalansetlabtek->print(fb);
    jalansebperpus->print(fb);
    jalansebgang1->print(fb);
    jalansebgang2->print(fb);
    jalansebgang3->print(fb);
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
    jalangkumesin->rotate(degreeZ,center,degreeX,degreeY);
    jalangkutokema->rotate(degreeZ,center,degreeX,degreeY);
    jalantaman->rotate(degreeZ,center,degreeX,degreeY);
    jalansunken->rotate(degreeZ,center,degreeX,degreeY);
    jalanseblabtek->rotate(degreeZ,center,degreeX,degreeY);
    jalansetlabtek->rotate(degreeZ,center,degreeX,degreeY);
    jalansebperpus->rotate(degreeZ,center,degreeX,degreeY);
    gangkanan->rotate(degreeZ,center,degreeX,degreeY);
    jalansebgang1->rotate(degreeZ,center,degreeX,degreeY);
    jalansebgang2->rotate(degreeZ,center,degreeX,degreeY);
    jalansebgang3->rotate(degreeZ,center,degreeX,degreeY);
  }
};
struct ITB{
  Jalan* jalanitb;
  KumpulanGedung* gedungitb;
  ITB(){
    jalanitb=new Jalan();
    gedungitb=new KumpulanGedung();
  }
  void print(FrameBuffer& fb){
    jalanitb->print(fb);
    gedungitb->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    jalanitb->rotate(degreeZ,center,degreeX,degreeY);
    gedungitb->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif



