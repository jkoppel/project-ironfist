#ifndef GRAPHICS_H
#define GRAPHICS_H

#pragma pack(push, 1)

struct top { int _top; top(int t) : _top(t) {} };
struct bottom { int _bottom; bottom(int t) : _bottom(t) {} };
struct left { int _left; left(int t) : _left(t) {} };
struct right { int _right; right(int t) : _right(t) {} };

struct H2RECT;

struct Point {
  int _x;
  int _y;

  Point(int x, int y) : _x(x), _y(y) {}
  Point() {_x = _y = 0;};
  Point clipToRect(const H2RECT &rect);
};

struct H2RECT {
  int _left;
  int _right; // Inclusive
  int _top;
  int _bottom; // Inclusive
  
  H2RECT() {}
  H2RECT(struct top t, struct bottom b, struct left l, struct right &r) : _top(t._top), _bottom(b._bottom), _left(l._left), _right(r._right) {}

  H2RECT clipToBounds(const H2RECT &oth);
  H2RECT unionWith(const H2RECT &oth);

  int getWidth() {
    return _right - _left + 1;
  }

  int getHeight() {
    return _bottom - _top + 1;
  }
};

H2RECT rectAroundPoint(const Point &p, int halfWidth, int halfHeight);

struct tag_rect {
  short x;
  short y;
  short width;
  short height;
};

extern signed char __fastcall PointInRect(int x, int y,struct tag_rect *rect);

#pragma pack(pop)

extern int gbUseEvilInterface;
extern int gbLowMemory;
extern int giBottomViewOverride;

#endif