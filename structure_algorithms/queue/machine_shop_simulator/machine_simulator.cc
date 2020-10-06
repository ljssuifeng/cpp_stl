#include "machine.h"
#include "event.h"
#include "job.h"
#include "task.h"

// global variables
int timeNow;
int numMachines;
int numJobs;
EventList* eList;
Machine* machineArray;
int largeTime = 1000;

void inputData() {
  using std::cout;
  using std::cin;
  using std::endl;

  cout << "Enter number of machines and jobs: " << endl;
  cin >> numMachines >> numJobs;
  if (numMachines < 1 || numJobs < 1) {
    throw IllegalParameterValue("number of machines and jobs must be  > 0.");
  }
  // generate machine and event queue
  eList = new EventList(numMachines, largeTime);
  machineArray = new Machine[numMachines + 1];

  // input machine state convert time
  cout << "Enter change-over times for machines" << endl;
  int ct;
  for (int j = 1; j <= numMachines; ++j) {
    cin >> ct;
    if (ct < 0) {
      throw IllegalParameterValue("change-over time must be > 0");
    }
    machineArray[j].changeTime = ct;
  }
  // input task
  Job* theJob;
  int numTasks, firstMachine, theMachine, theTaskTime;
  for (int i = 1; i <= numJobs; ++i) {
    cout << "Eneter number of tasks for job" << i << endl;
    cin >> numTasks;
    firstMachine = 0;
    if (numTasks < 1) {
      throw IllegalParameterValue("each job must have > 0 task.");
    }
    // generate task
    theJob = new Job(i);
    cout << "Enter the tasks (machine, time) in process order" << endl;
    for (int j = 1; j <= numTasks; ++j) {
      cin >> theMachine >> theTaskTime;
      if (theMachine < 1 || theMachine > numMachines) {
        throw IllegalInputData("bad machine number or taks times.");
      }
      if (j == 1) {
        firstMachine = theMachine;
      }
      theJob->addTask(theMachine, theTaskTime);
    }
    machineArray[firstMachine].jobQ.push(theJob);
  }
}

Job* changeState(int theMachine) {
  Job* lastJob;
  if (machineArray[theMachine].activeJob == nullptr) {
    lastJob = nullptr;
    if (machineArray[theMachine].jobQ.empty()) {
      eList->setFinishTime(theMachine, largeTime);
    } else {
      machineArray[theMachine].activeJob =
          machineArray[theMachine].jobQ.front();
      machineArray[theMachine].jobQ.pop();
      machineArray[theMachine].totalWait +=
          timeNow - machineArray[theMachine].activeJob->arrivalTime;
      machineArray[theMachine].numTasks++;
      int t = machineArray[theMachine].activeJob->removeNextTask();
      eList->setFinishTime(theMachine, timeNow + t);
    }
  } else {
    // right now, finish one job task
    lastJob = machineArray[theMachine].activeJob;
    machineArray[theMachine].activeJob = nullptr;
    eList->setFinishTime(theMachine,
                         timeNow + machineArray[theMachine].changeTime);
  }
  return lastJob;
}

bool moveToNextMachine(Job* theJob) {
  if (theJob->taskQ.empty()) {
    std::cout << "Job " << theJob->id << " has completed at " << timeNow
              << " Total wait was " << timeNow - theJob->length << std::endl;
    return false;
  } else {
    int p = theJob->taskQ.front().machine;
    machineArray[p].jobQ.push(theJob);
    theJob->arrivalTime = timeNow;
    if (eList->nextEventTime(p) == largeTime) {
      changeState(p);
    }
    return true;
  }
}

void simulate() {
  while (numJobs) {
    // at least one task to be resolved
    int nextToFinish = eList->nextEventMachine();
    timeNow = eList->nextEventTime(nextToFinish);

    Job* theJob = changeState(nextToFinish);
    if (theJob != nullptr && !moveToNextMachine(theJob)) {
      numJobs--;
    }
  }
}

void startShop() {
  for (int p = 1; p <= numMachines; ++p) {
    changeState(p);
  }
}

void outputStatistics() {
  using std::cout;
  using std::endl;
  cout << "Finish time = " << timeNow << endl;
  for (int p = 1; p <= numMachines; ++p) {
    cout << "Machine " << p << " completed " << machineArray[p].numTasks
         << " tasks" << endl;
    cout << "The total wait time was " << machineArray[p].totalWait << endl;
    cout << endl;
  }
}

int main() {
  inputData();
  startShop();
  simulate();
  outputStatistics();
  return 0;
}
