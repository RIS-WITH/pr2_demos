#ifndef PR2_DEMOS_SYNCHROMACARENA_H
#define PR2_DEMOS_SYNCHROMACARENA_H

#include "pr2_demo_lib/Pr2Robot.h"
#include "pr2_demo_lib/Task.h"

Task createTestSynchroTask()
{
  Task task;

  task.push_back(createActionTurn(25));

  task.push_back(createActionMove(1.04, 0.57));

  return task;
}

Task createResetCrashTask()
{
  Task task;

  task.push_back(createActionMove(-1.04, -0.57));

  task.push_back(createActionTurn(-25));

  return task;
}

Task createTaskOneFront()
{
  Task task;

  task.push_back(createActionMove(1., 0));

  return task;
}

Task createTaskOneBack()
{
  Task task;

  task.push_back(createActionMove(-1., 0));

  return task;
}

Task createTaskOneRight()
{
  Task task;

  task.push_back(createActionMove(0., 1.));

  return task;
}

Task createTaskOneLeft()
{
  Task task;

  task.push_back(createActionMove(0., -1.));

  return task;
}

Task createDanceSynchroTask(const std::string& synchro_ip)
{
  Task task;

  task.push_back(createActionLaunchSynchro(synchro_ip));

  /*task.push_back(createActionTurn(25));

  task.push_back(createActionMove(1.04, 0.57));*/

  //task.push_back(createActionSynchro(synchro_ip));

  task.push_back(createAction({
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.}
  },

                              {{0., 0.98625, 0., -1.92394, 0., -2.17469, 0.}, {-1.376, -0.228, 0., -1.412, 0.13936, -0.098, -1.6901}}));

  task.push_back(createActionSpeak("Bonjour, je m'appel P R 2"));

  task.push_back(createAction({
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.},
                                {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.}
  },

                              {{-1.373, -0.189, 0.16787, -1.191, -0.30564, -0.446, -1.76587}, {-1.373, -0.14833, 0.113, -1.321, 0.54236, -0.098, -2.2666}, {-1.373, -0.189, 0.16787, -1.191, -0.30564, -0.446, -1.76587}, {-1.373, -0.14833, 0.113, -1.321, 0.54236, -0.098, -2.2666}, {-1.373, -0.189, 0.16787, -1.191, -0.30564, -0.446, -1.76587}, {-1.373, -0.14833, 0.113, -1.321, 0.54236, -0.098, -2.2666}}, 0.7));

  // task.push_back(createActionWaitSynchro());

  task.push_back(createActionSpeak("Avec mes deux bras puissant, mon but est de pouvoir vous aider dans vos taches quotidiennes."));

  task.push_back(createAction({
                                {1.0755,  -0.304,  0.,      -1.2864, 0.,      -0.164,  1.476  }, // 60
                                {1.332,   0.2788,  0.,      -1.943,  0.,      -1.1657, 0      },
                                {1.0755,  -0.304,  0.,      -1.2864, 0.,      -0.164,  1.476  },
                                {0.2861,  0.27886, 1.38366, -1.943,  0.67329, -0.58,   1.0678 },
                                {0.36922, 0.27886, 1.38366, -1.943,  0.48387, -0.58,   1.35149},
                                {0.2861,  0.27886, 1.38366, -1.943,  0.67329, -0.58,   1.0678 },
                                {0.36922, 0.27886, 1.38366, -1.943,  0.48387, -0.58,   1.35149},
                                {0.2861,  0.27886, 1.38366, -1.943,  0.67329, -0.58,   1.0678 }
  },

                              {{-0.99118, -0.35855, 0.07096, -1.12875, -0.26242, -0.4938, -1.14112}, // 60
                               {-1.552, 0.2083, 0., -1.98, 0.052, -1.33, 0},
                               {-0.99118, -0.35855, 0.07096, -1.12875, -0.26242, -0.4938, -1.14112},
                               {-0.061, 0.3777, 0.154, -1.98, 0.052, -1.33, 0},
                               {-0.061, 0.3777, 0.154, -1.98, 0.052, -1.33, 0},
                               {-0.061, 0.3777, 0.154, -1.98, 0.052, -1.33, 0},
                               {-0.061, 0.3777, 0.154, -1.98, 0.052, -1.33, 0},
                               {-0.061, 0.3777, 0.154, -1.98, 0.052, -1.33, 0}}));

  task.push_back(createActionSynchro(synchro_ip));
  // task.push_back(createActionLaunchSynchro(synchro_ip));
  //  task.push_back(createActionSpeak("Je suis vraiment heureux que vous soyez ici. Je suis sure que vous allez adorer ce que vous allez voire."));

  task.push_back(createAction({
                                {0.59245, 0.06705, 0.29680, -1.943,   -1.3043, -0.28357, -0.75871},
                                {0.09398, 0.21196, 0.50474, -1.94734, -1.3043, -0.10853, -0.23958},
                                {0.59245, 0.06705, 0.29680, -1.943,   -1.3043, -0.28357, -0.75871},
                                {0.09398, 0.21196, 0.50474, -1.94734, -1.3043, -0.10853, -0.23958},
                                {0.59245, 0.06705, 0.29680, -1.943,   -1.3043, -0.28357, -0.75871}
  },

                              {{-0.57, 0.0534, -0.21857, -1.9462, 1.9299, -0.2141, -0.0611}, {-0.0817, 0.2081, -0.5873, -1.9462, 1.35242, -0.26096, 0.13846}, {-0.57, 0.0534, -0.21857, -1.9462, 1.9299, -0.2141, -0.0611}, {-0.0817, 0.2081, -0.5873, -1.9462, 1.35242, -0.26096, 0.13846}, {-0.57, 0.0534, -0.21857, -1.9462, 1.9299, -0.2141, -0.0611}}, 1.5));

  // task.push_back(createActionWaitSynchro());

  task.push_back(createActionSpeak("N'est-ce pas impressionant de pouvoir faire ca ?"));

  task.push_back(createActionSynchro(synchro_ip));
  // task.push_back(createActionLaunchSynchro(synchro_ip));

  task.push_back(createActionTorso(0.15));
  task.push_back(createAction({
                                {0.59245,   0.06705,   0.29680,  -1.943,    -1.3043,   -0.28357,  -0.75871},
                                {0.,        0.,        0.,       0.,        3.14159,   0.,        0.      }, // 210
                                {0.,        0.,        0.,       0.,        3.14159,   0.,        0.      },
                                {0.,        0.,        0.,       0.,        0.,        0.,        0.      },
                                {0.,        0.,        0.,       0.,        0.,        0.,        0.      },
                                {0.,        0.310416,  0.900958, -0.480134, -0.707181, -0.041817, 0.      },
                                {0.,        0.054721,  1.80192,  -1.53615,  -1.41436,  -0.083634, 0.      },
                                {0.,        0.054721,  1.80192,  -1.53615,  -1.41436,  -0.083634, 0.      }, // 270
                                {0.995512,  -0.477485, 0.086038, -1.80265,  0.082379,  -0.392682, 0.      }, // 280
                                {0.995512,  -0.477485, 0.086038, -1.80265,  0.082379,  -0.392682, 0.      },
                                {-0.062598, 0.988788,  1.52115,  -1.02332,  1.00028,   -0.271272, 0.      },
                                {-0.062598, 0.988788,  1.52115,  -1.02332,  1.00028,   -0.271272, 0.      },
                                {1.48634,   0.555463,  3.08609,  -1.52972,  -0.127823, -0.514661, 0.      },
                                {0.,        0.,        0.,       -1.52,     0,         -1.52,     0.      }
  },

                              {{0., 0., 0., 0., 3.14159, 0., 0.}, {0., 0., 0., 0., 3.14159, 0., 0.}, // 210
                               {0., 0., 0., 0., 0., 0., 0.},
                               {0., 0., 0., 0., 0., 0., 0.},
                               {0, -0.035535, -1.22957, -1.55524, -1.5109, -0.219097, 0.},
                               {0, -0.035535, -1.33283, -1.55524, -1.5109, -0.385019, 0.},
                               {0, -0.105499, -1.36273, -1.55524, -1.5109, -0.219097, 0.}, // 260
                               {-1.04851, -0.472102, -0.184554, -1.62857, 0.125212, -0.756032, 0.},
                               {-1.04851, -0.472102, -0.184554, -1.62857, 0.125212, -0.756032, 0.}, // 280
                               {-0.139155, 1.08159, -1.80182, -1.62857, -1.03803, -0.18769, 0.},
                               {-0.139155, 1.21011, -1.85966, -1.45404, -1.03803, -0.382147, 0.},
                               {-1.57606, 0.575569, -3.09033, -1.45404, 0.157183, -0.703993, 0.},
                               {-1.57606, 0.575569, -3.09033, -1.45404, 0.157183, -0.703993, 0.}, // 320
                               {0., 0., 0., -1.52, 0, -1.52, 0.}},
                              1.4));

  task.push_back(createActionSpeak("Hey makaraina !"));

  task.push_back(createAction({
                                {0., 1.2584,  0., -1.94338, 0., -0.974109, 0 },
                                {0., 0.98625, 0., -1.92394, 0., -2.17469,  0.}
  },

                              {{0., 1.2584, 0., -1.94338, 0., -0.974109, 0}, {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.}}));

  task.push_back(createActionSynchro(synchro_ip));
  // task.push_back(createActionWaitSynchro(synchro_ip));

  task.push_back(createActionTorso(0.));

  task.push_back(createActionSpeak("Bon, bon, bonjour. je suis P"));
  task.push_back(createActionSpeak("P R 2."));

  task.push_back(createAction({
                                {-0.238, 0.612,  0.128,  -1.409, 11.536, -1.551, -37.484},
                                {0.261,  0.271,  0.379,  -0.939, 13.155, -0.784, -36.688},
                                {0.811,  0.123,  -0.611, -1.266, 12.013, -0.426, -36.416},
                                {1.390,  -0.324, 0.455,  -1.653, 13.266, -1.056, -34.664}
  },

                              {{-0.505, 0.646, 0.146, -1.688, -5.381, -1.377, 113.392}, {-0.292, 0.555, -0.140, -1.747, -7.628, -0.581, 112.677}, {-0.061, 0.567, -0.536, -1.145, -7.652, -1.144, 113.032}, {-0.145, 0.479, -0.187, -1.699, -8.796, -0.584, 112.959}}, 1));

  task.push_back(createActionDelay(750));

  task.push_back(createActionSpeak("aider. puissant. heureux. adorer. impressionant? makaraina.\
                                    Un robot n'est rien de plus qu'un ordinateur connecté à des moteurs et des capteurs.\
                                    Un robot ne pense pas, ne vois pas, n'a pas d'aimotions, n'a pas de sentiments. Un robot n'est ni heureux ni triste...")); /*\
                                     Tout ce que vous venez de voir n'est qu'un script.\
                                     Il est temps de voir ce qu'il y a derriaire la machine."));*/

  task.push_back(createAction({
                                {1.441, -0.295,  -0.057, -1.393,   11.894, -1.041,   -34.825},
                                {0.950, -0.019,  0.041,  -1.403,   250,    -1.523,   250    },
                                {0.815, 0.125,   1.228,  -1.407,   11.923, -1.837,   -34.029},
                                {0.096, 0.802,   0.198,  -2.049,   12.410, -1.877,   31.447 },
                                {0.,    0.98625, 0.,     -1.92394, 0.,     -2.17469, 0.     }
  },

                              {{-0.463, -0.345, -2.418, -1.032, -8.191, -1.229, 25.087}, {0.145, -0.012, -2.306, -1.085, -250, -1.227, -25}, {-0.260, -0.144, -0.752, -1.097, -8.064, -1.459, 25.097}, {0.096, 0.802, 0.198, -2.049, -0.020, -1.877, 15.607}, {0., 0.98625, 0., -1.92394, 0., -2.17469, 0.}}, 3.5));

  task.push_back(createActionSynchro(synchro_ip));

  /*task.push_back(createActionMove(-1.04, -0.57));

  task.push_back(createActionTurn(-25));*/

  return task;
}

#endif // PR2_DEMOS_SYNCHROMACARENA_H
