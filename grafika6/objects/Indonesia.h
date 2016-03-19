#ifndef __Indonesia_H
#define __Indonesia_H

#include "belakang.h"
#include "kalimantan.h"
#include "Jawa.h"
#include "Sumatra.h"
#include "Kepulauan.h"
#include "seram.h"
#include "buru.h"
#include "halmahera.h"
#include "Sulawesi.h"
#include "Papua.h"


using namespace std;

  struct KepSumatra{
    Sumatra* sumatra;
    Belitung* belitung;
    Bangka* bangka;
    KepSumatra() {     
      sumatra = new Sumatra();
      belitung = new Belitung();
      bangka = new Bangka();
      sumatra->resizeCenter(0.7);
      sumatra->move(-100,0);
      belitung->resizeCenter(0.06);
      belitung->move(190,60);
      bangka->resizeCenter(0.16);
      bangka->move(60,150);
    }
    void print(FrameBuffer fb){
      sumatra->print(fb);
      bangka->print(fb);
      belitung->print(fb);
    }
    void resize(float skala){
      sumatra->resize(skala,Point<double>(400,300));
      bangka->resize(skala,Point<double>(400,300));
      belitung->resize(skala,Point<double>(400,300));
    }
    void move(int x, int y){
      sumatra->move(x,y);
      bangka->move(x,y);
      belitung->move(x,y);
    }
    
    };

  struct KepJawa{
    Jawa* jawa ; 
    Madura* madura ;
    KepJawa() {  
      jawa = new Jawa();
      madura = new Madura();
      jawa->resizeCenter(1);
      jawa->move(0,300);
      madura->resizeCenter(0.28);
      madura->move(60,40);
    }
    void print(FrameBuffer fb){
      jawa->print(fb);
      madura->print(fb);
    }
    void resize(float skala){
      jawa->resize(skala,Point<double>(400,300));
      madura->resize(skala,Point<double>(400,300));
    }
    void move(int x, int y){
      jawa->move(x,y);
      madura->move(x,y);
    }
    
  };
  
  struct NTT{
    Sumbawa* sumbawa;
    NTT1* ntt1 ; 
    NTT2* ntt2;
    NTT() {     
      sumbawa = new Sumbawa();
      ntt1 = new NTT1();
      ntt2 = new NTT2();
      
    }
    void print(FrameBuffer fb){
      sumbawa->print(fb);
      ntt1->print(fb);
      ntt2->print(fb);
    }
    void resize(float skala){
      sumbawa->resize(skala,Point<double>(400,300));
      ntt1->resize(skala,Point<double>(400,300));
      ntt2->resize(skala,Point<double>(400,300));
    }
    void move(int x, int y){
      sumbawa->move(x,y);
      ntt1->move(x,y);
      ntt2->move(x,y);
    }
    
  };
  
  struct NTB{
    NTB1* ntb;
    Bali* bali;
    Lombok* lombok;
    NTB() {     
      ntb = new NTB1();
      bali = new Bali();
      lombok = new Lombok();
      ntb->resizeCenter(1);
      ntb->move(100,-30);
      bali->resizeCenter(0.2);
      bali->move(-250,0);
      lombok->resizeCenter(0.15);
      lombok->move(-50,-80);
    }
    void print(FrameBuffer fb){
      ntb->print(fb);
      bali->print(fb);
      lombok->print(fb);
    }
    void resize(float skala){
      ntb->resize(skala,Point<double>(400,300));
      bali->resize(skala,Point<double>(400,300));
      lombok->resize(skala,Point<double>(400,300));
    }
    void move(int x, int y){
      ntb->move(x,y);
      bali->move(x,y);
      lombok->move(x,y);
    }
    
    };

struct Maluku{
    Ambon* ambon;
    Seram* seram;
    Buru* buru;
    Halmahera* halmahera;
    Maluku() {     
      ambon = new Ambon();
      seram = new Seram();
      buru = new Buru();
      halmahera = new Halmahera();
      halmahera->resizeCenter(5);
      halmahera->move(-200,0);
      ambon->resizeCenter(0.1);
      ambon->move(-100,290);
      seram->resizeCenter(6);
      seram->move(-80,300);
      buru->resizeCenter(5);
      buru->move(-250,300);
    }
    void print(FrameBuffer fb){
      halmahera->print(fb);
      ambon->print(fb);
      seram->print(fb);
      buru->print(fb);
    }
    void resize(float skala){
      halmahera->resize(skala,Point<double>(400,300));
      ambon->resize(skala,Point<double>(400,300));
      seram->resize(skala,Point<double>(400,300));
      buru->resize(skala,Point<double>(400,300));
    
    }
    void move(int x, int y){
      halmahera->move(x,y);
      ambon->move(x,y);
      seram->move(x,y);
      buru->move(x,y);
    }
    
    };
 struct Indonesia{
    KepSumatra* sumatra;
    Maluku* maluku;
    Papua* papua;
    Sulawesi* sulawesi;
    Kalimantan* kalimantan;
    NTT* ntt;
    NTB* ntb;
    KepJawa* jawa;
    Belakang* bel;
    Indonesia() {
      sumatra = new KepSumatra();
      maluku= new Maluku();
      papua= new Papua();
      sulawesi= new Sulawesi();
      kalimantan = new Kalimantan();
      ntt= new NTT();
      ntb= new NTB();
      jawa= new KepJawa();
      sumatra->resize(0.3);
      sumatra->move(-250,0);
      maluku->resize(0.13);
      maluku->move(90,-40);
      papua->resizeCenter(0.3);
      papua->move(300,150);
      sulawesi->resizeCenter(0.27);
      sulawesi->move(150,50);
      kalimantan->resizeCenter(0.27);
      kalimantan->move(-120,30);
      ntt->resize(0.2);
      ntt->move(30,100);
      ntb->resize(0.2);
      ntb->move(-50,100);
      jawa->resize(0.2);
      jawa->move(-150,70);
      resize(1.5);
      move(300, 75);
    }
    void print(FrameBuffer fb, Polygon* back, int red = 0, int green = 174, int blue = 239, int alpha = 0){
      back->print(fb, red, green, blue, alpha);
      sumatra->print(fb);
      maluku->print(fb);
      papua->print(fb);
      sulawesi->print(fb);
      kalimantan->print(fb);
      ntt->print(fb);
      ntb->print(fb);
      jawa->print(fb);
    }
    void resize(float skala){
      sumatra->resize(skala);
      maluku->resize(skala);
      papua->resize(skala,Point<double>(400,300));
      sulawesi->resize(skala,Point<double>(400,300));
      kalimantan->resize(skala,Point<double>(400,300));
      ntt->resize(skala);
      ntb->resize(skala);
      jawa->resize(skala);
    }
    void move(int x, int y){
      sumatra->move(x,y);
      maluku->move(x,y);
      papua->move(x,y);
      sulawesi->move(x,y);
      kalimantan->move(x,y);
      ntt->move(x,y);
      ntb->move(x,y);
      jawa->move(x,y);
    }
    
    };

#endif

