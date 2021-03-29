#ifndef __POS_HPP
#define __POS_HPP

class pos {
  int x;
  int y;
public:
  pos(int x, int y): x(x), y(y) {};
  int getX() const {return x;};
  int getY() const {return y;};
  void setX(int newX) { x = newX; }
  void setY(int newY) { y = newY; }
};

#endif
