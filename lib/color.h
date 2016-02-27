#ifndef COLOR_H__
#define COLOR_H__

/**
 * Class that represents color (defined by red, green, blue, and alpha values)
 */
class Color {
public:
  Color() : red(0), green(0), blue(0), alpha(0) {}
  Color(char _red, char _green, char _blue, char _alpha = 0) :
    red(_red), green(_green), blue(_blue), alpha(_alpha) {}
  char red, green, blue, alpha;

  Color& operator= (const Color& _color) { 
    red = _color.red, green = _color.green, blue = _color.blue, alpha = _color.alpha; 
    return *this;
  }

  bool operator== (const Color &rhs) const {
    return ((red == rhs.red) and (green == rhs.green) and (blue == rhs.blue) and (alpha == rhs.alpha));
  }

  bool operator!= (const Color &rhs) const {
    return (!(*this == rhs));
  }
  /* static constants */
  static const Color RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, BLACK, WHITE, EMPTY;
};

#endif