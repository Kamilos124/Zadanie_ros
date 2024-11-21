#include <zadanie_ros/SomePublisher.hpp>


double randomDoubleInRange(double min, double max, bool exclusive)
{
    double cos = RAND_MAX;
    if (exclusive)
    {
        return min + (max - min) * ((double)(rand()+1)/(cos+2));
    }
    return min + (max - min) * ((double)(rand())/cos);
}


void randomizePose(geometry_msgs::msg::Pose& pose)
{
    pose.position.x=randomDoubleInRange(-10,10,false);
    pose.position.y=randomDoubleInRange(-10,10,false);
    pose.position.z=randomDoubleInRange(-10,10,false);

    double yaw, pitch, roll;

    yaw = randomDoubleInRange(-M_PI, M_PI,false);
    pitch = randomDoubleInRange(-M_PI/2, M_PI/2, true);
    roll = randomDoubleInRange(-M_PI, M_PI,false);

    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    pose.orientation.x = sr * cp * cy - cr * sp * sy;
    pose.orientation.y = cr * sp * cy + sr * cp * sy;
    pose.orientation.z = cr * cp * sy - sr * sp * cy;
    pose.orientation.w = cr * cp * cy + sr * sp * sy;
}


SomePublisher::SomePublisher() : Node("some_publisher")
{
    publisher_ = this->create_publisher<geometry_msgs::msg::Pose>("/myPose", 20);
    timer_ = this->create_wall_timer(500ms, std::bind(&SomePublisher::callback_position, this)); 
    
}


void SomePublisher::callback_position() 
{
    auto pose = geometry_msgs::msg::Pose();
    randomizePose(pose);
    std::string message_position = std::to_string(pose.position.x) + ", " + std::to_string(pose.position.y) + ", " + std::to_string(pose.position.z) + ", ";
    std::string message_orientation = std::to_string(pose.orientation.w) + ", " + std::to_string(pose.orientation.x) + ", " + std::to_string(pose.orientation.y) + ", " + std::to_string(pose.orientation.z);
    std::string message = "Publish point: " + message_position + message_orientation; 
    RCLCPP_INFO(this->get_logger(), message.c_str());
    publisher_ -> publish(pose);
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SomePublisher>());
    rclcpp::shutdown();
    return 0;
}