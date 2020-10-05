#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "queue.h"

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

void printGraph() {
  for (int i = 0; i < graph_size + 2; ++i) {
    for (int j = 0; j < graph_size + 2; ++j) {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool findPath() {
  std::ifstream inFile("setting.txt");
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
}

int main() { findPath(); }
