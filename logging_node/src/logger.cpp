#include "logger.hpp"
#include <string>

Logger_node::Logger_node() : Node("logging_node") {

  // Service call
  this->log_entry_ = create_service<logging_interfaces::srv::Logentry>(
      "set_log_entry", std::bind(&Logger_node::log_entry_callback, this,
                                 std::placeholders::_1, std::placeholders::_2));

  // Publisher
  this->log_publisher_ = this->create_publisher<
                         logging_interfaces::msg::Logentry>("log_topic", 1);
}

void Logger_node::log_entry_callback(
    const shared_ptr<logging_interfaces::srv::Logentry::Request> request,
    const shared_ptr<logging_interfaces::srv::Logentry::Response> response) {

  // timestamp
  auto now = chrono::system_clock::now();
  auto now_s = chrono::time_point_cast<chrono::seconds>(now).time_since_epoch();
  auto now_ns =
      chrono::time_point_cast<chrono::nanoseconds>(now).time_since_epoch();
  auto now_ns_fraction =
      now_ns - chrono::duration_cast<chrono::seconds>(now_ns);

  int32_t now_s_c = now_s.count();
  uint32_t now_ns_c = now_ns_fraction.count();

  // message
  logging_interfaces::msg::Logentry msg_out;

  // populate message
  msg_out.header.stamp.sec = now_s_c;
  msg_out.header.stamp.nanosec = now_ns_c;
  msg_out.user = request->user;
  msg_out.entry = request->entry;

  // publish message
  this->log_publisher_->publish(msg_out);

  // service response
  response->out = "[" + std::to_string(now_s_c) + "." +
                  std::to_string(now_ns_c) + "]: " + request->user +
                  ": " + request->entry;
}