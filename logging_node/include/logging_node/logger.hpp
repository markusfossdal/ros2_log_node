#include <iostream>
#include <string>

#include "rclcpp/rclcpp.hpp"

class Logger_node : public rclcpp::Node {

public:
Logger_node();

private:
  rclcpp::Service<std_msgs::msg::StringArray>::SharedPtr log_entry;


}