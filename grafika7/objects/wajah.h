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
  //kanan
  Mata* matakanan;
  Alis* aliskanan;
  Tangisan* tangisankanan;
  Bolamata* bolakanan;
  MataSipit* matakanansipit;
  //mulut
  Mulut* mulut;
  MulutSenyum* senyum;
  MulutSedih* sedih;
  Bibir* bibirlebar;
  Bibir2* bibirsempit;
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
    bolakiri->move(-150,0);
    tangisankiri->move(-150,0);
    matakiri->move(-150,0);
    matakirisipit->move(-150,0);
    aliskiri->move(-150,0);
    //kanan
    matakanan = new Mata();
    aliskanan = new Alis();
    tangisankanan = new Tangisan();
    bolakanan = new Bolamata();
    matakanansipit = new MataSipit();
    //mulut
    mulut = new Mulut();
    senyum = new MulutSenyum();
    sedih = new MulutSedih();
    bibirlebar = new Bibir();
    bibirsempit = new Bibir2();
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
    }
    else if(mode==2){
      bibirlebar->print(fb);
      senyum->print(fb);
      matakanan->print(fb);
      matakiri->print(fb);
    }
    
    else if(mode==3){
      bibirsempit->print(fb);
      sedih->print(fb);
      matakanansipit->print(fb);
      matakirisipit->print(fb);
      tangisankiri->print(fb);
      tangisankanan->print(fb);
    }
    bolakanan->print(fb);
    bolakiri->print(fb);
    rambut->print(fb);
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
    mode=3;
    aliskanan->rotateCenter(180);
    aliskiri->rotateCenter(180);
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
    tangisankiri->move(x,y);
    tangisankanan->move(x,y);
    bolakanan->move(x,y);
    bolakiri->move(x,y);
    rambut->move(x,y);
  }
  
};

#endif
