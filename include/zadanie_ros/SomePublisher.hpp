#ifndef PUBLISH_HPP
#define PUBLISH_HPP


#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose.hpp"  


class SomePublisher : public rclcpp::Node
{
    private:
        void callback_timer() 
        {
            auto message = geometry_msgs::msg::Pose;
            message.data_x = geometry_msgs::msg::Pose::Point[0];
            message.data_y = geometry_msgs::msg::Pose::Point[1];
            message.data_z = geometry_msgs::msg::Pose::Point[2];
            RCLCPP_INFO(this->get_logger(), "Publish point: (%f, %f, %f)", message.data_x, message.data_y, message.data_z);
            publisher_ -> publish(message);
        };
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
    public:
        SomePublisher() : Node("some_publisher"), count(0) {};
};

#endif