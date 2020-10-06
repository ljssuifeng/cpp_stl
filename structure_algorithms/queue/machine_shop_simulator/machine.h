#pragma once
#include "job.h"
#include "structure_algorithms/queue/queue.h"

struct Machine {
  ArrayQueue<Job*> jobQ;  // jobs wait at this machine
  int changeTime;         // state convert time of this machine
  int totalWait;          // job wait total time at this machine
  int numTasks;           // serials count at this machine
  Job* activeJob;

  Machine() {
    totalWait = 0;
    numTasks = 0;
    activeJob = nullptr;
  }
};
