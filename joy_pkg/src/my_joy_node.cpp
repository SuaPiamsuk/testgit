// roscore
// rosrun joy joy_node 
// rosrun joy_pkg my_joy_node
// rosrun turtlesim turtlesim_node


#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>



class Teleop {
    public:
        Teleop();
    
    private:
        void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

        ros::NodeHandle nh;
        int linear, angular;
        double linear_scale, angular_scale;
        ros::Publisher vel_pub;
        ros::Subscriber joy_sub;
};


Teleop::Teleop(){
    
    // twist.angular.z = a_scale_*joy->axes[angular_];
   

    vel_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
    joy_sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&Teleop::joyCallback,this);
}


void Teleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){
    geometry_msgs::Twist twist;
    twist.linear.x = 1*joy->axes[1];
    twist.angular.z = 1*joy->axes[2];
    vel_pub.publish(twist);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "teleop_turtle");
    Teleop teleop_turtle;
    ros::spin();
}


// #include <ros/ros.h>
// #include <geometry_msgs/Twist.h>
// #include <sensor_msgs/Joy.h>


// class TeleopTurtle
// {
// public:
//   TeleopTurtle();

// private:
//   void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

//   ros::NodeHandle nh_;

//   int linear_, angular_;
//   double l_scale_, a_scale_;
//   ros::Publisher vel_pub_;
//   ros::Subscriber joy_sub_;

// };


// TeleopTurtle::TeleopTurtle()
// //   linear_(1),
// //   angular_(2)
// {

// //   nh_.param("axis_linear", linear_, linear_);
// //   nh_.param("axis_angular", angular_, angular_);
// //   nh_.param("scale_angular", a_scale_, a_scale_);
// //   nh_.param("scale_linear", l_scale_, l_scale_);


//   vel_pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);


//   joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);
// //   joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback);

// }

// void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
// {
//   geometry_msgs::Twist twist;
//   twist.angular.z = a_scale_*joy->axes[angular_];
//   twist.linear.x = l_scale_*joy->axes[linear_];
//   vel_pub_.publish(twist);
// }


// int main(int argc, char** argv)
// {
//   ros::init(argc, argv, "teleop_turtle");
//   TeleopTurtle teleop_turtle;

//   ros::spin();
// }