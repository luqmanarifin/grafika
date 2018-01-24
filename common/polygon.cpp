#include <polygon.h>

Polygon::Polygon() {
  warna = Color::WHITE;
  points = NULL;
  size = 0;
  done = new bool*[1366];
  for(int i = 0; i < 1366; i++) done[i] = new bool[768];
}
Polygon::Polygon(Point<double>* _points, int _size) {
  warna = Color::WHITE;
  points = _points;
  size = _size;
  done = new bool*[1366];
  for(int i = 0; i < 1366; i++) done[i] = new bool[768];
}
Polygon::Polygon(const Polygon& _polygon) {   
  warna = _polygon.warna;
  size = _polygon.size;
  points = new Point<double>[size];
  for(int i=0;i<size;i++){
    points[i] = Point<double>(_polygon.points[i]);
  }    
  done = new bool*[1366];
  for(int i = 0; i < 1366; i++) done[i] = new bool[768];
}
Polygon& Polygon::operator=(const Polygon& _polygon) {
  warna = _polygon.warna;
  size = _polygon.size;
  if ( points != NULL) delete[] points;
  points = new Point<double>[size];
  for(int i=0;i<size;i++){
    points[i] = Point<double>(_polygon.points[i]);
  }    
  return *this;
}
Polygon::~Polygon() {
  if ( points != NULL) delete[] points;
}

// Set Color
Polygon& Polygon::setColor(int red, int green, int blue, int alpha = 1.0) { warna = Color(red, green, blue, alpha); return *this; }
Polygon& Polygon::setColor(const Color& color) { warna = color; return *this; }

double Polygon::ratio(double a, double b) { return abs(a / b); }

bool Polygon::isEqueal(Point<double> p1,Point<double> p2) {
  return !islessgreater(p1.x,p2.x) && !islessgreater(p1.y,p2.y) && !islessgreater(p1.z,p2.z);
}
Polygon& Polygon::addCurve(curve c)
{
  for (auto d : c.points)
  {
    if (size > 0) {
      if (points[size - 1] != d) {
        addPoint(d);
      }
    }
    else {
      addPoint(d);
    }
  }
  return *this;
}

Polygon& Polygon::addPoint(const Point<double>& p) {
  Point<double>* newPoints = new Point<double>[size + 1];
  for(int i = 0; i < size; i++) {
    newPoints[i] = points[i];
  }
  
  newPoints[size++] = p;
  if ( points != NULL) delete[] points;
  points = newPoints;

  // update center
  center.x *= (size - 1);
  center.x += p.x;
  center.x /= size;
  center.y *= (size - 1);
  center.y += p.y;
  center.y /= size;
  center.z *= (size - 1);
  center.z += p.z;
  center.z /= size;
  
  return *this;
}

bool Polygon::same(double a, double b) {
  return fabs(a - b) < eps;
}

///////////
/* Print */
///////////

Polygon& Polygon::print_frame(FrameBuffer& fb, int red, int green, int blue, int alpha) {
  // for(int i = 0; i < size; i++) {
    // int j = (i + 1) % size;
    // line((int) points[i].x, (int) points[i].y, (int) points[j].x, (int) points[j].y, Color(red, green, blue, alpha)).print(fb);
  // }
  return *this;
}

#define MP make_pair

Polygon& Polygon::print(FrameBuffer& fb) {
  print_frame(fb,0,0,0,0);
  pair<double, double>* a = new pair<double, double>[2 * size];

  double ymin = MinY(), ymak = MaxY();

  for(int y = ymin; y <= ymak; y++) {
    int sz = 0;
    for(int i = 0; i < size; i++) {
      int j = (i + 1) % size;
      double l = points[i].y;
      double r = points[j].y;
      if(min(l, r) <= y && y <= max(l, r)) {
        pair<double, double> la = MP(points[i].x, points[i].z);
        pair<double, double> ra = MP(points[j].x, points[j].z);
        if(same(l, r)) {
          a[sz++] = min(la, ra);
          a[sz++] = max(la, ra);
        } else {
          double dx = abs(l - y)*abs(la.first - ra.first)/abs(l - r);
          double dz = abs(l - y)*abs(la.second - ra.second)/abs(l - r);
          a[sz++] = MP(la.first + (la.first < ra.first? dx : -dx), 
                      la.second + (la.second < ra.second? dz : -dz));
        }
      }
    }
    sort(a, a + sz);
    sz = unique(a,a+sz)-a;
    for(int i = 0; i + 1 < sz; i += 2) {
      int lx = (int)round(a[i].first);
      int lz = (int)round(a[i].second);
      int rx = (int)round(a[i+1].first);
      int rz = (int)round(a[i+1].second);
      for (int x = lx; x <= rx; ++x) {
        int z = (int)round(double(rz - lz) * (x - lx) / (rx - lx) ) + lz;
        fb.set(x, y, z, warna);
      }
    }
  }
  
  // double bmin = 1e9, bmak = -1e9;
  // for(int i = 0; i < size; i++) {
  //   bmin = min(bmin, points[i].x);
  //   bmak = max(bmak, points[i].x);
  // }

  // for(int b = bmin; b <= bmak; b++) {
  //   int sz = 0;
  //   for(int i = 0; i < size; i++) {
  //     int j = (i + 1) % size;
  //     double l = points[i].x;
  //     double r = points[j].x;
  //     if(min(l, r) <= b && y <= max(l, r)) {
  //       pair<double, double> la = MP(points[i].y, points[i].z);
  //       pair<double, double> ra = MP(points[j].y, points[j].z);
  //       if(same(l, r)) {
  //         a[sz++] = min(la, ra);
  //         a[sz++] = max(la, ra);
  //       } else {
  //         double dx = abs(l - y)*abs(la.first - ra.first)/abs(l - r);
  //         double dz = abs(l - y)*abs(la.second - ra.second)/abs(l - r);
  //         a[sz++] = MP(la.first + (la.first < ra.first? dx : -dx), 
  //                     la.second + (la.second < ra.second? dz : -dz));
  //       }
  //     }
  //   }
  //   sort(a, a + sz);
  //   sz = unique(a,a+sz)-a;
  //   for(int i = 0; i + 1 < sz; i += 2) {
  //     int lx = (int)round(a[i].first);
  //     int lz = (int)round(a[i].second);
  //     int rx = (int)round(a[i+1].first);
  //     int rz = (int)round(a[i+1].second);
  //     for (int x = lx; x <= rx; ++x) {
  //       int z = (int)round(fabs( double(rz - lz) * (x - lx) / (rx - lx) )) + lz;
  //       fb.set(x, y, z, warna);
  //     }
  //   }
  // }

  if (a != NULL) delete[] a;
  return *this;
}

////////////////
/* Boundaries */
////////////////

int Polygon::MaxX() {
  if (maxX != DUMMY) return maxX;

  int Max = DUMMY;              
  for(int i = 0; i < size; i++) {
    int rounded = (int)ceil(points[i].x);
    if(rounded > Max) {
      Max = rounded;
    }
  } 
  return maxX = Max;
}

int Polygon::MinX() {
  if (minX != DUMMY) return minX;

  int Min = DUMMY - 1;              // overflow cycle (min - 1 = max) :P
  for(int i = 0; i < size; i++) {
    int rounded = (int)round(points[i].x);
    if(rounded < Min) {
      Min = rounded;
    }
  } 
  return minX = Min;
}

int Polygon::MaxY() {
  if (maxY != DUMMY) return maxY;

  int Max = DUMMY;              
  for(int i = 0; i < size; i++) {
    int rounded = (int)ceil(points[i].y);
    if(rounded > Max) {
      Max = rounded;
    }
  } 
  return maxY = Max;
}

int Polygon::MinY() {
  if (minY != DUMMY) return minY;

  int Min = DUMMY - 1;              
  for(int i = 0; i < size; i++) {
    int rounded = (int)round(points[i].y);
    if(rounded < Min) {
      Min = rounded;
    }
  } 
  return minY = Min;
}

int Polygon::MinZ() {
  if (minZ != DUMMY) return minZ;

  int Min = DUMMY - 1;              
  for(int i = 0; i < size; i++) {
    int rounded = (int)round(points[i].z);
    if(rounded < Min) {
      Min = rounded;
    }
  } 
  return minZ = Min;
}

////////////////////
/* Transformation */
////////////////////

Polygon& Polygon::resize(double factor, const Point<double>& center = Point<double>()) {
  #pragma omp parallel for
  for (int i = 0; i < size; ++i) {
    points[i].scale(factor, center);
  }
  this->center.scale(factor, center);
  minZ = DUMMY;
  return *this;
}
Polygon& Polygon::resizeCenter(double factor) {
  return resize(factor, this->center);
}
Polygon& Polygon::move(int x, int y) {
  #pragma omp parallel for
  for (int i = 0; i < size; ++i) {
    points[i].move(x, y);
  }
  center.move(x, y);
  minZ = DUMMY;
  return *this;
}
Polygon& Polygon::rotate(double degreeZ, const Point<double>& center, double degreeX, double degreeY) {
  #pragma omp parallel for
  for (int i = 0; i < size; ++i) {
    points[i].rotate(degreeZ, center, degreeX, degreeY);
  }
  this->center.rotate(degreeZ, center, degreeX, degreeY);
  minZ = DUMMY;

  return *this;
}
Polygon& Polygon::rotateCenter(double degreeZ, double degreeX, double degreeY) {
  return rotate(degreeZ, this->center, degreeX, degreeY);
}