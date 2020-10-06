#pragma once
#include "structure_algorithms/queue/queue.h"
#include "task.h"

struct Job {
  ArrayQueue<Task> taskQ;  // serirals of job
  int length;              // total time of job serials
  int arrivalTime;         // timepoint when arrive this queue
  int id;                  // job id

  Job(int theId = 0) {
    id = theId;
    length = 0;
    arrivalTime = 0;
  }
  void addTask(int theMachine, int theTime) {
    Task theTask(theMachine, theTime);
    taskQ.push(theTask);
  }
  int removeNextTask() {
    int theTime = taskQ.front().time;
    taskQ.pop();
    length += theTime;
    return theTime;
  }
};
