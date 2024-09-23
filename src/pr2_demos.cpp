#include <ros/ros.h>
#include <ros/package.h>

#include "pr2_demo_lib/Task.h"
#include "pr2_demo_lib/Pr2Robot.h"
#include "pr2_demo_lib/Parameters.h"

#include "pr2_demos/PickTask.h"
#include "pr2_demos/Macarena.h"
#include "pr2_demos/MacarenaSynchro.h"

#include <chrono>
#include <iostream>

Task createTaskInit()
{
  Task task;
  task.push_back(createAction({{ 0., 0.98625, 0., -1.92394, 0., -2.17469, 0. }},
                              {{ 0., 0.98625, 0., -1.92394, 0., -2.17469, 0.  }}, 2));
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
  params.insert(Parameter("ip", {"-i", "--ip"}, {""}));

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
    std::string ip = params.at("ip").getFirst();
    Task task = createDanceTask(ip);
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "synchro")
  {
    std::string ip = params.at("ip").getFirst();
    if(ip == "")
    {
      std::cout << "syncho dance require a synchro ip. Provide it using the -i or --ip option." << std::endl;
      return -1;
    }
     std::cout << "start synchro dance !" << std::endl;
    Task task = createDanceSynchroTask(ip);
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
