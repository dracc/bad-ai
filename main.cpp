#include <array>
#include <iostream>
#include <string>

#include "agent.hpp"


void print_field(pos const& agent, pos const& goal, int rows, int cols) {
  std::cout << "_";
  for (int j = 0; j < cols; ++j) {
    std::cout << "____";
  }
  std::cout << std::endl;
  
  for (int i = 0; i < rows; ++i) {
    std::cout << "|";
    for (int j = 0; j < cols; ++j) {
      if (agent.getX() == j && agent.getY() == i) {
	std::cout << " A |";
      } else if (goal.getX() == j && goal.getY() == i) {
	std::cout << " G |";
      } else {
	std::cout << "   |";
      }
    }
    std::cout << std::endl << "|";
    for (int j = 0; j < cols; ++j) {
      std::cout << "___|";
    }
    std::cout << std::endl;
  }
}

int score(pos const& agent, pos const& goal) {
  return abs(abs(agent.getX()) - goal.getX()) + abs(abs(agent.getY()) - goal.getY());
}

int main(int argc, char** argv) {
  int rows = 5;
  int cols = 5;
  int action = 1;
  int steps = 0;
  
  int last = 0;
  int curr = 0;

  atype agent;
  pos goal(0, 0);

  if (argc >= 3) {
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
  }
  if (argc >= 5) {
    goal.setX(atoi(argv[3]));
    goal.setY(atoi(argv[4]));
  }
  
  print_field(agent.p(), goal, rows, cols);
  last = score(agent.p(), goal);

  while ((curr = score(agent.p(), goal)) != 0) {
    ++steps;
    print_field(agent.p(), goal, rows, cols);

    std::cout << last << " "
	      << curr << " "
	      << agent.p().getX() << " "
	      << agent.p().getY() << std::endl;
    if (curr >= last) {
      agent.steer(30);
      agent.crash();
    } else {
      agent.steer(0);
      agent.accelerate();
    }
    last = curr;
  }
  print_field(agent.p(), goal, rows, cols);
  std::cout << "Steps walked: " << steps << std::endl;
  return 0;
}
