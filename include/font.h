#ifndef __FONT_H_
#define __FONT_H_

#include <bits/stdc++.h>
#include <framebuffer.h>
#include <color.h>

using namespace std;

struct Font {
  Font font() { }
  void print(FrameBuffer& fb, string str, int x, int y, int size_font, Color col);
  void print(FrameBuffer& fb, char c, int x, int y, int size_font, Color col);

  static const string pallet[][7];
};

#endif
