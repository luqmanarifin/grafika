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
  blok* ccBarat;
  blok* ccTimur;
  blok* labtekV;
  blok* labtekVI;
  blok* labtekVII;
  blok* labtekVIII;
  blok* kontrolPower;
  blok* gedungBio;
  blok* Biomedi;
  blok* TeknikKimia;
  blok* Biomedis;
  blok* Mkor;
  blok* SBM;
  blok* Mesin;
  blok* Mesin1;
  blok* Mektan;
  blok* PAU;
  blok* sebelahPAU;
  blok* Perpus;
  blok* cas;
  KumpulanGedung(){
    kontrolPower =  new blok(310,400,-350,10,30,-7,2);
    kontrolPower->setColor(200,200,0);
    gedungBio =  new blok(460,400,-300,10,30,-6,4);
    gedungBio->setColor(200,0,200);
    Biomedis =  new blok(525,400,-390,10,30,-5,3);
    Biomedis->setColor(200,0,200);
    Mkor =  new blok(595,400,-350,10,30,-9,2);
    Mkor->setColor(200,100,250);
    SBM =  new blok(625,400,-350,10,30,-9,2);
    SBM->setColor(200,0,200);
    Mesin =  new blok(470,400,-380,10,30,-9,5);
    Mesin->setColor(200,0,200);
    Mesin1 =  new blok(410,400,-420,10,30,-5,5);
    Mesin1->setColor(200,0,200);
    TeknikKimia =  new blok(510,400,-300,10,30,-6,4);
    TeknikKimia->setColor(0,0,200);
    labtekV =  new blok(320,400,-230,10,40,-11,3);
    labtekV->setColor(200,200,0);
    labtekVI =  new blok(370,400,-230,10,40,-11,3);
    labtekVI->setColor(200,200,0);
    labtekVII =  new blok(370,400,-70,10,40,-11,3);
    labtekVII->setColor(200,200,0);
    labtekVIII =  new blok(320,400,-70,10,40,-11,3);
    labtekVIII->setColor(200,200,0);
    Mektan =  new blok(430,400,-80,10,40,-4,11);
    Mektan->setColor(200,100,0);
    ccBarat =  new blok(260,400,-230,10,40,-6,2);
    ccBarat->setColor(40,0,200);
    ccTimur =  new blok(260,400,-140,10,40,-6,2);
    ccTimur->setColor(40,0,200);
    sebelahPAU =  new blok(570,400,-290,10,70,-5,5);
    sebelahPAU->setColor(0,0,200);
    PAU =  new blok(570,400,-240,10,70,-4,8);
    PAU->setColor(0,0,200);
    Perpus =  new blok(570,400,-120,10,30,-6,6);
    Perpus->setColor(0,0,200);
    cas =  new blok(570,400,-60,10,100,-5,7);
    cas->setColor(0,0,200);
  }
  void print(FrameBuffer& fb){
    SBM->print(fb);
    Mkor->print(fb);
    kontrolPower->print(fb);
    Mesin->print(fb);
    Mesin1->print(fb);
    TeknikKimia->print(fb);
    Biomedis->print(fb);
    gedungBio->print(fb);
    labtekV->print(fb);
    labtekVI->print(fb);
    labtekVII->print(fb);
    labtekVIII->print(fb);
    Mektan->print(fb);
    ccBarat->print(fb);
    ccTimur->print(fb);
    sebelahPAU->print(fb);
    PAU->print(fb);
    Perpus->print(fb);
    cas->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    SBM->rotate(degreeZ,center,degreeX,degreeY);
    Mkor->rotate(degreeZ,center,degreeX,degreeY);
    gedungBio->rotate(degreeZ,center,degreeX,degreeY);
    Biomedis->rotate(degreeZ,center,degreeX,degreeY);
    Mesin->rotate(degreeZ,center,degreeX,degreeY);
    Mesin1->rotate(degreeZ,center,degreeX,degreeY);
    kontrolPower->rotate(degreeZ,center,degreeX,degreeY);
    TeknikKimia->rotate(degreeZ,center,degreeX,degreeY);
    labtekV->rotate(degreeZ,center,degreeX,degreeY);
    labtekVI->rotate(degreeZ,center,degreeX,degreeY);
    labtekVII->rotate(degreeZ,center,degreeX,degreeY);
    labtekVIII->rotate(degreeZ,center,degreeX,degreeY);
    Mektan->rotate(degreeZ,center,degreeX,degreeY);
    ccBarat->rotate(degreeZ,center,degreeX,degreeY);
    ccTimur->rotate(degreeZ,center,degreeX,degreeY);
    PAU->rotate(degreeZ,center,degreeX,degreeY);
    sebelahPAU->rotate(degreeZ,center,degreeX,degreeY);
    Perpus->rotate(degreeZ,center,degreeX,degreeY);
    cas->rotate(degreeZ,center,degreeX,degreeY);
  }
};

