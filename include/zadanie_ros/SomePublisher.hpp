#ifndef PUBLISH_HPP
#define PUBLISH_HPP

#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose.hpp"  
#include "std_msgs/msg/string.hpp"
using namespace std::chrono_literals;

double randomDoubleInRange(double min, double max, bool exclusive=false);
void randomizaPose(geometry_msgs::msg::Pose& pose);

class SomePublisher : public rclcpp::Node
{
    private:
        void callback_position();
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    public:
        SomePublisher();
};

#endif