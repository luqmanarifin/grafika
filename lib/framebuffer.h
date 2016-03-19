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
#include <queue>
#include <cmath>
#include <algorithm>

#include "color.h"
#include "point.h"
#include "frame.h"


/**
 * Helper class to access linux framebuffer.
 * Source: http://xathrya.web.id/blog/2012/10/26/graphic-programming-using-frame-buffer-on-linux/
 * with refactoring and some modifications.
 * Must be "print()" to be printed in monitor
 */
class FrameBuffer : public Frame {
  typedef std::pair<std::pair<int, std::pair<int,int> >, Color > query;
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
    printf("done\n");

    /* store important information */
    xres = vinfo.xres;
    yres = vinfo.yres;
    bits_per_pixel = vinfo.bits_per_pixel;

    /* map the device to memory */
    fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

    /* Construct hstack & vstack */
    hstack = new std::priority_queue<query> [yres];
    vstack = new std::priority_queue<query> [xres];

    /* initialize visited vector */
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
  void set(Point<int> p, Color c) {
    set(p.x, p.y, c.red, c.green, c.blue, c.alpha);
  }

#define MP make_pair
  /**
   * Vertical pixel range setter
   */
  void vset(int z, int x, int y1, int y2, Color color) {
    if (x < 0 || x >= xres) return;
    vstack[x].push(MP(MP(z, MP(y1, y2)), color));
  }

  /**
   * Horizontal pixel range setter
   */
  void hset(int z, int y, int x1, int x2, Color color) {
    if (y < 0 || y >= yres) return;
    hstack[y].push(MP(MP(z, MP(x1, x2)), color));
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
      lastSet.push_back(Point<int>(x, y));
    }
  }

  void print() {
    propagate();

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
    //printf("%d ",lastSet.size());
  }
  
  void print_exclude(Point<int> a, Point<int> b) {
    for(int i = 0; i < lastSet.size(); i++) {
      int x = lastSet[i].x;
      int y = lastSet[i].y;
      if(a.x <= x && x <= b.x && a.y <= y && y <= b.y) continue;
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

  void print_include(Point<int> a, Point<int> b) {
    for(int i = 0; i < lastSet.size(); i++) {
      int x = lastSet[i].x;
      int y = lastSet[i].y;
      if(a.x <= x && x <= b.x && a.y <= y && y <= b.y) {
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
  }

  /**
   * Get color at p.
   */
  Color get(Point<int> p) {
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
      Point<int> &p = lastSet.back();
      set(p.x, p.y, Color::BLACK);
      visited[p.x][p.y] = 0;
      lastSet.pop_back();
    }
  }

  void clear(std::vector<Point<int> >& all) {
    while(!all.empty()) {
      Point<int> &p = all.back();
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

protected:
  /**
   * Get memory offset for pixel at (x, y).
   */
  int getLocation(int x, int y) {
    return (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8)
        + (y + vinfo.yoffset) * finfo.line_length;
  }

  /**
   * Propagate the range draws
   */
  void propagate() {
    /**
     * Horizontal
     */
    for (int row = 0; row < yres; ++row) {
      /* For all range queries */
      while (!hstack[row].empty()) {
        std::pair<int, int> rng = hstack[row].top().first.second;
        Color c = hstack[row].top().second;
        hstack[row].pop();

        for (int col = rng.first; col < rng.second; ++col) {
          set(col, row, c);
        }
      }
    }

    /**
     * Vertical
     */
    for (int col = 0; col < xres; ++col) {
      /* For all range queries */
      while (!vstack[col].empty()) {
        std::pair<int, int> rng = vstack[col].top().first.second;
        Color c = vstack[col].top().second;
        vstack[col].pop();

        for (int row = rng.first; row < rng.second; ++row) {
          set(col, row, c);
        }
      }
    }
  }

  int xres, yres;     /* screen resolution */
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  static int fbfd;    /* frame buffer file descriptor */
  static char* fbp;   /* pointer to framebuffer */
  static std::vector<std::vector<int> > visited;
  static std::vector<Point<int> > lastSet;
  static std::vector<std::vector<Color> > color;
  std::priority_queue<query> *hstack;
  std::priority_queue<query> *vstack;
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
std::vector<Point<int> > FrameBuffer::lastSet;
std::vector<std::vector<Color> > FrameBuffer::color;

#endif
