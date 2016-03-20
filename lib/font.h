#ifndef __FONT_H_
#define __FONT_H_

#include <bits/stdc++.h>
#include "framebuffer.h"
#include "color.h"

using namespace std;

struct Font {
  Font font() { }
  void print(FrameBuffer& fb, string str, int x, int y, int size_font, Color col) {
    for(int i = 0; i < str.size(); i++) {
      print(fb, str[i], x, y, size_font, col);
      x += 4 * size_font;
    }
  }
  void print(FrameBuffer& fb, char c, int x, int y, int size_font, Color col) {
    for(int i = 0; i < 7; i++) {
      for(int j = 0; j < 4; j++) {
        int s = c - 'A';
        int at = (0 <= s && s < 26? s : 26);
        if(pallet[at][i][j] != '*') continue;
        for(int a = 0; a < size_font; a++) {
          for(int b = 0; b < size_font; b++) {
            int p = x + j * size_font + a;
            int q = y + i * size_font + b;
            fb.set(p, q, col);
          }
        }
      }
    }
  }
  static const string pallet[][7];
};

const string Font::pallet[][7] = {
  {
    " *  ",
    "* * ",
    "*** ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    "**  ",
    "* * ",
    "**  ",
    "* * ",
    "**  ",
    "    ",
    "    "
  },
  {
    " ** ",
    "*   ",
    "*   ",
    "*   ",
    " ** ",
    "    ",
    "    "
  },
  {
    "**  ",
    "* * ",
    "* * ",
    "* * ",
    "**  ",
    "    ",
    "    "
  },
  {
    "*** ",
    "*   ",
    "**  ",
    "*   ",
    "*** ",
    "    ",
    "    "
  },
  {
    // F
  },
  {
    " ** ",
    "*   ",
    "* * ",
    "* * ",
    " ** ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    "*** ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    "*** ",
    " *  ",
    " *  ",
    " *  ",
    "*** ",
    "    ",
    "    "
  },
  {
    " ** ",
    "  * ",
    "  * ",
    "* * ",
    " *  ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    "**  ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    "*   ",
    "*   ",
    "*   ",
    "*   ",
    "*** ",
    "    ",
    "    "
  },
  {
    "* * ",
    "*** ",
    "* * ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    "**  ",
    "* * ",
    "* * ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    " *  ",
    "* * ",
    "* * ",
    "* * ",
    " *  ",
    "    ",
    "    "
  },
  {
    "**  ",
    "* * ",
    "**  ",
    "*   ",
    "*   ",
    "    ",
    "    "
  },
  {
    " *  ",
    "* * ",
    "* * ",
    "* * ",
    " ** ",
    "    ",
    "    "
  },
  {
    "**  ",
    "* * ",
    "**  ",
    "* * ",
    "* *  ",
    "    ",
    "    "
  },
  {
    " ** ",
    "*   ",
    " *  ",
    "  * ",
    "**  ",
    "    ",
    "    "
  },
  {
    "*** ",
    " *  ",
    " *  ",
    " *  ",
    " *  ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    "* * ",
    "* * ",
    " *  ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    "* * ",
    " *  ",
    " *  ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    "* * ",
    "*** ",
    "* * ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    " *  ",
    "* * ",
    "* * ",
    "    ",
    "    "
  },
  {
    "* * ",
    "* * ",
    " *  ",
    " *  ",
    " *  ",
    "    ",
    "    "
  },
  {
    "*** ",
    "  * ",
    " *  ",
    "*   ",
    "*** ",
    "    ",
    "    "
  },
  {
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    "
  }
};

#endif