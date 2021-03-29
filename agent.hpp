#ifndef __AGENT
#define __AGENT

#include "pos.hpp"

class atype {
  float xpos = 0.0;
  float ypos = 0.0;
  float speed = 1.0;
  int rotation = 0;
public:
  const pos p() {return {(int)(xpos + 0.5), (int)(ypos + 0.5)};};
  void steer(int left);
  void accelerate();
  void crash();
};

#endif
