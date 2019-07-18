#include "base.h"
#include "graphics.h"
#include "windows.h" // For max/min....seriously

Point Point::clipToRect(const H2RECT &rect) {
  int newX = min(max(this->_x, rect._left), rect._right);
  int newY = min(max(this->_y, rect._top), rect._bottom);
  return Point(newX, newY);
}

H2RECT H2RECT::clipToBounds(const H2RECT &oth) {
  return H2RECT (
    top(max(this->_top, oth._top)),
    bottom((min(this->_bottom, oth._bottom))),
    left(max(this->_left, oth._left)),
    right(min(this->_right, oth._right)));
}

H2RECT H2RECT::unionWith(const H2RECT &oth) {
  return H2RECT(
    top(min(this->_top, oth._top)),
    bottom((max(this->_bottom, oth._bottom))),
    left(min(this->_left, oth._left)),
    right(max(this->_right, oth._right)));
}

H2RECT rectAroundPoint(const Point &p, int halfWidth, int halfHeight) {
  return H2RECT(top(p._y - halfHeight),
                bottom(p._y + halfHeight),
                left(p._x - halfWidth),
                right(p._x + halfWidth));
}