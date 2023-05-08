#include <iostream>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"

#include "logging_interfaces/msg/logentry.hpp"
#include "logging_interfaces/srv/logentry.hpp"
  
using namespace std;

class Logger_node : public rclcpp::Node {

public:
Logger_node();

private:
  rclcpp::Service<logging_interfaces::srv::Logentry>::SharedPtr log_entry_;
  rclcpp::Publisher<logging_interfaces::msg::Logentry>::SharedPtr log_publisher_;


void log_entry_callback(
    const shared_ptr<logging_interfaces::srv::Logentry::Request> request,
    const shared_ptr<logging_interfaces::srv::Logentry::Response> response);
};