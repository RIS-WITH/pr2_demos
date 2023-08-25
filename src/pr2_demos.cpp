#include <ros/ros.h>
#include <ros/package.h>

#include "pr2_demo_lib/Task.h"
#include "pr2_demo_lib/Pr2Robot.h"
#include "pr2_demo_lib/Parameters.h"

#include "pr2_demos/PickTask.h"
#include "pr2_demos/Macarena.h"

#include <chrono>
#include <iostream>

Task createTaskInit()
{
  Task task;
  task.push_back(createAction({{ 0.096, 0.802, 0.198, -2.049, -0.020, -1.877, 31.447 }},
                              {{{ 0.096, 0.802, 0.198, -2.049, -0.020, -1.877, 31.447 }}}, 2));
  //task.push_back(createAction(head_front));
  task.push_back(createAction(gripper_close));

  return task;
}

void spinThread(bool* is_running)
{
  while((*is_running == true) && (ros::ok()))
  {
    ros::spinOnce();
    usleep(100);
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pr2_demos");

  Parameters params;
  params.insert(Parameter("task", {"-t", "--task"}));
  params.insert(Parameter("language", {"-l", "--language"}, {"fr"}));

  params.set(argc, argv);
  params.display();

  bool is_running = true;
  std::thread spin_thread(spinThread,&is_running);
  
  Pr2Robot robot(true);

  if(params.at("task").getFirst() == "init")
  {
    Task init_task = createTaskInit();
    executeTask(&robot, init_task);
  }
  else if(params.at("task").getFirst() == "dance")
  {
    std::cout << "start dance !" << std::endl;
    Task task = createDanceTask();
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "pick")
  {
    Task task = createPickPlaceTask();
    executeTask(&robot, task);
    task = createTaskInit();
    executeTask(&robot, task);
  }

  is_running = false;
  spin_thread.join();

  return 0;
}
