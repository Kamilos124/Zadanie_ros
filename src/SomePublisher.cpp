#include <zadanie_ros/SomePublisher.hpp>


SomePublisher::SomePublisher() : Node("some_publisher"), count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("/myPose", 20);
    timer_ = this->create_wall_timer(500ms, std::bind(&SomePublisher::callback_timer, this)); 
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SomePublisher>());
    rclcpp::shutdown();
    return 0;
}