// Copyright by azaky
// azaky.github.io

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <unistd.h>
#include <fcntl.h>    /* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h> /* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h> /* for frame buffer properties */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

/**
 * Class that represents color (defined by red, green, blue, and alpha values)
 */
class Color {
public:
  Color() : red(0), green(0), blue(0), alpha(0) {}
  Color(char _red, char _green, char _blue, char _alpha = 0) :
    red(_red), green(_green), blue(_blue), alpha(_alpha) {}
  char red, green, blue, alpha;

  bool operator== (const Color &rhs) const {
    return ((red == rhs.red) and (green == rhs.green) and (blue == rhs.blue) and (alpha == rhs.alpha));
  }

  bool operator!= (const Color &rhs) const {
    return (!(*this == rhs));
  }
  /* static constants */
  static const Color RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, BLACK, WHITE, EMPTY;
};

/**
 * Class that represents 2D point
 */
class Point {
public:
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  
  void resize(float size, const Point& center = Point()) {
    *this -= center;
    x *= size;
    y *= size;
    *this += center;
  }

  Point operator+=(const Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Point operator+(const Point& rhs) {
    return Point(x+rhs.x, y+rhs.y);
  }

  Point operator-=(const Point& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Point operator-(const Point& rhs) {
    return Point(x-rhs.x, y-rhs.y);
  }

  void rotate(const int& degree, const Point& offset = Point(0, 0)) {
    *this -= offset;
    Point temp = *this;
    float rad = degree*3.14159265/180.0;
    x = temp.x*cos(rad)-temp.y*sin(rad);
    y = temp.x*sin(rad)+temp.y*cos(rad);
    *this += offset;
  }

  int x, y;
};

class Frame {
public:
  virtual void set(int x, int y, Color c) = 0;
  virtual void set(Point p, Color c) = 0;
  virtual void set(int x, int y, char red, char green, char blue, char alpha = 0) = 0;
  virtual Color get(Point p) = 0;
  virtual Color get(int x, int y) = 0;
  virtual int getXSize() = 0;
  virtual int getYSize() = 0;
};

class FrameMatrix : public Frame {
public:
  FrameMatrix() {
    xres = yres = 0;
  }

  void set(int x, int y, Color c) {
    matrix[y][x] = c;
    xres = std::max(xres, x);
    yres = std::max(yres, y);

  };

  void set(Point p, Color c) {
    matrix[p.y][p.x] = c;
    xres = std::max(xres, p.x);
    yres = std::max(yres, p.y);

  };
  void set(int x, int y, char red, char green, char blue, char alpha = 0) {
    matrix[y][x] = Color(red, green, blue, alpha);
    xres = std::max(xres, x);
    yres = std::max(yres, y);

  };
  
  Color get(Point p) {
    if (p.y > yres)
      p.y %= yres+1;
    while (p.y < 0)
      p.y += yres+1;

    if (p.x > xres)
      p.x %= xres+1;
    while (p.x < 0)
      p.x += xres+1;

    if ((matrix.count(p.y)) and (matrix[p.y].count(p.x)))
      return matrix[p.y][p.x];
    return Color::EMPTY;
  };
  
  Color get(int x, int y) {
    if (y > yres)
      y %= yres+1;
    while (y < 0)
      y += yres+1;

    if (x > xres)
      x %= xres+1;
    while (x < 0)
      x += xres+1;

    if ((matrix.count(y)) and (matrix[y].count(x)))
      return matrix[y][x];
    return Color::EMPTY;
  };

  int getXSize() {
    return xres;
  }

  int getYSize() {
    return yres;
  }

  void clear(){
    for(int i = 0; i <= 1366; i++){
      for(int j = 0; j <= 768; j++){
        matrix[j][i]=Color::EMPTY;
      }
    }
  }

  FrameMatrix& operator=(FrameMatrix _fm){
    xres = _fm.xres;
    yres = _fm.yres;
    for(int i = 0; i <= 1366; i++){
      for(int j = 0; j <= 768; j++){
        if(_fm.get(Point(i,j))!=Color::EMPTY)
        matrix[j][i]=_fm.matrix[j][i];
      }
    }
    return *this;
  }
private:
  std::map<int, std::map<int, Color> > matrix;
  int xres, yres;
};
/**
 * Helper class to access linux framebuffer.
 * Source: http://xathrya.web.id/blog/2012/10/26/graphic-programming-using-frame-buffer-on-linux/
 * with refactoring and some modifications.
 */
class FrameBuffer : public Frame {
public: 
  FrameBuffer() {
    if (fbp == NULL) {
      init();
    }
  }

  ~FrameBuffer() {
    close(fbfd);
  }

  /**
   * Initialize frame buffer. Copy frame buffer ("/dev/fb0") into memory.
   */
  void init() {
    /* open the file for reading and writing */
    fbfd = open("/dev/fb0",O_RDWR);
    if (!fbfd) {
      printf("Error: cannot open framebuffer device.\n");
      exit(1);
    }
     
    /* get the fixed screen information */
    if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
      printf("Error reading fixed information.\n");
      exit(2);
    }
     
    /* get variable screen information */
    if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
      printf("Error reading variable information.\n");
      exit(3);
    }

    /* store important information */
    xres = vinfo.xres;
    yres = vinfo.yres;
    bits_per_pixel = vinfo.bits_per_pixel;

    /* map the device to memory */
    fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

    /* initialize visited vector */
    // visited.clear();
    if (visited.empty()) {
      visited.resize(xres);
      for (int i = 0; i < xres; ++i) {
        visited[i].resize(yres);
      }
    }
    // lastSet.clear();
  }