struct Jalan{
  blok* tanah;
  blok* jalanparkiran;
  blok* jalanparkiranbelakang;
  blok* jalanparkirankekiri;
  blok* jalanparkirankekanan;
  blok* jalanboulevard;
  blok* jalanboulevard1;
  blok* jalanboulevard2;
  blok* jalankirigku;[
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
    tanah = new blok(100,398,70,10,-1,-55,56);
    tanah->setColor(50,170,50);
    jalanparkirankekiri = new blok(100,400,-480,10,1,-1,56);
    jalanparkirankekanan = new blok(100,400,0,10,1,-1,20);
    jalanparkiran = new blok(100,400,0,10,1,-48,1);
    jalanparkiranbelakang = new blok(650,400,-50,10,1,-43,1);
    jalanseblabtek = new blok(300,400,0,10,1,-48,1); 
    jalanboulevard = new blok(100,400,-200,10,1,-2,20);
    jalanboulevard1 = new blok(210,400,-220,10,1,-10,1);
    jalanboulevard2 = new blok(210,400,-310,10,1,-1,10);
    jalankirigku = new blok(100,400,-420,10,1,-1,25);
    jalanintel = new blok(300,400,-195,10,1,-3,12);
    jalangkutokema = new blok(300,400,-340,10,1,-1,10);
    jalanmesinmatik = new blok(400,400,-360,10,1,-1,16);
    jalantaman = new blok(430,400,-195,10,1,-3,12);
    jalansunken = new blok(560,400,-190,10,1,-4,9);
    jalangkumesin = new blok(400,400,-340,10,1,-14,1);
    jalansetlabtek = new blok(420,400,-50,10,1,-32,1);
    jalansebperpus = new blok(550,400,-50,10,1,-32,1);
    gangkanan = new blok(300,400,-50,10,1,-1,40);
    jalansebgang1 = new blok(470,400,70,10,1,-13,1);
    jalansebgang1->rotate(0,Point<double>(475,400,5),0,15);
    jalansebgang2 = new blok(520,400,70,10,1,-13,1);
    jalansebgang2->rotate(0,Point<double>(525,400,5),0,15);
    jalansebgang3 = new blok(610,400,70,10,1,-13,2);
    jalansebgang3->rotate(0,Point<double>(610,400,5),0,15);
  }
  ~Jalan(){
    delete tanah;
    delete jalanparkirankekiri;
    delete jalanparkirankekanan;
    delete jalanparkiran;
    delete jalanparkiranbelakang;
    delete jalanseblabtek;
    delete jalanboulevard;
    delete jalanboulevard1;
    delete jalanboulevard2;
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
    //tanah->print(fb);
    jalanparkiran->print(fb);
    jalanparkiranbelakang->print(fb);
    jalanparkirankekiri->print(fb);
    jalanparkirankekanan->print(fb);
    jalankirigku->print(fb);
    jalanboulevard->print(fb);
    jalanboulevard1->print(fb);
    jalanboulevard2->print(fb);
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
    tanah->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkiran->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkiranbelakang->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekiri->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekanan->rotate(degreeZ,center,degreeX,degreeY);
    jalankirigku->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard1->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard2->rotate(degreeZ,center,degreeX,degreeY);
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
    gedungitb=new KumpulanGedung();
    jalanitb=new Jalan();
  }
  ~ITB(){
    delete gedungitb;
    delete jalanitb;
  }
  
  void print(FrameBuffer& fb){
    gedungitb->print(fb);
    jalanitb->print(fb);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    jalanitb->rotate(degreeZ,center,degreeX,degreeY);
    gedungitb->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif



