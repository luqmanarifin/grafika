#ifndef _OBJECT_H
#define _OBJECT_H 1

#include <ctime>

#define HEIGHT 800

/* Object general prototype */

class object
{
public:
  object(const Polygon& p);
  ~object();
  void init();
  Polygon& getStatusNow();
private:
  Polygon* pol;
  const double G = 9.80665;
};
object::object(const Polygon& _pol) { pol = new Polygon(_pol); init(); }
object::~object() { delete pol; }
void object::init() {}
Polygon& object::getStatusNow() { return *pol; }

// -----------------------------------------
// Propeller

class propeller : public object
{
public:
  propeller(const Polygon& p, double _speed) : object(p), speed(_speed) {}
private:
  double speed;
};
Polygon& propeller::getStatusNow() 
{
  pol->rotate(_speed);      // rotate
  pol->resize(_speed);      // go forth
  return *pol;
}

// -----------------------------------------
// Wheel

class wheel : public object
{
public:
  wheel(const Polygon& p, int _radius, double _speed = 0) : object(p), speed(_speed), radius(_radius) { then = time(); }
private:
  double speed;
  time_t then;
  int radius;
};
Polygon& wheel::getStatusNow() 
{
  int now = time() - then;
  speed -= int(G * now);              // changed speed
  if (pol->getLowest() > HEIGHT)      // bounced
    speed *= -1;
  
  pol->rotate(20);         // rotate
  pol->move(0, speed);     // free-falls
  return *pol;
}

#endif