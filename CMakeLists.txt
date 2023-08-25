cmake_minimum_required(VERSION 3.0.2)
project(pr2_demos)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  pr2_demo_lib
  roscpp
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pr2_demos
   CATKIN_DEPENDS pr2_demo_lib roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_demos src/pr2_demos.cpp)
target_link_libraries(robot_demos ${catkin_LIBRARIES} ${pr2_demo_lib_LIBRARIES})
add_dependencies(robot_demos ${catkin_EXPORTED_TARGETS})
