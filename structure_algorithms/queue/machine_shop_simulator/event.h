#include "structure_algorithms/my_exceptions.h"

class EventList {
 public:
  EventList(int theNumMachines, int theLargeTime) {
    if (theNumMachines < 1) {
      throw IllegalParameterValue("number of machine must be >= 1");
    }
    numMachines = theNumMachines;
    finishTime = new int[numMachines + 1];
    for (int i = 1; i <= numMachines; ++i) {
      finishTime[i] = theLargeTime;
    }
  }
  int nextEventMachine() {
    int p = 1;
    int time = finishTime[1];
    for (int i = 2; i <= numMachines; ++i) {
      if (finishTime[i] < time) {
        time = finishTime[i];
        p = i;
      }
    }
    return p;
  }

  int nextEventTime(int theMachine) { return finishTime[theMachine]; }

  void setFinishTime(int theMachine, int theTime) {
    finishTime[theMachine] = theTime;
  }

 private:
  int* finishTime;  // array for finish time
  int numMachines;  // number of machines
};
