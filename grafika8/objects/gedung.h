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
struct bengkok : public Shape {
  int x,s,y,z;
  bengkok(int _x,int _y, int _z, int _s, int h,int p,int l){
    x=_x;
    y=_y;
    s=_s;
    z=_z;
    //depan
    addPolygon(Polygon()
      .addPoint(Point<double>(x,y,+z))
      .addPoint(Point<double>(x+s,y,+z))
      .addPoint(Point<double>(x+s,y+h,+z))
      .addPoint(Point<double>(x,y+h,+z))
    ); 
    //atas
    addPolygon(Polygon()
      .addCurve(curve(Point<double>(x, y,z), Point<double>(x+(l)*2*s/9, y,(p)*s/3+z), Point<double>(x+(((l))*s/3),y, (p)*2*s/3+z), Point<double>(x+((l)*s),y,(p)*s+ z)))
      .addCurve(curve(Point<double>(x+((l)*s),y,(p-1)*s+ z), Point<double>(x+((l)*s/3),y,(p-1)*2*s/3+z), Point<double>(x+(((l))*2*s/9), y,(p-1)*s/3+z), Point<double>(x+s, y,z)))
    );
    //bawah
    addPolygon(Polygon()
      .addCurve(curve(Point<double>(x, y+h,z), Point<double>(x+(l)*2*s/9, y+h,(p)*s/3+z), Point<double>(x+(((l))*s/3),y+h, (p)*2*s/3+z), Point<double>(x+((l)*s),y+h,(p)*s+ z)))
      .addCurve(curve(Point<double>(x+((l)*s),y+h,(p-1)*s+ z), Point<double>(x+((l)*s/3),y+h,(p-1)*2*s/3+z), Point<double>(x+(((l))*2*s/9), y+h,(p-1)*s/3+z), Point<double>(x+s, y+h,z)))
    );
    //samping kiri
    addPolygon(Polygon()
      .addCurve(curve(Point<double>(x, y,z), Point<double>(x+(l)*2*s/9, y,(p)*s/3+z), Point<double>(x+(((l))*s/3),y, (p)*2*s/3+z), Point<double>(x+((l)*s),y,(p)*s+ z)))
      .addCurve(curve(Point<double>(x+((l)*s),y+h,(p)*s+ z), Point<double>(x+(((l))*s/3),y+h, (p)*2*s/3+z), Point<double>(x+(l)*2*s/9, y+h,(p)*s/3+z), Point<double>(x, y+h,z)))
    );
    //samping kanan
    addPolygon(Polygon()
      .addCurve(curve(Point<double>(x+((l)*s),y,(p-1)*s+ z), Point<double>(x+((l)*s/3),y,(p-1)*2*s/3+z), Point<double>(x+(((l))*2*s/9), y,(p-1)*s/3+z), Point<double>(x+s, y,z)))
      .addCurve(curve(Point<double>(x+s, y+h,z), Point<double>(x+(((l))*2*s/9), y+h,(p-1)*s/3+z), Point<double>(x+((l)*s/3),y+h,(p-1)*2*s/3+z), Point<double>(x+((l)*s),y+h,(p-1)*s+ z)))
    );
    //belakang
    addPolygon(Polygon()
      .addPoint(Point<double>(x+l*s,y,(p-1)*s+ z))
      .addPoint(Point<double>(x+l*s,y,(p)*s+ z))
      .addPoint(Point<double>(x+l*s,y+h,(p)*s+ z))
      .addPoint(Point<double>(x+l*s,y+h,(p-1)*s+ z))
    );
  }
  
};  
struct Gedungcc  {
  blok* utama;
  blok* atap;
  Gedungcc(){
    atap = new blok(300+145,270,0-15,55,30,5,2); 
    utama = new blok(300+150,300,0,50,100,5,2);
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
  
struct KumpulanKubus  {

  blok *stei,*fmipa,*fsrd,*fitb,*fttm,*sith,*sf,*sbm,*umum,*other,*ftsl,*sappk,*ftmd,*fti;
  int UJUNG_X2 = 1100;
  int UJUNG_Y2 = 100;
  KumpulanKubus(){
      
    Point<double>* center= new Point<double> (UJUNG_X2,UJUNG_Y2,0);
    stei = new blok(UJUNG_X2-20, UJUNG_Y2,0, 10,10,1,1);
    stei->setColor(200,200,0);
	  stei->rotate(0,*center,-45,0);
	  stei->rotate(0,*center,0,-45); center = new Point<double>(UJUNG_X2,UJUNG_Y2+20,0);
	  
    fmipa = new blok(UJUNG_X2-20, UJUNG_Y2+20,0, 10,10,1,1);
    fmipa->setColor(100,150,0);
	  fmipa->rotate(0,*center,-45,0);
	  fmipa->rotate(0,*center,0,-45);
	
	  center = new Point<double>(UJUNG_X2,UJUNG_Y2+40,0);
    fsrd = new blok(UJUNG_X2-20, UJUNG_Y2+40,0, 10,10,1,1);
    fsrd->setColor(170,60,30);
	  fsrd->rotate(0,*center,-45,0);
	  fsrd->rotate(0,*center,0,-45);
	
	  center = new Point<double>(UJUNG_X2,UJUNG_Y2+60,0);
     sappk = new blok(UJUNG_X2-20, UJUNG_Y2+60,0, 10,10,1,1);
    sappk->setColor(130,130,50);
	  sappk->rotate(0,*center,-45,0);
	  sappk->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+80,0);
     fttm = new blok(UJUNG_X2-20, UJUNG_Y2+80,0, 10,10,1,1);
    fttm->setColor(30,160,190);
	  fttm->rotate(0,*center,-45,0);
	  fttm->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+100,0);
     sith = new blok(UJUNG_X2-20, UJUNG_Y2+100,0, 10,10,1,1);
    sith->setColor(50,50,0);
	  sith->rotate(0,*center,-45,0);
	  sith->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+120,0);
     fti = new blok(UJUNG_X2-20, UJUNG_Y2+120,0, 10,10,1,1);
    fti->setColor(0,70,200);
	  fti->rotate(0,*center,-45,0);
	  fti->rotate(0,*center,0,-45);
	
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+140,0);
     fitb = new blok(UJUNG_X2-20, UJUNG_Y2+140,0, 10,10,1,1);
    fitb->setColor(230,230,50);
	  fitb->rotate(0,*center,-45,0);
	  fitb->rotate(0,*center,0,-45);
    
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+160,0);
     ftmd = new blok(UJUNG_X2-20, UJUNG_Y2+160,0, 10,10,1,1);
    ftmd->setColor(50,0,200);
	  ftmd->rotate(0,*center,-45,0);
	  ftmd->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+180,0);
     ftsl = new blok(UJUNG_X2-20, UJUNG_Y2+180,0, 10,10,1,1);
    ftsl->setColor(230,230,0);
	  ftsl->rotate(0,*center,-45,0);
	  ftsl->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+200,0);
     sf = new blok(UJUNG_X2-20, UJUNG_Y2+200,0, 10,10,1,1);
    sf->setColor(170,170,0);
	  sf->rotate(0,*center,-45,0);
	  sf->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+220,0);
     sbm = new blok(UJUNG_X2-20, UJUNG_Y2+220,0, 10,10,1,1);
    sbm->setColor(100,0,100);
	  sbm->rotate(0,*center,-45,0);
	  sbm->rotate(0,*center,0,-45);
	
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+240,0);
     umum = new blok(UJUNG_X2-20, UJUNG_Y2+240,0, 10,10,1,1);
    umum->setColor(100,200,0);
	  umum->rotate(0,*center,-45,0);
	  umum->rotate(0,*center,0,-45);
		
    center = new Point<double>(UJUNG_X2,UJUNG_Y2+260,0);
     other = new blok(UJUNG_X2-20, UJUNG_Y2+260,0, 10,10,1,1);
    other->setColor(200,100,250);
	  other->rotate(0,*center,-45,0);
	  other->rotate(0,*center,0,-45);
  }
  void print(FrameBuffer& fb){
    stei->print(fb);
    fmipa->print(fb);
    fsrd->print(fb);
    fitb->print(fb);
    fttm->print(fb);
    sith->print(fb);
    sf->print(fb);
    sbm->print(fb);
    umum->print(fb);
    other->print(fb);
    ftsl->print(fb);
    sappk->print(fb);
    ftmd->print(fb);
    fti->print(fb);
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
  blok* tvst;
  blok* oktagon;
  blok* Biomedis;
  blok* Mkor;
  blok* labrh;
  blok* matematikaindustri;
  blok* SBM;
  blok* Mesin;
  blok* Mesin1;
  blok* comlabs;
  blok* pln;
  blok* Mektan;
  blok* PAU;
  blok* sebelahPAU;
  blok* Perpus;
  blok* cas;
  blok* gkubarat;
  blok* gedungfisikabaru;
  blok* bsca;
  blok* gedungfisikalama;
  blok* gedungsipil;
  blok* aulabarat;
  blok* aulatimur;
  blok* gedungplano;
  blok* gedungarsi;
  blok* gedunggeodesi;
  blok* gedungdkv;
  blok* gedungseni;
  blok* gedunglingkungan;
  blok* gkutimur;
  blok* gedungtimurjauh;  
  blok* bscb;  
  blok* gedungfttm;
  blok* bengkok;
  blok* labkelautan;
  KumpulanGedung(){
    kontrolPower =  new blok(300+310,400,-350,10,30,-7,2);
    kontrolPower->setColor(200,200,0);
    gkubarat =  new blok(300+340,400,-380,10,30,-4,4);
    gkubarat->setColor(100,200,0);
    gedungfisikabaru =  new blok(300+240,400,-430,10,30,-4,5);
    gedungfisikabaru->setColor(100,150,0);
    bsca =  new blok(300+210,400,-430,10,30,-4,2);
    bsca->setColor(100,200,0);
    labrh =  new blok(300+340,400,-430,10,30,-4,2);
    labrh->setColor(50,50,0);
    gedungBio =  new blok(300+460,400,-300,10,30,-6,4);
    gedungBio->setColor(50,50,0);
    Biomedis =  new blok(300+525,400,-390,10,30,-5,3);
    Biomedis->setColor(0,70,200);
    Mkor =  new blok(300+595,400,-350,10,30,-9,2);
    Mkor->setColor(200,100,250);
    matematikaindustri =  new blok(300+555,400,-390,10,30,-8,2);
    matematikaindustri->setColor(100,150,0);
    SBM =  new blok(300+625,400,-350,10,30,-9,2);
    SBM->setColor(100,0,100);
    Mesin =  new blok(300+470,400,-380,10,30,-9,5);
    Mesin->setColor(50,0,200);
    Mesin1 =  new blok(300+410,400,-420,10,30,-5,5);
    Mesin1->setColor(50,0,200);
    TeknikKimia =  new blok(300+510,400,-300,10,30,-6,4);
    TeknikKimia->setColor(0,70,200);
    oktagon =  new blok(300+500,400,-240,10,30,-5,5);
    oktagon->setColor(100,200,0);
    tvst =  new blok(300+440,400,-240,10,30,-5,5);
    tvst->setColor(100,200,0);
    labtekV =  new blok(300+320,400,-230,10,40,-11,3);
    labtekV->setColor(200,200,0);
    labtekVI =  new blok(300+370,400,-230,10,40,-11,3);
    labtekVI->setColor(230,230,0);
    labtekVII =  new blok(300+370,400,-70,10,40,-11,3);
    labtekVII->setColor(170,170,0);
    labtekVIII =  new blok(300+320,400,-70,10,40,-11,3);
    labtekVIII->setColor(200,200,0);
    Mektan =  new blok(300+430,400,-80,10,40,-4,11);
    Mektan->setColor(230,230,0);
    comlabs =  new blok(300+500,400,-130,10,40,-6,3);
    comlabs->setColor(100,200,0);
    pln =  new blok(300+460,400,-130,10,40,-6,3);
    pln->setColor(200,200,0);
    ccBarat =  new blok(300+260,400,-230,10,40,-6,2);
    ccBarat->setColor(200,100,250);
    ccTimur =  new blok(300+260,400,-140,10,40,-6,2);
    ccTimur->setColor(200,100,250);
    sebelahPAU =  new blok(300+570,400,-290,10,70,-5,5);
    sebelahPAU->setColor(170,60,30);
    PAU =  new blok(300+570,400,-240,10,70,-4,8);
    PAU->setColor(200,100,250);
    Perpus =  new blok(300+570,400,-120,10,30,-6,6);
    Perpus->setColor(200,100,250);
    cas =  new blok(300+570,400,-60,10,100,-5,7);
    cas->setColor(100,150,0);
	  gedungfisikalama =  new blok(300+230,400,-330,10,40,-8,6);
    gedungfisikalama->setColor(100,150,0);
	  gedungsipil =  new blok(300+150,400,-330,10,40,-8,6);
    gedungsipil->setColor(230,230,0);
	  aulabarat =  new blok(300+120,400,-230,10,40,-8,6);
    aulabarat->setColor(200,100,250);
	  aulatimur =  new blok(300+120,400,-90,10,40,-8,6);
    aulatimur->setColor(200,100,250);
	  gedunglingkungan =  new blok(300+260,400,-20,10,40,-9,2);
    gedunglingkungan->setColor(230,230,0);
    gedunggeodesi =  new blok(300+230,400,-20,10,40,-4,2);
    gedunggeodesi->setColor(230,230,50);
	  gedungarsi =  new blok(300+230,400,-70,10,40,-4,2);
    gedungarsi->setColor(130,130,50);
	  gedungplano =  new blok(300+200,400,-20,10,40,-4,2);
    gedungplano->setColor(130,130,50);
	  gedungdkv =  new blok(300+200,400,-70,10,40,-4,2);
    gedungdkv->setColor(170,60,30);
    gkutimur =  new blok(300+310,400,0,10,40,-4,4);
    gkutimur->setColor(100,200,0);
    gedungtimurjauh =  new blok(300+510,400,80,10,40,-9,9);
    gedungtimurjauh->setColor(30,160,190);
	  bscb =  new blok(300+480,400,50,10,40,-10,3);
    bscb->setColor(100,200,0);
    gedungfttm =  new blok(300+440,400,50,10,40,-10,3);
    gedungfttm->setColor(30,160,190);
    bengkok =  new blok(300+410,400,50,10,40,-10,2);
    bengkok->setColor(200,100,250);
    labkelautan =  new blok(300+360,400,50,10,40,-10,4);
    labkelautan->setColor(230,230,0);
  }
  void print(FrameBuffer& fb){
    gedunggeodesi->print(fb);
    aulabarat->print(fb);
    aulatimur->print(fb);
    SBM->print(fb);
    bsca->print(fb);
    gkubarat->print(fb);
    Mkor->print(fb);
    gedungsipil->print(fb);
    gedungfisikabaru->print(fb);
    labrh->print(fb);
    kontrolPower->print(fb);
    Mesin->print(fb);
    Mesin1->print(fb);
    matematikaindustri->print(fb);
    TeknikKimia->print(fb);
    oktagon->print(fb);
    Biomedis->print(fb);
    gedungBio->print(fb);
    labtekV->print(fb);
    labtekVI->print(fb);
    labtekVII->print(fb);
    labtekVIII->print(fb);
    Mektan->print(fb);
    ccBarat->print(fb);
    comlabs->print(fb);
    pln->print(fb);
    ccTimur->print(fb);
    sebelahPAU->print(fb);
    PAU->print(fb);
    Perpus->print(fb);
    cas->print(fb);
    tvst->print(fb);
    gedungfisikalama->print(fb);
    gedungarsi->print(fb);
    gedungdkv->print(fb);
    gedungplano->print(fb);
    gedunglingkungan->print(fb);
    gkutimur->print(fb);
    gedungtimurjauh->print(fb);
    bscb->print(fb);
    gedungfttm->print(fb);
    bengkok->print(fb);
    labkelautan->print(fb);
   }
  void move(int x,int y){
    gedunggeodesi->move(x,y);
    aulabarat->move(x,y);
    aulatimur->move(x,y);
    SBM->move(x,y);
    bsca->move(x,y);
    gkubarat->move(x,y);
    Mkor->move(x,y);
    gedungsipil->move(x,y);
    gedungfisikabaru->move(x,y);
    labrh->move(x,y);
    kontrolPower->move(x,y);
    Mesin->move(x,y);
    Mesin1->move(x,y);
    matematikaindustri->move(x,y);
    TeknikKimia->move(x,y);
    oktagon->move(x,y);
    Biomedis->move(x,y);
    gedungBio->move(x,y);
    labtekV->move(x,y);
    labtekVI->move(x,y);
    labtekVII->move(x,y);
    labtekVIII->move(x,y);
    Mektan->move(x,y);
    ccBarat->move(x,y);
    comlabs->move(x,y);
    pln->move(x,y);
    ccTimur->move(x,y);
    sebelahPAU->move(x,y);
    PAU->move(x,y);
    Perpus->move(x,y);
    cas->move(x,y);
    tvst->move(x,y);
    gedungfisikalama->move(x,y);
    gedungarsi->move(x,y);
    gedungdkv->move(x,y);
    gedungplano->move(x,y);
    gedunglingkungan->move(x,y);
    gkutimur->move(x,y);
    gedungtimurjauh->move(x,y);
    bscb->move(x,y);
    gedungfttm->move(x,y);
    bengkok->move(x,y);
    labkelautan->move(x,y);
   }
  void resize(double fb){
    Point<double> center (550,560,140);
	  gedunggeodesi->resize(fb,center);
	  aulabarat->resize(fb,center);
    aulatimur->resize(fb,center);
    SBM->resize(fb,center);
    bsca->resize(fb,center);
    gkubarat->resize(fb,center);
    Mkor->resize(fb,center);
    gedungsipil->resize(fb,center);
    gedungfisikabaru->resize(fb,center);
    labrh->resize(fb,center);
    kontrolPower->resize(fb,center);
    Mesin->resize(fb,center);
    Mesin1->resize(fb,center);
    matematikaindustri->resize(fb,center);
    TeknikKimia->resize(fb,center);
    oktagon->resize(fb,center);
    Biomedis->resize(fb,center);
    gedungBio->resize(fb,center);
    labtekV->resize(fb,center);
    labtekVI->resize(fb,center);
    labtekVII->resize(fb,center);
    labtekVIII->resize(fb,center);
    Mektan->resize(fb,center);
    ccBarat->resize(fb,center);
    comlabs->resize(fb,center);
    pln->resize(fb,center);
    ccTimur->resize(fb,center);
    sebelahPAU->resize(fb,center);
    PAU->resize(fb,center);
    Perpus->resize(fb,center);
    cas->resize(fb,center);
	  tvst->resize(fb,center);
	  gedungfisikalama->resize(fb,center);
	  gedungarsi->resize(fb,center);
    gedungdkv->resize(fb,center);
    gedungplano->resize(fb,center);
    gedunglingkungan->resize(fb,center);
    gkutimur->resize(fb,center);
	  gedungtimurjauh->resize(fb,center);
	  bscb->resize(fb,center);
    gedungfttm->resize(fb,center);
    bengkok->resize(fb,center);
    labkelautan->resize(fb,center);
   }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    SBM->rotate(degreeZ,center,degreeX,degreeY);
    Mkor->rotate(degreeZ,center,degreeX,degreeY);
    gedungsipil->rotate(degreeZ,center,degreeX,degreeY);
    gedungfisikabaru->rotate(degreeZ,center,degreeX,degreeY);
    labrh->rotate(degreeZ,center,degreeX,degreeY);
    matematikaindustri->rotate(degreeZ,center,degreeX,degreeY);
    gedungBio->rotate(degreeZ,center,degreeX,degreeY);
    Biomedis->rotate(degreeZ,center,degreeX,degreeY);
    Mesin->rotate(degreeZ,center,degreeX,degreeY);
    aulatimur->rotate(degreeZ,center,degreeX,degreeY);
    Mesin1->rotate(degreeZ,center,degreeX,degreeY);
    gedunggeodesi->rotate(degreeZ,center,degreeX,degreeY);
    kontrolPower->rotate(degreeZ,center,degreeX,degreeY);
    TeknikKimia->rotate(degreeZ,center,degreeX,degreeY);
    oktagon->rotate(degreeZ,center,degreeX,degreeY);
    aulabarat->rotate(degreeZ,center,degreeX,degreeY);
    labtekV->rotate(degreeZ,center,degreeX,degreeY);
    labtekVI->rotate(degreeZ,center,degreeX,degreeY);
    labtekVII->rotate(degreeZ,center,degreeX,degreeY);
    labtekVIII->rotate(degreeZ,center,degreeX,degreeY);
    bsca->rotate(degreeZ,center,degreeX,degreeY);
    Mektan->rotate(degreeZ,center,degreeX,degreeY);
    ccBarat->rotate(degreeZ,center,degreeX,degreeY);
    ccTimur->rotate(degreeZ,center,degreeX,degreeY);
    tvst->rotate(degreeZ,center,degreeX,degreeY);
    comlabs->rotate(degreeZ,center,degreeX,degreeY);
    pln->rotate(degreeZ,center,degreeX,degreeY);
    PAU->rotate(degreeZ,center,degreeX,degreeY);
    sebelahPAU->rotate(degreeZ,center,degreeX,degreeY);
    Perpus->rotate(degreeZ,center,degreeX,degreeY);
    cas->rotate(degreeZ,center,degreeX,degreeY);
    gkubarat->rotate(degreeZ,center,degreeX,degreeY);
    gedungfisikalama->rotate(degreeZ,center,degreeX,degreeY);
    gedungarsi->rotate(degreeZ,center,degreeX,degreeY);
    gedungplano->rotate(degreeZ,center,degreeX,degreeY);
    gedungdkv->rotate(degreeZ,center,degreeX,degreeY);
    gedunglingkungan->rotate(degreeZ,center,degreeX,degreeY);
    gkutimur->rotate(degreeZ,center,degreeX,degreeY);
    gedungtimurjauh->rotate(degreeZ,center,degreeX,degreeY);
    bscb->rotate(degreeZ,center,degreeX,degreeY);
    gedungfttm->rotate(degreeZ,center,degreeX,degreeY);
    bengkok->rotate(degreeZ,center,degreeX,degreeY);
    labkelautan->rotate(degreeZ,center,degreeX,degreeY);
  }
};
struct Jalan{
  blok* jalanparkiran;
  blok* jalanparkiranbelakang;
  blok* jalanparkirankekiri;
  bengkok* jalanujungkanan;
  bengkok* jalanujungkiri;
  bengkok* jalanujungkiribelakang;
  blok* jalanparkirankekanan;
  blok* jalanboulevard;
  blok* jalanboulevard1;
  blok* jalanboulevard2;
  blok* jalanboulevard3;
  blok* jalanboulevard4;
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
    jalanparkirankekiri = new blok(300+160,400,-480,10,1,-1,45);
    jalanparkirankekanan = new blok(300+130,400,0,10,1,-1,17);
    jalanujungkiri = new bengkok(300+100,400,-430,10,1,-5,6);
    jalanujungkiribelakang = new bengkok(300+650,400,-430,10,1,-5,-5);
    jalanujungkanan = new bengkok(300+100,400,-30,10,1,3,3);
    jalanparkiran = new blok(300+100,400,-30,10,1,-40,1);
    jalanparkiranbelakang = new blok(300+650,400,-50,10,1,-38,1);
    jalanseblabtek = new blok(300+300,400,0,10,1,-48,1); 
    jalanboulevard = new blok(300+100,400,-200,10,1,-2,20);
    jalanboulevard1 = new blok(300+210,400,-220,10,1,-10,1);
    jalanboulevard2 = new blok(300+210,400,-310,10,1,-1,10);
    jalanboulevard3 = new blok(300+210,400,-210,10,1,10,1);
    jalanboulevard4 = new blok(300+210,400,-110,10,1,-1,10);
    jalankirigku = new blok(300+100,400,-420,10,1,-1,25);
    jalanintel = new blok(300+300,400,-195,10,1,-3,12);
    jalangkutokema = new blok(300+300,400,-340,10,1,-1,10);
    jalanmesinmatik = new blok(300+400,400,-360,10,1,-1,16);
    jalantaman = new blok(300+430,400,-195,10,1,-3,12);
    jalansunken = new blok(300+560,400,-190,10,1,-4,9);
    jalangkumesin = new blok(300+400,400,-340,10,1,-14,1);
    jalansetlabtek = new blok(300+420,400,-50,10,1,-32,1);
    jalansebperpus = new blok(300+550,400,-50,10,1,-32,1);
    gangkanan = new blok(300+300,400,-50,10,1,-1,40);
    jalansebgang1 = new blok(300+470,400,70,10,1,-13,1);
    //jalansebgang1->rotate(0,Point<double>(475,400,5),0,15);
    jalansebgang2 = new blok(300+520,400,70,10,1,-13,1);
    //jalansebgang2->rotate(0,Point<double>(525,400,5),0,15);
    jalansebgang3 = new blok(300+610,400,70,10,1,-13,2);
    //jalansebgang3->rotate(0,Point<double>(610,400,5),0,15);
  }
  ~Jalan(){
    delete jalanparkirankekiri;
    delete jalanparkirankekanan;
    delete jalanujungkiribelakang;
    delete jalanujungkiri;
    delete jalanujungkanan;
    delete jalanparkiran;
    delete jalanparkiranbelakang;
    delete jalanseblabtek;
    delete jalanboulevard;
    delete jalanboulevard1;
    delete jalanboulevard2;
    delete jalanboulevard3;
    delete jalanboulevard4;
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
    jalanujungkiribelakang->print(fb);
    jalanujungkiri->print(fb);
    jalanujungkanan->print(fb);
    jalankirigku->print(fb);
    jalanboulevard->print(fb);
    jalanboulevard1->print(fb);
    jalanboulevard2->print(fb);
    jalanboulevard3->print(fb);
    jalanboulevard4->print(fb);
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
  void move(int x,int y){
    jalanparkiran->move(x,y);
    jalanparkiranbelakang->move(x,y);
    jalanparkirankekiri->move(x,y);
    jalanparkirankekanan->move(x,y);
    jalanujungkiribelakang->move(x,y);
    jalanujungkiri->move(x,y);
    jalanujungkanan->move(x,y);
    jalankirigku->move(x,y);
    jalanboulevard->move(x,y);
    jalanboulevard1->move(x,y);
    jalanboulevard2->move(x,y);
    jalanboulevard3->move(x,y);
    jalanboulevard4->move(x,y);
    jalanintel->move(x,y);
    jalanmesinmatik->move(x,y);
    jalangkumesin->move(x,y);
    jalangkutokema->move(x,y);
    jalantaman->move(x,y);
    jalansunken->move(x,y);
    jalanseblabtek->move(x,y);
    jalansetlabtek->move(x,y);
    jalansebperpus->move(x,y);
    jalansebgang1->move(x,y);
    jalansebgang2->move(x,y);
    jalansebgang3->move(x,y);
    gangkanan->move(x,y);
  }
  void resize(double fb){
    Point<double> center (550,560,140);
    jalanparkiran->resize(fb,center);
    jalanparkiranbelakang->resize(fb,center);
    jalanparkirankekiri->resize(fb,center);
    jalanparkirankekanan->resize(fb,center);
    jalanujungkiribelakang->resize(fb,center);
    jalanujungkiri->resize(fb,center);
    jalanujungkanan->resize(fb,center);
    jalankirigku->resize(fb,center);
    jalanboulevard->resize(fb,center);
    jalanboulevard1->resize(fb,center);
    jalanboulevard2->resize(fb,center);
    jalanboulevard3->resize(fb,center);
    jalanboulevard4->resize(fb,center);
    jalanintel->resize(fb,center);
    jalanmesinmatik->resize(fb,center);
    jalangkumesin->resize(fb,center);
    jalangkutokema->resize(fb,center);
    jalantaman->resize(fb,center);
    jalansunken->resize(fb,center);
    jalanseblabtek->resize(fb,center);
    jalansetlabtek->resize(fb,center);
    jalansebperpus->resize(fb,center);
    jalansebgang1->resize(fb,center);
    jalansebgang2->resize(fb,center);
    jalansebgang3->resize(fb,center);
    gangkanan->resize(fb,center);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    jalanparkiran->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkiranbelakang->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekiri->rotate(degreeZ,center,degreeX,degreeY);
    jalanparkirankekanan->rotate(degreeZ,center,degreeX,degreeY);
    jalanujungkiribelakang->rotate(degreeZ,center,degreeX,degreeY);
    jalanujungkiri->rotate(degreeZ,center,degreeX,degreeY);
    jalanujungkanan->rotate(degreeZ,center,degreeX,degreeY);
    jalankirigku->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard1->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard2->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard3->rotate(degreeZ,center,degreeX,degreeY);
    jalanboulevard4->rotate(degreeZ,center,degreeX,degreeY);
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
  blok* tanah;
  Jalan* jalanitb;
  KumpulanGedung* gedungitb;
  ITB(){
    tanah = new blok(300+100,398,70,10,-30,-56,62);
    tanah->setColor(170,200,200);
    gedungitb=new KumpulanGedung();
    jalanitb=new Jalan();
  }
  ~ITB(){
    delete tanah;
    delete gedungitb;
    delete jalanitb;
  }
  void print_all(FrameBuffer& fb){
    gedungitb->print(fb);
    jalanitb->print(fb);
  }
  void print(FrameBuffer& fb,int mode){
    tanah->print(fb);
    switch(mode) {
          case 0 : gedungitb->print(fb);
    jalanitb->print(fb); break;
          case 1 : jalanitb->print(fb); break;
          case 2 : gedungitb->print(fb); break;
    }
  }
  void resize(double fb){
    Point<double> center (550,560,140);
    tanah->resize(fb,center);
    gedungitb->resize(fb);
    jalanitb->resize(fb);
  }
  void move(int x,int y){
    tanah->move(x,y);
    gedungitb->move(x,y);
    jalanitb->move(x,y);
  }
  void rotate(double degreeZ, const Point<double>& center = Point<double>(0,0), double degreeX = 0, double degreeY = 0){
    tanah->rotate(degreeZ,center,degreeX,degreeY);
    jalanitb->rotate(degreeZ,center,degreeX,degreeY);
    gedungitb->rotate(degreeZ,center,degreeX,degreeY);
  }
};
#endif



