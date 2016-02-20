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

#include "color.h"
#include "point.h"
#include "frame.h"

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
    for(int i = 0; i <= xres; i++){
      for(int j = 0; j <= yres; j++){
        matrix[j][i]=Color::EMPTY;
      }
    }
  }

  FrameMatrix& operator=(FrameMatrix _fm){
    xres = _fm.xres;
    yres = _fm.yres;
    for(int i = 0; i <= xres; i++){
      for(int j = 0; j <= yres; j++){
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
 * Must be "print()" to be printed in monitor
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
    if (color.empty()) {
      color.resize(xres);
      for (int i = 0; i < xres; ++i) {
        color[i].resize(yres);
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
    color[x][y] = Color(red, green, blue, alpha);
    /* adds to lastSet */
    if (!visited[x][y]) {
      visited[x][y] = 1;
      lastSet.push_back(Point(x, y));
    }
  }

  void print() {
    for(int i = 0; i < lastSet.size(); i++) {
      int x = lastSet[i].x;
      int y = lastSet[i].y;
      int red = color[x][y].red;
      int green = color[x][y].green;
      int blue = color[x][y].blue;
      int alpha = color[x][y].alpha;
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

  void clear(std::vector<Point>& all) {
    while(!all.empty()) {
      Point &p = all.back();
      set(p.x, p.y, Color::BLACK);
      if (0 <= p.x && p.x < xres && 0 <= p.y && p.y < yres) {
        visited[p.x][p.y] = 0;
      }
      all.pop_back();
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
  static std::vector<std::vector<Color> > color;
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
std::vector<std::vector<Color> > FrameBuffer::color;

#endif
