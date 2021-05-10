#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

#include <sstream>

class transform{
     public:
     transform(){
          msg_sub = n.subscribe("localization_gps_imu/odometry", 1000,  &transform::msgCallback, this);

          msg_pub_seq = n.advertise<std_msgs::Int32>("localization_gps_imu/odometry/header/seq", 1000);
          msg_pub_stamp_sec = n.advertise<std_msgs::Int32>("localization_gps_imu/odometry/header/stamp/sec", 1000);
          msg_pub_stamp_nsec = n.advertise<std_msgs::Int32>("localization_gps_imu/odometry/header/stamp/nsec", 1000);
          msg_pub_frame_id = n.advertise<std_msgs::String>("localization_gps_imu/odometry/header/frame_id", 1000);

          msg_pub_child_id = n.advertise<std_msgs::String>("localization_gps_imu/odometry/child_frame_id", 1000);

          msg_pub_position_x = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/position/x", 1000);
          msg_pub_position_y = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/position/y", 1000);
          msg_pub_position_z = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/position/z", 1000);

          msg_pub_orientation_x = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/orientation/x", 1000);
          msg_pub_orientation_y = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/orientation/y", 1000);
          msg_pub_orientation_z = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/orientation/z", 1000);
          msg_pub_orientation_w = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/pose/orientation/w", 1000);

          msg_pub_twist_linear_x = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/linear/x", 1000);
          msg_pub_twist_linear_y = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/linear/y", 1000);
          msg_pub_twist_linear_z = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/linear/z", 1000);

          msg_pub_twist_angular_x = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/angular/x", 1000);
          msg_pub_twist_angular_y = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/angular/y", 1000);
          msg_pub_twist_angular_z = n.advertise<std_msgs::Float64>("localization_gps_imu/odometry/twist/angular/z", 1000);


     }
     void msgCallback(const nav_msgs::Odometry::ConstPtr& input){
          ROS_INFO("%s", "recieve localization_gps_imu/odometry\n");
          std_msgs::Float64 output_float;
          std_msgs::String output_string;
          std_msgs::Int32 output_int;

          output_float.data = input->pose.pose.position.x;
          msg_pub_position_x.publish(output_float);

          output_float.data = input->pose.pose.position.y;
          msg_pub_position_y.publish(output_float);

          output_float.data = input->pose.pose.position.z;
          msg_pub_position_z.publish(output_float);

          output_float.data = input->pose.pose.orientation.x;
          msg_pub_orientation_x.publish(output_float);

          output_float.data = input->pose.pose.orientation.y;
          msg_pub_orientation_y.publish(output_float);

          output_float.data = input->pose.pose.orientation.z;
          msg_pub_orientation_z.publish(output_float);

          output_float.data = input->pose.pose.orientation.w;
          msg_pub_orientation_w.publish(output_float);

          output_int.data = input->header.seq;
          msg_pub_seq.publish(output_int);

          output_int.data = input->header.stamp.sec;
          msg_pub_stamp_sec.publish(output_int);

          output_int.data = input->header.stamp.nsec;
          msg_pub_stamp_nsec.publish(output_int);

          output_string.data = input->header.frame_id;
          msg_pub_frame_id.publish(output_string);

          output_string.data = input->child_frame_id;
          msg_pub_child_id.publish(output_string);

          output_float.data = input->twist.twist.linear.x;
          msg_pub_twist_linear_x.publish(output_float);

          output_float.data = input->twist.twist.linear.y;
          msg_pub_twist_linear_y.publish(output_float);

          output_float.data = input->twist.twist.linear.z;
          msg_pub_twist_linear_z.publish(output_float);

          output_float.data = input->twist.twist.angular.x;
          msg_pub_twist_angular_x.publish(output_float);

          output_float.data = input->twist.twist.angular.y;
          msg_pub_twist_angular_y.publish(output_float);

          output_float.data = input->twist.twist.angular.z;
          msg_pub_twist_angular_z.publish(output_float);

     }
     private:
     ros::NodeHandle n;

     ros::Publisher msg_pub_seq;
     ros::Publisher msg_pub_stamp_sec;
     ros::Publisher msg_pub_stamp_nsec;
     ros::Publisher msg_pub_frame_id;
     ros::Publisher msg_pub_child_id;

     ros::Publisher msg_pub_position_x;
     ros::Publisher msg_pub_position_y;
     ros::Publisher msg_pub_position_z;

     ros::Publisher msg_pub_orientation_x;
     ros::Publisher msg_pub_orientation_y;
     ros::Publisher msg_pub_orientation_z;
     ros::Publisher msg_pub_orientation_w;

     ros::Publisher msg_pub_twist_linear_x;
     ros::Publisher msg_pub_twist_linear_y;
     ros::Publisher msg_pub_twist_linear_z;

     ros::Publisher msg_pub_twist_angular_x;
     ros::Publisher msg_pub_twist_angular_y;
     ros::Publisher msg_pub_twist_angular_z;

     ros::Subscriber msg_sub;
};



int main (int argc, char **argv)
{
     ros::init(argc, argv, "msg_transform");
     
     

     transform ros_to_moos;
     
     
     ros::spin();

     return 0;
}
