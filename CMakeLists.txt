cmake_minimum_required(VERSION 3.0.2)
project(ros_px4avd)

find_package(catkin REQUIRED COMPONENTS
  mavros
  roscpp
  sensor_msgs
  std_msgs
  iq_gnc
)


catkin_package(

)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


#LiDAR Sensor Test Program
add_executable(sensorscr src/sensor.cpp ${RPLIDAR_SDK_SRC})
target_link_libraries(sensorscr ${catkin_LIBRARIES})

#Avoidance Instance
add_executable(testavoid src/avoid.cpp ${RPLIDAR_SDK_SRC})
target_link_libraries(testavoid ${catkin_LIBRARIES})
