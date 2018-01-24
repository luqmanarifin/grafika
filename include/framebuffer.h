// Copyright by @azaky (azaky.github.io)
// Modified by @icalF (icalf.github.io) and @luqmanarifin (luqmanarifin.github.io)

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
#include <ctype.h>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

#include <color.h>
#include <point.h>
#include <frame.h>


/**
 * Helper class to access linux framebuffer.
 * Source: http://xathrya.web.id/blog/2012/10/26/graphic-programming-using-frame-buffer-on-linux/
 * with refactoring and some modifications.
 * Must be "print()" to be printed in monitor
 */
class FrameBuffer : public Frame {
public: 
  FrameBuffer();

  ~FrameBuffer();

  /**
   * Initialize frame buffer. Copy frame buffer ("/dev/fb0") into memory.
   */
  void init();

  /**
   * Set pixel at (x, y, z) using RGBA red, green, blue, and alpha.
   * The value of alpha is unnecessary, the default is 0;
   */
  void set(int x, int y, int z, char red, char green, char blue, char alpha);

  /**
   * Set pixel at (x, y, z) using color c.
   */
  void set(int x, int y, int z, Color c);

  /**
   * Set pixel at p using color c.
   */
  void set(Point<int> p, Color c);

  void print();
  
  void print_exclude(Point<int> a, Point<int> b);

  void print_include(Point<int> a, Point<int> b);

  /**
   * Get color at p.
   */
  Color get(Point<int> p);

  /**
   * Get color at (x, y).
   */
  Color get(int x, int y);

  /**
   * Clear the screen. Color them with the default color (BLACK)
   */
  void clear();

  void clear(std::vector<Point<int> >& all);

  /**
   * Refresh the screen. Unmap the memory back to the "/dev/fb0"
   */
  void refresh();

  int bits_per_pixel;   /* guess what */

  int getXSize();

  int getYSize();

protected:
  /**
   * Get memory offset for pixel at (x, y).
   */
  int getLocation(int x, int y);

  int xres, yres;     /* screen resolution */
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  static int fbfd;    /* frame buffer file descriptor */
  static char* fbp;   /* pointer to framebuffer */
  static std::vector<std::vector<int> > visited;
  static std::vector<std::pair<int, int> > lastSet;
  static std::vector<std::vector<std::pair<int, Color> > > color;
};

#endif
