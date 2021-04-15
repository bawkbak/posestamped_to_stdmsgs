cmake_minimum_required(VERSION 2.8.3)
project(posestamped_to_stdmsgs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(transform src/transform.cpp)
target_link_libraries(transform ${catkin_LIBRARIES})