#ifndef _OBJECT_H
#define _OBJECT_H 1

#include <ctime>

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
  wheel(const Polygon& p, double _speed) : object(p), speed(_speed) { then = time(); }
private:
  double speed;
  time_t then, now;
};
Polygon& wheel::getStatusNow() 
{
  now = time();
  pol->rotate(_speed);      // rotate
  pol->move(0, int(_speed * G * 0.00001));     // free-falls
  return *pol;
}

#endif