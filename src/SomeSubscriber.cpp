#include <zadanie_ros/SomeSubscriber.hpp>
#include <cmath>


SomeSubscriber::SomeSubscriber()
    : Node("some_subscriber")
{

    pose_subscriber_ = this->create_subscription<geometry_msgs::msg::Pose>(
            "/myPose", POSE_SUB_QUEUE_SIZE,
            std::bind(&SomeSubscriber::poseCallback, this, std::placeholders::_1));

    str_publisher_ = create_publisher<std_msgs::msg::String>("/dir", STRING_PUB_QUEUE_SIZE);

    RCLCPP_INFO(this->get_logger(), "Subscriber node is running");
}


double SomeSubscriber::getYaw(const double& x, const double& y, const double& z, const double& w)
{
    double siny_cosp = 2*(w*z + x*y);
    double cosy_cosp = 1 - 2*(y*y + z*z);
    return std::atan2(siny_cosp, cosy_cosp);
}


void SomeSubscriber::poseCallback(const geometry_msgs::msg::Pose::SharedPtr msg){
    double yaw = getYaw(msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w);
    RCLCPP_INFO(this->get_logger(), "HEADING: %f radians", yaw);
    if(std::fabs(yaw) > M_PI/2){
        auto message = std_msgs::msg::String();
        message.data = "RURA MUSI JEBAC";
        str_publisher_->publish(message);
    }
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SomeSubscriber>());
    rclcpp::shutdown();
    return 0;
}