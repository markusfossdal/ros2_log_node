cmake_minimum_required(VERSION 3.8)
project(logging_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(ament_cmake REQUIRED)
find_package(logging_interfaces REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(node bin/node.cpp src/logger.cpp)

target_include_directories(node PRIVATE
    include
    # ${std_msgs_INCLUDE_DIRS}
    ${logging_interfaces_INCLUDE_DIRS}

)

target_link_libraries(node PRIVATE 
    rclcpp::rclcpp
    # ${std_msgs_LIBRARIES}
    ${logging_interfaces_LIBRARIES}
)

install(TARGETS node DESTINATION lib/${PROJECT_NAME})

ament_package()
