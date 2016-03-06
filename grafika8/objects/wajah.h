#ifndef __Wajah_H_
#define __Wajah_H_

#include "rambut.h"
#include "kepala.h"
#include "bolamata.h"
#include "mata.h"
#include "mulut.h"

struct Wajah {
  //utama
  Kepala* kepala;
  HidungKanan* hidKanan;
  HidungKiri* hidKiri;
  Hidung* hidung;
  Rambut* rambut;
  //kiri
  Mata* matakiri;
  Alis* aliskiri;
  Tangisan* tangisankiri;
  Bolamata* bolakiri;
  MataSipit* matakirisipit;
  MataMerem* matakirimerem;
  //kanan
  Mata* matakanan;
  Alis* aliskanan;
  Tangisan* tangisankanan;
  Bolamata* bolakanan;
  MataSipit* matakanansipit;
  MataMerem* matakananmerem;
  //mulut
  Mulut* mulut;
  MulutSenyum* senyum;
  MulutSedih* sedih;
  Bibir* bibirlebar;
  Bibir2* bibirsempit;
  MulutTertawa* tertawa;
  GigiTertawa* gigi;
  int mode=1;
  Wajah() {
    //utama
    kepala = new Kepala();
    rambut = new Rambut();
    hidKanan = new HidungKanan();
    hidKiri = new HidungKiri();
    hidung = new Hidung();
    //kiri
    matakiri = new Mata();
    aliskiri = new Alis();
    tangisankiri = new Tangisan();
    bolakiri = new Bolamata();
    matakirisipit = new MataSipit();
    matakirimerem = new MataMerem();
    bolakiri->move(-150,0);
    tangisankiri->move(-150,0);
    matakiri->move(-150,0);
    matakirisipit->move(-150,0);
    matakirimerem->move(-150,0);
    aliskiri->move(-150,0);
    //kanan
    matakanan = new Mata();
    aliskanan = new Alis();
    tangisankanan = new Tangisan();
    bolakanan = new Bolamata();
    matakanansipit = new MataSipit();
    matakananmerem = new MataMerem();
    //mulut
    mulut = new Mulut();
    senyum = new MulutSenyum();
    sedih = new MulutSedih();
    bibirlebar = new Bibir();
    bibirsempit = new Bibir2();
    tertawa = new MulutTertawa();
    gigi = new GigiTertawa();
  }
  void print(FrameBuffer& fb){
    kepala->print(fb);
    //hidKanan->print(fb);
    //hidKiri->print(fb);
    //hidung->print(fb);
    aliskiri->print(fb);
    aliskanan->print(fb);
    if(mode==1){
      mulut->print(fb);
      matakanan->print(fb);
      matakiri->print(fb);
      bolakanan->print(fb);
      bolakiri->print(fb);
    }
    else if(mode==2){
      bibirlebar->print(fb);
      senyum->print(fb);
      matakanan->print(fb);
      matakiri->print(fb);
      bolakanan->print(fb);
      bolakiri->print(fb);
    }
    else if(mode==3){
      bibirsempit->print(fb);
      sedih->print(fb);
      matakanansipit->print(fb);
      matakirisipit->print(fb);
      tangisankiri->print(fb);
      tangisankanan->print(fb);
      bolakanan->print(fb);
      bolakiri->print(fb);
    }
    else if(mode==4){
      mulut->print(fb);
      matakananmerem->print(fb);
      matakirimerem->print(fb);
    }
    else if(mode==5){
      bibirlebar->print(fb);
      tertawa->print(fb);
      gigi->print(fb);
      matakananmerem->print(fb);
      matakirimerem->print(fb);
    }
    rambut->print(fb);
    rambut->print_frame(fb,255,255,255,0);
  }
  void jadibiasa(){
    if(mode==3){
      aliskanan = new Alis();
      aliskiri = new Alis();
      aliskiri->move(250,0);
      aliskanan->move(400,0);
    }
    mode=1;
  }
  void jadisenyum(){
    if(mode==3){
      aliskanan = new Alis();
      aliskiri = new Alis();
      aliskiri->move(250,0);
      aliskanan->move(400,0);
    }
    mode=2;
  }
  void jadisedih(){
    if(mode!=3){ 
      aliskanan->rotateCenter(180);
      aliskiri->rotateCenter(180);
    }
    mode=3;
  }
  void jadimerem(){
    if(mode==3){ 
      aliskanan = new Alis();
      aliskiri = new Alis();
      aliskiri->move(250,0);
      aliskanan->move(400,0);
    }
    mode=4;
  }
  void jaditertawa(){
    if(mode==3){ 
      aliskanan = new Alis();
      aliskiri = new Alis();
      aliskiri->move(250,0);
      aliskanan->move(400,0);
    }
    mode=5;
  }
  void move(double x,double y){
    kepala->move(x,y);
    hidKanan->move(x,y);
    hidKiri->move(x,y);
    hidung->move(x,y);
    aliskiri->move(x,y);
    aliskanan->move(x,y);
    matakanan->move(x,y);
    matakiri->move(x,y);
    mulut->move(x,y);
    bibirsempit->move(x,y);
    bibirlebar->move(x,y);
    senyum->move(x,y);
    sedih->move(x,y);
    matakanansipit->move(x,y);
    matakirisipit->move(x,y);
    matakananmerem->move(x,y);
    matakirimerem->move(x,y);
    tangisankiri->move(x,y);
    tangisankanan->move(x,y);
    bolakanan->move(x,y);
    bolakiri->move(x,y);
    rambut->move(x,y);
    tertawa->move(x,y);
    gigi->move(x,y);
  }
  
};

#endif