  /**
   * Set pixel at (x, y) using color c.
   */
  void set(int x, int y, Color c) {
    set(x, y, c.red, c.green, c.blue, c.alpha);
  }

  /**
   * Set pixel at p using color c.
   */
  void set(Point p, Color c) {
    set(p.x, p.y, c.red, c.green, c.blue, c.alpha);
  }

  /**
   * Set pixel at (x, y) using RGBA red, green, blue, and alpha.
   * The value of alpha is unnecessary, the default is 0;
   */
  void set(int x, int y, char red, char green, char blue, char alpha = 0) {
    /* Validate coordinate */
    if (x < 0 || x >= xres || y < 0 || y >= yres) {
      return;
    }
    int location = getLocation(x, y);
    if (bits_per_pixel == 32) {
      *(fbp + location + 0) = blue;
      *(fbp + location + 1) = green;
      *(fbp + location + 2) = red;
      *(fbp + location + 3) = alpha;
    }
    else if (bits_per_pixel == 16) {
      unsigned short int t = (red >> 3) << 11 | (green >> 2) << 5 | (blue >> 3);
      *((unsigned short int*)(fbp + location)) = t;     
    }
    else {
      printf("Unknown bpp format: %d bpp\n", vinfo.bits_per_pixel);
    }
    /* adds to lastSet */
    if (!visited[x][y]) {
      // printf("%d %d\n", x, y);
      visited[x][y] = 1;
      lastSet.push_back(Point(x, y));
    }
  }

  /**
   * Get color at p.
   */
  Color get(Point p) {
    return get(p.x, p.y);
  }

  /**
   * Get color at (x, y).
   */
  Color get(int x, int y) {
    /* Validate coordinate */
    if (x < 0 || x >= xres || y < 0 || y >= yres) {
      return Color();
    }
    int location = getLocation(x, y);
    char red, green, blue, alpha;
    if (bits_per_pixel == 32) {
      blue  = *(fbp + location + 0);
      green = *(fbp + location + 1);
      red   = *(fbp + location + 2);
      alpha = *(fbp + location + 3);
    }
    else if (bits_per_pixel == 16) {
      unsigned short int t = *((unsigned short int*)(fbp + location));
      red   = (char)((t >> 11) << 3);
      green = (char)((t >> 5) << 2);
      blue  = (char)(t << 3);
      alpha = 0;
    }
    else {
      printf("Unknown bpp format: %d bpp\n", vinfo.bits_per_pixel);
      red = green = blue = alpha = 0;
    }
    return Color(red, green, blue, alpha);
  }

  /**
   * Clear the screen. Color them with the default color (BLACK)
   */
  void clear() {
    while (lastSet.size()) {
      Point &p = lastSet.back();
      set(p.x, p.y, Color::BLACK);
      visited[p.x][p.y] = 0;
      lastSet.pop_back();
    }
  }

  /**
   * Refresh the screen. Unmap the memory back to the "/dev/fb0"
   */
  void refresh() {
    /* unmap the framebuffer */
    munmap(fbp, finfo.smem_len);

    /* after the unmap operation, fbp and fbfd will be invalid.
     * it is necessary to do re-initialize */
    close(fbfd);
    init();
  }

  int bits_per_pixel;   /* guess what */

  int getXSize() {
    return xres;
  }

  int getYSize() {
    return yres;
  }
private:
  /**
   * Get memory offset for pixel at (x, y).
   */
  int getLocation(int x, int y) {
    return (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8)
        + (y + vinfo.yoffset) * finfo.line_length;
  }

  int xres, yres;     /* screen resolution */
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  static int fbfd;    /* frame buffer file descriptor */
  static char* fbp;   /* pointer to framebuffer */
  static std::vector<std::vector<int> > visited;
  static std::vector<Point> lastSet;
};

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

/* FrameBuffer variables */
int FrameBuffer::fbfd = 0;
char* FrameBuffer::fbp = NULL;
std::vector<std::vector<int> > FrameBuffer::visited;
std::vector<Point> FrameBuffer::lastSet;

#endif
