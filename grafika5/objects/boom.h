#ifndef __BOOM_H_
#define __BOOM_H_

#include "../lib/polygon.h" 

struct Boom : public Polygon {
  Boom() {
    addPoint(Point(126,468));
    addPoint(Point(126,288));
    addPoint(Point(144,288));
    addPoint(Point(144,270));
    addPoint(Point(126,270));
    addPoint(Point(126,252));
    addPoint(Point(90,252));
    addPoint(Point(90,270-54));//paling kiri
    addPoint(Point(126,270-54));
    addPoint(Point(126,252-54));
    addPoint(Point(180,252-54));
    addPoint(Point(180,234-54));
    addPoint(Point(162,234-54));
    addPoint(Point(162,216-54));
    addPoint(Point(144,216-54));
    addPoint(Point(144,198-54));
    addPoint(Point(126,198-54));
    addPoint(Point(126,180-54));
    addPoint(Point(198,180-54));
    addPoint(Point(198,144-54));
    addPoint(Point(180,144-54));
    addPoint(Point(180,108-54));
    addPoint(Point(162,108-54));
    addPoint(Point(162,72-54));
    addPoint(Point(198,72-54));//pojok kiri atas
    addPoint(Point(198,90-54));
    addPoint(Point(216,90-54));
    addPoint(Point(216,108-54));
    addPoint(Point(252,108-54));
    addPoint(Point(252,126-54));
    addPoint(Point(270,126-54));
    addPoint(Point(270,144-54));
    addPoint(Point(306,144-54));
    addPoint(Point(306,108-54));
    addPoint(Point(288,108-54));
    addPoint(Point(288,54-54));
    addPoint(Point(306,54-54));//paling atas
    addPoint(Point(306,72-54));
    addPoint(Point(324,72-54));
    addPoint(Point(324,90-54));
    addPoint(Point(342,90-54));
    addPoint(Point(342,108-54));
    addPoint(Point(360,108-54));
    addPoint(Point(360,72-54));
    addPoint(Point(378,72-54));
    addPoint(Point(378,108-54));
    addPoint(Point(396,108-54));
    addPoint(Point(396,126-54));
    addPoint(Point(414,126-54));
    addPoint(Point(414,144-54));
    addPoint(Point(450,144-54));
    addPoint(Point(450,126-54));
    addPoint(Point(486,126-54));
    addPoint(Point(486,108-54));
    addPoint(Point(594,108-54));//pojok kanan panjang
    addPoint(Point(594,126-54));
    addPoint(Point(612,126-54));
    addPoint(Point(612,144-54));
    addPoint(Point(630,144-54));
    addPoint(Point(630,180-54));
    addPoint(Point(648,180-54));
    addPoint(Point(648,234-54));
    addPoint(Point(666,234-54));
    addPoint(Point(666,270-54));
    addPoint(Point(684,270-54));
    addPoint(Point(684,306-54));//kiri pertama    
    addPoint(Point(666,306-54));
    addPoint(Point(666,324-54));
    addPoint(Point(684,324-54));
    addPoint(Point(684,360-54));
    addPoint(Point(666,360-54));
    addPoint(Point(666,378-54));
    addPoint(Point(684,378-54));
    addPoint(Point(684,396-54));
    addPoint(Point(666,396-54));
    addPoint(Point(666,414-54));
    addPoint(Point(648,414-54));
    addPoint(Point(648,468-54));
    addPoint(Point(666,468-54));
    addPoint(Point(666,486-54));
    addPoint(Point(684,486-54));
    addPoint(Point(684,522-54));
    addPoint(Point(666,522-54));
    addPoint(Point(666,540-54));
    addPoint(Point(648,540-54));
    addPoint(Point(648,558-54));
    addPoint(Point(666,558-54));
    addPoint(Point(666,594-54));
    addPoint(Point(684,594-54));
    addPoint(Point(684,612-54));//pojok kanan bawah
    addPoint(Point(666,558));
    addPoint(Point(666,540));
    addPoint(Point(630,540));
    addPoint(Point(630,558));
    addPoint(Point(450,558));
    addPoint(Point(450,540));
    addPoint(Point(432,540));
    addPoint(Point(432,558));
    addPoint(Point(252,558));
  }
};

#endif
