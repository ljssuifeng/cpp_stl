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
  Position() = default;
  Position(int r, int c) : row(r), col(c) {}
};

std::ostream& operator<<(std::ostream& out, const Position& pos) {
  out << "->(" << pos.row << "," << pos.col << ")";
  return out;
}

// global variables
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

void markGraphElements() {
  std::ifstream inFile("graph_element_test_setting.txt");
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
      for (int i = 0; i < graph_size + 2; ++i) {
        for (int j = 0; j < graph_size + 2; ++j) {
          graph[i][j] = 0;
        }
      }
      //      printGraph();
    }
    while (std::getline(inFile, line)) {
      // get obstacles's coordinates in graph
      int a, b;
      std::stringstream ss(line);
      ss >> a >> b;
      graph[a][b] = 1;
    }
    printGraph();
    std::cout << "****************************" << std::endl;
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
  int numberOfNbrs = 4;
  int currentMarkedSign = 2;
  Position Nbr;
  Position here;
  ArrayQueue<Position> aq;

  for (int r = 1; r <= graph_size; ++r) {
    for (int c = 1; c <= graph_size; ++c) {
      if (graph[r][c] == 1) {  // find new element have not been marked
        graph[r][c] = currentMarkedSign;
        here = Position(r, c);
        aq.push(here);
        do {
          here = aq.front();
          aq.pop();
          for (int i = 0; i < numberOfNbrs; ++i) {
            Nbr.row = here.row + offset[i].row;
            Nbr.col = here.col + offset[i].col;
            if (graph[Nbr.row][Nbr.col] == 1) {
              graph[Nbr.row][Nbr.col] = currentMarkedSign;
              aq.push(Nbr);
            }
          }
        } while (!aq.empty());
        currentMarkedSign++;
      }
    }
  }
  printGraph();
}

int main() { markGraphElements(); }
