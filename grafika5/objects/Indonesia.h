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

#define tengah_A 683
#define tengah_B 384

using namespace std;

  struct KepSumatra{
    Sumatra* sumatra;
    Belitung* belitung;
    Bangka* bangka;
    KepSumatra() {     
      sumatra = new Sumatra();
      belitung = new Belitung();
      bangka = new Bangka();
      sumatra->resizes(0.7);
      sumatra->move(-100,0);
      belitung->resizes(0.06);
      belitung->move(190,60);
      bangka->resizes(0.16);
      bangka->move(60,150);
    }
    void print(FrameBuffer fb){
      sumatra->print(fb);
      bangka->print(fb);
      belitung->print(fb);
    }
    void resize(float skala){
      sumatra->resize(skala,Point<double>(tengah_A,tengah_B));
      bangka->resize(skala,Point<double>(tengah_A,tengah_B));
      belitung->resize(skala,Point<double>(tengah_A,tengah_B));
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
      jawa->resizes(1);
      jawa->move(0,300);
      madura->resizes(0.28);
      madura->move(60,40);
    }
    void print(FrameBuffer fb){
      jawa->print(fb);
      madura->print(fb);
    }
    void resize(float skala){
      jawa->resize(skala,Point<double>(tengah_A,tengah_B));
      madura->resize(skala,Point<double>(tengah_A,tengah_B));
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
      sumbawa->resize(skala,Point<double>(tengah_A,tengah_B));
      ntt1->resize(skala,Point<double>(tengah_A,tengah_B));
      ntt2->resize(skala,Point<double>(tengah_A,tengah_B));
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
      ntb->resizes(1);
      ntb->move(100,-30);
      bali->resizes(0.2);
      bali->move(-250,0);
      lombok->resizes(0.15);
      lombok->move(-50,-80);
    }
    void print(FrameBuffer fb){
      ntb->print(fb);
      bali->print(fb);
      lombok->print(fb);
    }
    void resize(float skala){
      ntb->resize(skala,Point<double>(tengah_A,tengah_B));
      bali->resize(skala,Point<double>(tengah_A,tengah_B));
      lombok->resize(skala,Point<double>(tengah_A,tengah_B));
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
      halmahera->resizes(5);
      halmahera->move(-200,0);
      ambon->resizes(0.1);
      ambon->move(-100,290);
      seram->resizes(6);
      seram->move(-80,300);
      buru->resizes(5);
      buru->move(-250,300);
    }
    void print(FrameBuffer fb){
      halmahera->print(fb);
      ambon->print(fb);
      seram->print(fb);
      buru->print(fb);
    }
    void resize(float skala){
      halmahera->resize(skala,Point<double>(tengah_A,tengah_B));
      ambon->resize(skala,Point<double>(tengah_A,tengah_B));
      seram->resize(skala,Point<double>(tengah_A,tengah_B));
      buru->resize(skala,Point<double>(tengah_A,tengah_B));
    
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
      sumatra->move(-230,0);
      maluku->resize(0.13);
      maluku->move(30,-70);
      papua->resizes(0.3);
      papua->move(500,200);
      sulawesi->resizes(0.27);
      sulawesi->move(350,90);
      kalimantan->resizes(0.27);
      kalimantan->move(90,80);
      ntt->resize(0.2);
      ntt->move(30,100);
      ntb->resize(0.2);
      ntb->move(-50,100);
      jawa->resize(0.2);
      jawa->move(-150,70);
      resize(1.5);
      move(200, 35);
      
    }
    void print(FrameBuffer fb, Polygon* back, int red = 0, int green = 174, int blue = 239, int alpha = 0){
      back->print(fb, red, green, blue, alpha);
      sumatra->print(fb);
      /*maluku->print(fb);
      papua->print(fb);
      sulawesi->print(fb);
      kalimantan->print(fb);
      ntt->print(fb);
      ntb->print(fb);
      jawa->print(fb);*/
    }
    void resize(float skala){
      sumatra->resize(skala);
      maluku->resize(skala);
      papua->resize(skala,Point<double>(tengah_A,tengah_B));
      sulawesi->resize(skala,Point<double>(tengah_A,tengah_B));
      kalimantan->resize(skala,Point<double>(tengah_A,tengah_B));
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

