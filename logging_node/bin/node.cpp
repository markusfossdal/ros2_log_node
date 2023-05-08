#include "logger.hpp"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Logger_node>());
  rclcpp::shutdown();
  return 0;
}