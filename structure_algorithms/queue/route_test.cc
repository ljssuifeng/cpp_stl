#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "queue.h"
#include "structure_algorithms/stack/stack.h"

struct Position {
  int row;
  int col;
  friend std::ostream& operator<<(std::ostream& out, const Position& pos);
};

std::ostream& operator<<(std::ostream& out, const Position& pos) {
  out << "->(" << pos.row << "," << pos.col << ")";
  return out;
}

Position start, finish;
int graph_size;
int** graph;
int pathLength;
ArrayQueue<Position>* path;
ArrayStack<Position>* pathStack;

void printGraph() {
  for (int i = 0; i < graph_size + 2; ++i) {
    for (int j = 0; j < graph_size + 2; ++j) {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool findPath() {
  std::ifstream inFile("route_test_setting.txt");
  if (inFile.is_open()) {
    std::string line;
    if (std::getline(inFile, line)) {
      std::stringstream ss(line);
      ss >> graph_size;
      graph = new int*[graph_size + 2];
      for (int i = 0; i < graph_size + 2; ++i) {
        graph[i] = new int[graph_size + 2];
      }
      // init all graph coordination is able to go
      for (int i = 1; i < graph_size + 1; ++i) {
        for (int j = 1; j < graph_size + 1; ++j) {
          graph[i][j] = 0;
        }
      }
      for (int i = 0; i < graph_size + 2; ++i) {
        // set bounds to false
        graph[0][i] = graph[graph_size + 1][i] = 1;
        graph[i][0] = graph[i][graph_size + 1] = 1;
      }
      //      printGraph();
    }
    if (std::getline(inFile, line)) {
      std::stringstream ss(line);
      // read start and finish position coordinates
      ss >> start.row >> start.col >> finish.row >> finish.col;
    }
    while (std::getline(inFile, line)) {
      // get obstacles's coordinates in graph
      int a, b;
      std::stringstream ss(line);
      ss >> a >> b;
      graph[a][b] = 1;
    }
    printGraph();
  }

  // find route from start to finish position, if get the route, return true, or
  // return false
  if (start.row == finish.row && start.col == finish.col) {
    pathLength = 0;
    return true;
  }
  // init offset
  Position offset[4];
  offset[0].row = 0;   // right
  offset[0].col = 1;   // right
  offset[1].row = 1;   // down
  offset[1].col = 0;   // down
  offset[2].row = 0;   // left
  offset[2].col = -1;  // left
  offset[3].row = -1;  // up
  offset[3].col = 0;   // up

  Position here = start;
  graph[here.row][here.col] = 2;  // mark start position
  int numberOfNbrs = 4;           // number of dirs around the position

  ArrayQueue<Position> aq;
  Position nbr;
  do {
    for (int i = 0; i < numberOfNbrs; ++i) {
      nbr.row = here.row + offset[i].row;
      nbr.col = here.col + offset[i].col;
      if (graph[nbr.row][nbr.col] == 0) {
        graph[nbr.row][nbr.col] = graph[here.row][here.col] + 1;
        if (nbr.row == finish.row && nbr.col == finish.col) break;
        aq.push(nbr);
      }
    }
    if (nbr.row == finish.row && nbr.col == finish.col) break;
    if (aq.empty()) {
      return false;
    }
    here = aq.front();
    aq.pop();
  } while (true);

  std::cout << "******************\n";
  printGraph();
  // construct the route
  pathLength = graph[finish.row][finish.col] - 2;
  path = new ArrayQueue<Position>(pathLength);
  pathStack = new ArrayStack<Position>(pathLength);

  // go back from finish coordinate
  here = finish;
  for (int j = pathLength - 1; j >= 0; --j) {
    path->push(here);
    pathStack->push(here);
    // find ancestor position
    for (int i = 0; i < numberOfNbrs; ++i) {
      nbr.row = here.row + offset[i].row;
      nbr.col = here.col + offset[i].col;
      if (graph[nbr.row][nbr.col] == j + 2) break;
    }
    here = nbr;
  }
  std::cout << *path << std::endl;
  std::cout << *pathStack << std::endl;
  return true;
}

int main() { findPath(); }
