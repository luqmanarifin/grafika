#ifndef COLOR_H__
#define COLOR_H__

/**
 * Class that represents color (defined by red, green, blue, and alpha values)
 */
class Color {
public:
  Color() ;
  Color(char _red, char _green, char _blue, char _alpha = 0);
  char red, green, blue, alpha;

  Color& operator= (const Color& _color);

  bool operator== (const Color &rhs) const;

  bool operator!= (const Color &rhs) const;

  bool operator< (const Color &rhs) const;
  
  /* static constants */
  static const Color RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, BLACK, WHITE, EMPTY;
};

#endif