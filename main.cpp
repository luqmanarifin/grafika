#include "lib/polygon.h"
#include <iostream>
using namespace std;

FrameBuffer fb;
Polygon* printSumatra(){
    Polygon* pol = new Polygon();
	//Kiri
	pol->addPoint(Point(0, 0));
	pol->addPoint(Point(0, 30));
	pol->addPoint(Point(10, 30));
	pol->addPoint(Point(10, 60));
	pol->addPoint(Point(35, 60));
	pol->addPoint(Point(35, 90));
	pol->addPoint(Point(80, 90));
	pol->addPoint(Point(80, 120));
	pol->addPoint(Point(105, 120));
	pol->addPoint(Point(105, 150));
	pol->addPoint(Point(145, 150));
	pol->addPoint(Point(145, 180));
	pol->addPoint(Point(170, 180));
	pol->addPoint(Point(170, 210));
	pol->addPoint(Point(180, 210));
	pol->addPoint(Point(180, 240));
	pol->addPoint(Point(235, 240));
	pol->addPoint(Point(235, 270));
	pol->addPoint(Point(250, 270));
	pol->addPoint(Point(250, 300));
	pol->addPoint(Point(275, 300));
	pol->addPoint(Point(275, 330));
	pol->addPoint(Point(315, 330));
	pol->addPoint(Point(315, 360));
	pol->addPoint(Point(335, 360));
	pol->addPoint(Point(335, 390));
	pol->addPoint(Point(345, 390));
	pol->addPoint(Point(345, 420));
	pol->addPoint(Point(330, 420));
	pol->addPoint(Point(330, 450));
	pol->addPoint(Point(375, 450));
	pol->addPoint(Point(375, 480));
	pol->addPoint(Point(390, 480));
	pol->addPoint(Point(390, 510));	
	pol->addPoint(Point(435, 510));
	pol->addPoint(Point(435, 540));
	pol->addPoint(Point(460, 540));
	pol->addPoint(Point(460, 570));
	pol->addPoint(Point(500, 570));
	pol->addPoint(Point(500, 600));
	pol->addPoint(Point(525, 600));
	pol->addPoint(Point(525, 630));    
	//Kanan
	pol->addPoint(Point(615, 630));
	pol->addPoint(Point(615, 600));
	pol->addPoint(Point(620, 600));
	pol->addPoint(Point(620, 570));
	pol->addPoint(Point(610, 570));
	pol->addPoint(Point(610, 540));
	pol->addPoint(Point(620, 540));
	pol->addPoint(Point(620, 510));
	pol->addPoint(Point(610, 510));
	pol->addPoint(Point(610, 480));
	pol->addPoint(Point(585, 480));
	pol->addPoint(Point(585, 450));
	pol->addPoint(Point(570, 450));
	pol->addPoint(Point(570, 420));
	pol->addPoint(Point(555, 420));
	pol->addPoint(Point(555, 390));
	pol->addPoint(Point(545, 390));
	pol->addPoint(Point(545, 360));
	pol->addPoint(Point(495, 360));
	pol->addPoint(Point(495, 330));
	pol->addPoint(Point(515, 330));
	pol->addPoint(Point(515, 300));
	pol->addPoint(Point(490, 300));
	pol->addPoint(Point(490, 270));
	pol->addPoint(Point(415, 270));
	pol->addPoint(Point(415, 240));
	pol->addPoint(Point(390, 240));
	pol->addPoint(Point(390, 210));
	pol->addPoint(Point(350, 210));
	pol->addPoint(Point(350, 180));
	pol->addPoint(Point(295, 180));
	pol->addPoint(Point(295, 150));
	pol->addPoint(Point(255, 150));
	pol->addPoint(Point(255, 120));
	pol->addPoint(Point(200, 120));
	pol->addPoint(Point(200, 90));
	pol->addPoint(Point(185, 90));
	pol->addPoint(Point(185, 60));
	pol->addPoint(Point(160, 60));
	pol->addPoint(Point(160, 30));
	pol->addPoint(Point(60, 30));
	pol->addPoint(Point(60, 0));
	return pol;
}

int main() {
  system("clear");
  printSumatra()->print(fb);
  return 0;
}
