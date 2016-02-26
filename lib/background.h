// Copyright by azaky
// azaky.github.io

#ifndef BACKGROUND_H
#define BACKGROUND_H

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

class Background : public FrameBuffer {
public:
  Background() {}
  void print_exclude(Point a, Point b) {
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
};

#endif
