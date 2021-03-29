#include "agent.hpp"
#include <cmath>

void atype::steer(int left) {
  rotation = (rotation + left) % 360;
  xpos = std::fmax(xpos + std::cos(rotation) * speed, 0);
  ypos = std::fmax(ypos + std::sin(rotation) * speed, 0);
}

void atype::accelerate() {
  speed *= 1.5;
}

void atype::crash() {
  speed = 1;
};
