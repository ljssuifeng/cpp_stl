#include "queue.h"
#include <array>

ArrayQueue<int>* arrq;
int toOutputCar;
int smallestCar;
int itsTrack;
bool putinHoldingTrack(int c, int numberOfTracks) {
  int bestTrack = numberOfTracks;
  int largestElementInTrack = 0;
  for (int i = 0; i < numberOfTracks - 1; ++i) {
    if (!arrq[i].empty()) {
      int elem = arrq[i].back();
      if (c > elem) {
        if (elem > largestElementInTrack) {
          largestElementInTrack = elem;
          bestTrack = i;
        }
      }
    } else {
      bestTrack = i;
    }
  }
  if (bestTrack == numberOfTracks) {
    return false;
  }
  arrq[bestTrack].push(c);
  std::cout << "put " << c << " into track: " << bestTrack << std::endl;
  for (int i = 0; i < numberOfTracks - 1; ++i) {
    if (!arrq[i].empty() && arrq[i].front() < smallestCar) {
      smallestCar = arrq[i].front();
      itsTrack = i;
    }
  }
  return true;
}

void outputFromHoldingTrack(int numberOfTracks, int numberOfCars) {
  arrq[itsTrack].pop();
  std::cout << "Move car " << smallestCar << " from holding track " << itsTrack
            << " to output track" << std::endl;
  smallestCar = numberOfCars + 2;
  for (int i = 0; i < numberOfTracks - 1; ++i) {
    if (!arrq[i].empty() && (arrq[i].front() < smallestCar)) {
      smallestCar = arrq[i].front();
      itsTrack = i;
    }
  }
  //  for (int i = 0; i < numberOfTracks - 1; ++i) {
  //    if (!arrq[i].empty() && arrq[i].front() == toOutputCar) {
  //      std::cout << "move car " << arrq[i].front() << " out from track " << i
  //                << std::endl;
  //      arrq[i].pop();
  //      if (toOutputCar < numberOfCar) {
  //        toOutputCar++;
  //        outputFromHoldingTrack(numberOfTracks, numberOfCar);
  //      }
  //    }
  //  }
}

bool railRoadSort(std::array<int, 9> initSerials, int numberOfCars,
                  int numberOfTracks) {
  toOutputCar = 1;
  arrq = new ArrayQueue<int>[numberOfTracks - 1];
  smallestCar = numberOfCars + 1;
  for (int i = 0; i < numberOfCars; ++i) {
    int c = initSerials[i];
    if (c == toOutputCar) {
      std::cout << "move car index " << toOutputCar
                << " from init track to output track" << std::endl;
      if (toOutputCar == numberOfCars) {
        return true;
      }
      toOutputCar++;
      while (smallestCar == toOutputCar) {
        outputFromHoldingTrack(numberOfTracks, numberOfCars);
        toOutputCar++;
      }
    } else {
      putinHoldingTrack(c, numberOfTracks);
    }
  }
}

int main() {
  std::array<int, 9> initSerials{3, 6, 9, 2, 4, 7, 1, 8, 5};
  railRoadSort(initSerials, initSerials.size(), 3);
}
