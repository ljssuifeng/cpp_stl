#include "stack.h"
/****array stack is faster than linked stack!!! ********/
/****array stack and linked stack is faster than derived stack***********/
// whether the switch box is routable
bool checkBox(int net[], int n) {
  ArrayStack<int>* s = new ArrayStack<int>(n);
  for (int i = 0; i < n; ++i) {
    if (!s->empty()) {
      if (net[i] == net[s->top()]) {
        s->pop();
      } else {
        s->push(i);
      }
    } else {
      s->push(i);
    }
  }
  if (s->empty()) {
    std::cout << "Switch box is routable.\n";
    return true;
  }
  std::cout << "Switch box is not routable.\n";
  return false;
}

// rail road cars
ArrayStack<int>* track;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;  // smallest car in which track

bool putInHoldingTrack(int c) {
  int bestTrack = 0;
  int bestTop = numberOfCars + 1;

  for (int i = 1; i <= numberOfTracks; ++i) {
    if (!track[i].empty()) {
      int topCar = track[i].top();
      if (c < topCar && topCar < bestTop) {
        bestTop = topCar;
        bestTrack = i;
      }
    } else {
      if (bestTrack == 0) {
        bestTrack = i;
      }
    }
  }
  if (bestTrack == 0) {
    return false;
  }
  track[bestTrack].push(c);
  std::cout << "Move car " << c << " from input track to holding track "
            << bestTrack << std::endl;
  if (c < smallestCar) {
    smallestCar = c;
    itsTrack = bestTrack;
  }
  return true;
}

void outputFromHoldingTrack() {
  track[itsTrack].pop();
  std::cout << "Move car " << smallestCar << " from holding track " << itsTrack
            << " to output track" << std::endl;
  smallestCar = numberOfCars + 2;
  for (int i = 1; i <= numberOfTracks; ++i) {
    if (!track[i].empty() && (track[i].top() < smallestCar)) {
      smallestCar = track[i].top();
      itsTrack = i;
    }
  }
}

bool railRoad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks) {
  numberOfCars = theNumberOfCars;
  numberOfTracks = theNumberOfTracks;

  track = new ArrayStack<int>[theNumberOfTracks + 1];

  int nextCarToOutput = 1;
  smallestCar = theNumberOfCars + 1;

  for (int i = 1; i <= theNumberOfCars; ++i) {
    if (inputOrder[i] == nextCarToOutput) {
      std::cout << "Move car " << inputOrder[i]
                << " from input track to output track" << std::endl;
      nextCarToOutput++;
      while (smallestCar == nextCarToOutput) {
        outputFromHoldingTrack();
        nextCarToOutput++;
      }
    } else {
      if (!putInHoldingTrack(inputOrder[i])) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  using std::cout;
  using std::endl;
  DerivedArrayStack<double> das(10);
  cout << "is das empty? " << std::boolalpha << das.empty() << endl;

  das.push(12);
  das.push(23);
  das.push(34);
  cout << "das size:" << das.size() << endl;
  cout << "top element of das is: " << das.top() << endl;
  das.pop();
  cout << "size of das after pop is:" << das.size() << endl;
  das.pop();
  das.pop();
  //  das.pop();   // will throw exception

  ArrayStack<int> as(2);
  as.push(2);
  as.push(22);
  as.push(222);

  cout << "as size: " << as.size() << endl;
  cout << "as is empty? " << std::boolalpha << as.empty() << endl;
  cout << "as top element is: " << as.top() << endl;
  as.pop();
  cout << "as size after pop: " << as.size() << endl;
  as.pop();
  as.pop();
  //  as.pop(); //throw exception here   stack empty

  DerivedLinkedStack<double> dls(10);
  cout << "is dls empty? " << std::boolalpha << dls.empty() << endl;

  dls.push(12);
  dls.push(23);
  dls.push(34);
  cout << "dls size:" << dls.size() << endl;
  cout << "top element of dls is: " << dls.top() << endl;
  dls.pop();
  cout << "size of dls after pop:" << dls.size() << endl;
  dls.pop();
  dls.pop();
  //  dls.pop();  // will throw exception

  LinkedStack<int> ls(2);
  ls.push(2);
  ls.push(22);
  ls.push(222);

  cout << "ls size: " << ls.size() << endl;
  cout << "ls is empty? " << std::boolalpha << ls.empty() << endl;
  cout << "ls top element is: " << ls.top() << endl;
  ls.pop();
  cout << "ls size after pop: " << ls.size() << endl;
  ls.pop();
  ls.pop();
  //  ls.pop();  // throw exception here   stack empty

  int carOrder[]{0, 3, 6, 9, 4, 8, 1, 2, 7, 10, 5};
  railRoad(carOrder, 10, 3);

  int net[]{1, 2, 2, 1, 3, 3, 4, 4};
  checkBox(net, 8);
}
