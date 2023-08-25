#ifndef PR2_DEMOS_PICKTASK_H
#define PR2_DEMOS_PICKTASK_H

#include "pr2_demo_lib/Task.h"
#include "pr2_demo_lib/Pr2Robot.h"

Task createPickPlaceTask()
{
  Task task;
  task.push_back(createAction({{-1.536, -0.026, -0.050, -1.407, 3.238, -1.556, -37.923},
                                {0.496, 0.067, 0.130, -1.972, 2.802, -1.773, -37.971},
                                {0.466, 0.094, 0.198, -1.314, 2.777, -1.265, -37.777}}, false));
  task.push_back(createAction(gripper_open));
  task.push_back(createAction({{0.409, 0.041, 0.188, -1.013, 2.824, -0.999, -37.723}}, false));
  task.push_back(createAction(gripper_close));
  task.push_back(createAction({{0.466, 0.094, 0.198, -1.314, 2.777, -1.265, -37.777},
                                {0.496, 0.067, 0.130, -1.972, 2.802, -1.773, -37.971},
                                {-1.536, -0.026, -0.050, -1.407, 3.238, -1.556, -37.923}
                                }, false));

  task.push_back(createAction({{-1.536, -0.026, -0.050, -1.407, 3.238, -1.556, -37.923},
                                {0.496, 0.067, 0.130, -1.972, 2.802, -1.773, -37.971},
                                {0.466, 0.094, 0.198, -1.314, 2.777, -1.265, -37.777},
                                {0.409, 0.041, 0.188, -1.013, 2.824, -0.999, -37.723}}, false));
  task.push_back(createAction(gripper_open));
  task.push_back(createAction({{0.466, 0.094, 0.198, -1.314, 2.777, -1.265, -37.777},
                                {0.496, 0.067, 0.130, -1.972, 2.802, -1.773, -37.971},
                                {-1.536, -0.026, -0.050, -1.407, 3.238, -1.556, -37.923}
                                }, false));

  return task;
}

#endif // PR2_DEMOS_PICKTASK_H