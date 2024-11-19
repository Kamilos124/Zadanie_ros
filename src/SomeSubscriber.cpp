#include <zadanie_ros/SomePublisher.hpp>



int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SomeSubscriber>());
    rclcpp::shutdown();
    return 0;
}