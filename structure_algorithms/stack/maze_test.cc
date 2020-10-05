#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include "stack.h"

struct Position {
  int row;
  int col;
  friend std::ostream& operator<<(std::ostream& out, const Position& pos);
};

std::ostream& operator<<(std::ostream& out, const Position& pos) {
  out << "->(" << pos.row << "," << pos.col << ")";
  return out;
}

ArrayStack<Position>* path;
const int m = 10;  // size of maze
bool maze[m + 2][m + 2] = {true};

bool findPath() {
  path = new ArrayStack<Position>(2 * m);
  // init offset   //0--right, 1--down, 2--left, 3--up
  Position offset[4];
  offset[0].row = 0;
  offset[0].col = 1;
  offset[1].row = 1;
  offset[1].col = 0;
  offset[2].row = 0;
  offset[2].col = -1;
  offset[3].row = -1;
  offset[3].col = 0;

  // init obstacles around the maze
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      maze[i][j] = true;
    }
  }
  for (int i = 0; i <= m + 1; ++i) {
    maze[i][0] = maze[i][m + 1] = false;
    maze[0][i] = maze[m + 1][i] = false;
  }
  int a = 0, b = 0;
  // input obstacles in maze
  std::ifstream inFile("obstacles_position.txt");
  if (inFile) {
    std::string line;
    while (std::getline(inFile, line)) {
      std::stringstream ss(line);
      ss >> a >> b;
      maze[a][b] = false;
    }
  }

  Position here;
  here.row = 1;
  here.col = 1;
  maze[1][1] = false;
  int option = 0;
  int lastOption = 3;

  while ((here.row != m) || (here.col != m)) {
    int r, c;
    while (option <= lastOption) {
      r = here.row + offset[option].row;
      c = here.col + offset[option].col;
      if (maze[r][c] == true) break;
      option++;
    }
    if (option <= lastOption) {
      path->push(here);
      here.row = r;
      here.col = c;
      maze[r][c] = false;
      option = 0;
    } else {
      if (path->empty()) {
        return false;
      }
      Position next = path->top();
      path->pop();
      if (next.row == here.row) {
        option = 2 + next.col - here.col;
      } else {
        option = 3 + next.row - here.row;
      }
      here = next;
    }
  }
  return true;
}
void printPath() {
  ArrayStack<Position>* result = new ArrayStack<Position>(m * 2);
  while (!path->empty()) {
    result->push(path->top());
    path->pop();
  }
  std::cout << *result << std::endl;
}

int main() {
  findPath();
  printPath();
}
