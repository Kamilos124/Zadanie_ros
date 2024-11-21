#ifndef PUBLISH_HPP
#define PUBLISH_HPP

#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose.hpp"  
#include "std_msgs/msg/string.hpp"
using namespace std::chrono_literals;

class SomePublisher : public rclcpp::Node
{
    private:
        double randomDoubleInRange(double min, double max, bool exclusive=false);
        void randomizaPose(geometry_msgs::msg::Pose& pose);
        void callback_position();
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr publisher_;
    public:
        SomePublisher();
};

#endif