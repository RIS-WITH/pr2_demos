#ifndef PR2_DEMOS_TRANSITIONPR2_H
#define PR2_DEMOS_TRANSITIONPR2_H

#include "pr2_demo_lib/Pr2Robot.h"
#include "pr2_demo_lib/Task.h"

Task createResetTransitionPr2Task()
{
  Task task;

  task.push_back(createActionMove(-0.53, -0.98));

  task.push_back(createActionTurn(-25));

  return task;
}

Task createTransitionPr2Task(const std::string& synchro_ip)
{
  Task task;

  task.push_back(createActionLaunchSynchro(synchro_ip));

  task.push_back(createActionTurn(25));

  task.push_back(createActionMove(0.53, 0.98));

  return task;
}

#endif // PR2_DEMOS_TRANSITIONPR2_H
