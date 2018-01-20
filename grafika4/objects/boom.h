#ifndef __BOOM_H_
#define __BOOM_H_

#include <polygon.h> 

struct Boom : public Polygon {
  Boom() {
    addPoint(Point<double>(126,468));
    addPoint(Point<double>(126,288));
    addPoint(Point<double>(144,288));
    addPoint(Point<double>(144,270));
    addPoint(Point<double>(126,270));
    addPoint(Point<double>(126,252));
    addPoint(Point<double>(90,252));
    addPoint(Point<double>(90,270-54));//paling kiri
    addPoint(Point<double>(126,270-54));
    addPoint(Point<double>(126,252-54));
    addPoint(Point<double>(180,252-54));
    addPoint(Point<double>(180,234-54));
    addPoint(Point<double>(162,234-54));
    addPoint(Point<double>(162,216-54));
    addPoint(Point<double>(144,216-54));
    addPoint(Point<double>(144,198-54));
    addPoint(Point<double>(126,198-54));
    addPoint(Point<double>(126,180-54));
    addPoint(Point<double>(198,180-54));
    addPoint(Point<double>(198,144-54));
    addPoint(Point<double>(180,144-54));
    addPoint(Point<double>(180,108-54));
    addPoint(Point<double>(162,108-54));
    addPoint(Point<double>(162,72-54));
    addPoint(Point<double>(198,72-54));//pojok kiri atas
    addPoint(Point<double>(198,90-54));
    addPoint(Point<double>(216,90-54));
    addPoint(Point<double>(216,108-54));
    addPoint(Point<double>(252,108-54));
    addPoint(Point<double>(252,126-54));
    addPoint(Point<double>(270,126-54));
    addPoint(Point<double>(270,144-54));
    addPoint(Point<double>(306,144-54));
    addPoint(Point<double>(306,108-54));
    addPoint(Point<double>(288,108-54));
    addPoint(Point<double>(288,54-54));
    addPoint(Point<double>(306,54-54));//paling atas
    addPoint(Point<double>(306,72-54));
    addPoint(Point<double>(324,72-54));
    addPoint(Point<double>(324,90-54));
    addPoint(Point<double>(342,90-54));
    addPoint(Point<double>(342,108-54));
    addPoint(Point<double>(360,108-54));
    addPoint(Point<double>(360,72-54));
    addPoint(Point<double>(378,72-54));
    addPoint(Point<double>(378,108-54));
    addPoint(Point<double>(396,108-54));
    addPoint(Point<double>(396,126-54));
    addPoint(Point<double>(414,126-54));
    addPoint(Point<double>(414,144-54));
    addPoint(Point<double>(450,144-54));
    addPoint(Point<double>(450,126-54));
    addPoint(Point<double>(486,126-54));
    addPoint(Point<double>(486,108-54));
    addPoint(Point<double>(594,108-54));//pojok kanan panjang
    addPoint(Point<double>(594,126-54));
    addPoint(Point<double>(612,126-54));
    addPoint(Point<double>(612,144-54));
    addPoint(Point<double>(630,144-54));
    addPoint(Point<double>(630,180-54));
    addPoint(Point<double>(648,180-54));
    addPoint(Point<double>(648,234-54));
    addPoint(Point<double>(666,234-54));
    addPoint(Point<double>(666,270-54));
    addPoint(Point<double>(684,270-54));
    addPoint(Point<double>(684,306-54));//kiri pertama    
    addPoint(Point<double>(666,306-54));
    addPoint(Point<double>(666,324-54));
    addPoint(Point<double>(684,324-54));
    addPoint(Point<double>(684,360-54));
    addPoint(Point<double>(666,360-54));
    addPoint(Point<double>(666,378-54));
    addPoint(Point<double>(684,378-54));
    addPoint(Point<double>(684,396-54));
    addPoint(Point<double>(666,396-54));
    addPoint(Point<double>(666,414-54));
    addPoint(Point<double>(648,414-54));
    addPoint(Point<double>(648,468-54));
    addPoint(Point<double>(666,468-54));
    addPoint(Point<double>(666,486-54));
    addPoint(Point<double>(684,486-54));
    addPoint(Point<double>(684,522-54));
    addPoint(Point<double>(666,522-54));
    addPoint(Point<double>(666,540-54));
    addPoint(Point<double>(648,540-54));
    addPoint(Point<double>(648,558-54));
    addPoint(Point<double>(666,558-54));
    addPoint(Point<double>(666,594-54));
    addPoint(Point<double>(684,594-54));
    addPoint(Point<double>(684,612-54));//pojok kanan bawah
    addPoint(Point<double>(666,558));
    addPoint(Point<double>(666,540));
    addPoint(Point<double>(630,540));
    addPoint(Point<double>(630,558));
    addPoint(Point<double>(450,558));
    addPoint(Point<double>(450,540));
    addPoint(Point<double>(432,540));
    addPoint(Point<double>(432,558));
    addPoint(Point<double>(252,558));
  }
};

#endif
