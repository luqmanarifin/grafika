#include <color.h>

Color::Color() : red(0), green(0), blue(0), alpha(0) {}
Color::Color(char _red, char _green, char _blue, char _alpha) :
  red(_red), green(_green), blue(_blue), alpha(_alpha) {}

Color& Color::operator= (const Color& _color) { 
  red = _color.red, green = _color.green, blue = _color.blue, alpha = _color.alpha; 
  return *this;
}

bool Color::operator== (const Color &rhs) const {
  return ((red == rhs.red) and (green == rhs.green) and (blue == rhs.blue) and (alpha == rhs.alpha));
}

bool Color::operator!= (const Color &rhs) const {
  return (!(*this == rhs));
}

bool Color::operator< (const Color &rhs) const {
  return true;
}

/* set default values for static variables */
/* Color constants */
const Color Color::RED      = Color(255,   0,   0);
const Color Color::GREEN    = Color(  0, 255,   0);
const Color Color::BLUE     = Color(  0,   0, 255);
const Color Color::YELLOW   = Color(255, 255,   0);
const Color Color::PURPLE   = Color(255,   0, 255);
const Color Color::CYAN     = Color(  0, 255, 255);
const Color Color::BLACK    = Color(  0,   0,   0);
const Color Color::WHITE    = Color(255, 255, 255);
const Color Color::EMPTY    = Color( -1,  -1,  -1);