#include <iostream>
#include <string>
#include <vector>

#include "task.h"
#include "scheduler.h"

using namespace std;

int main (int argc, char** argv) 
{   
  string s1("home");
  string s2("office");

  unsigned int task_count;

  if(argc > 1) {
    task_count = stoi(argv[1]);
  }
  else {
    task_count = 10;
  }

  double one_hour = 60 * 60 * 60;
  double task_duration = one_hour / 2.0;

  double window_start = 0;
  double window_end = window_start + (task_duration * task_count * task_count);

  vector<Task*> tasks;

  for (int i = 0; i < task_count; ++i)
  {
    tasks.push_back(new Task(i, window_start, window_end, task_duration, s1, s2));
  }


  Scheduler scheduler(&tasks);
  bool worked = scheduler.solve(-1, "");

  if(worked)  {
    cout<< "Schedule found" << worked << "\n";
    for(auto & tp : tasks) {
      cout<< "Is start time "<<tp->getExecTime() << " after start? "
       << (tp->getExecTime() >= tp->getStart()) << "\n";
    } 
  }
  else {
    cout<< "No schedule found"<< endl;
  }

  return 0;

}
