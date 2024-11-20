#ifndef SUBSCRIB_HPP
#define SUBSCRIB_HPP

#define POSE_SUB_QUEUE_SIZE 5
#define STRING_PUB_QUEUE_SIZE 5

#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/pose.hpp"  

/*

 SomeSubscriber


Node przyjmuje wiadomosc geometry_msgs/msg/pose z topica /myPose
Jezeli orientacja jest bardziej na wschod niz na zachod
wysyla wiadomosc std_msgs/msg/string na topic /dir


*/

class SomeSubscriber : public rclcpp::Node
{

public:

    SomeSubscriber();

private:

    double getYaw(const double& x, const double& y, const double& z, const double& w);

    void poseCallback(const geometry_msgs::msg::Pose::SharedPtr msg);

    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr pose_subscriber_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr str_publisher_;

};

#endif