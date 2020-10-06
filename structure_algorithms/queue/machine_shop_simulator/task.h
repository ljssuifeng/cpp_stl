#pragma once

// job serials
struct Task {
  int machine;
  int time;

  Task(int theMachine = 0, int theTime = 0)
      : machine(theMachine), time(theTime) {}
};
