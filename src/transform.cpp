#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <sstream>

class transform{
     public:
     transform(){
          msg_sub = n.subscribe("robot_pose", 1000,  &transform::msgCallback, this);

          msg_pub_position_x = n.advertise<std_msgs::Float64>("robot_pose/pose/position/x", 1000);
          msg_pub_position_y = n.advertise<std_msgs::Float64>("robot_pose/pose/position/y", 1000);
          msg_pub_position_z = n.advertise<std_msgs::Float64>("robot_pose/pose/position/z", 1000);
          msg_pub_orientation_x = n.advertise<std_msgs::Float64>("robot_pose/pose/orientation/x", 1000);
          msg_pub_orientation_y = n.advertise<std_msgs::Float64>("robot_pose/pose/orientation/y", 1000);
          msg_pub_orientation_z = n.advertise<std_msgs::Float64>("robot_pose/pose/orientation/z", 1000);
          msg_pub_orientation_w = n.advertise<std_msgs::Float64>("robot_pose/pose/orientation/w", 1000);
          msg_pub_seq = n.advertise<std_msgs::Int32>("robot_pose/header/seq", 1000);
          msg_pub_stamp_sec = n.advertise<std_msgs::Int32>("robot_pose/header/stamp/sec", 1000);
          msg_pub_stamp_nsec = n.advertise<std_msgs::Int32>("robot_pose/header/stamp/nsec", 1000);
          msg_pub_frame_id = n.advertise<std_msgs::String>("robot_pose/header/frame_id", 1000);
     }
     void msgCallback(const geometry_msgs::PoseStamped::ConstPtr& input){
          ROS_INFO("%s", "recieve robot_pose\n");
          std_msgs::Float64 output_float;
          std_msgs::String output_string;
          std_msgs::Int32 output_int;

          output_float.data = input->pose.position.x;
          msg_pub_position_x.publish(output_float);

          output_float.data = input->pose.position.y;
          msg_pub_position_y.publish(output_float);

          output_float.data = input->pose.position.z;
          msg_pub_position_z.publish(output_float);

          output_float.data = input->pose.orientation.x;
          msg_pub_orientation_x.publish(output_float);

          output_float.data = input->pose.orientation.y;
          msg_pub_orientation_y.publish(output_float);

          output_float.data = input->pose.orientation.z;
          msg_pub_orientation_z.publish(output_float);

          output_float.data = input->pose.orientation.w;
          msg_pub_orientation_w.publish(output_float);

          output_int.data = input->header.seq;
          msg_pub_seq.publish(output_int);

          output_int.data = input->header.stamp.sec;
          msg_pub_stamp_sec.publish(output_int);

          output_int.data = input->header.stamp.nsec;
          msg_pub_stamp_nsec.publish(output_int);

          output_string.data = input->header.frame_id;
          msg_pub_frame_id.publish(output_string);
     }
     private:
     ros::NodeHandle n;

     ros::Publisher msg_pub_position_x;
     ros::Publisher msg_pub_position_y;
     ros::Publisher msg_pub_position_z;

     ros::Publisher msg_pub_orientation_x;
     ros::Publisher msg_pub_orientation_y;
     ros::Publisher msg_pub_orientation_z;
     ros::Publisher msg_pub_orientation_w;

     ros::Publisher msg_pub_seq;
     ros::Publisher msg_pub_stamp_sec;
     ros::Publisher msg_pub_stamp_nsec;
     ros::Publisher msg_pub_frame_id;

     ros::Subscriber msg_sub;
};



int main (int argc, char **argv)
{
     ros::init(argc, argv, "msg_transform");
     
     

     transform ros_to_moos;
     /*
     msg.header.frame_id = ss.str();
     msg.pose.position.x = 5.0;
     msg.pose.position.y = 6.0;
     msg.pose.position.z = 0.1;
     msg.pose.orientation.x = 0.3;
     msg.pose.orientation.y = 0.4;
     msg.pose.orientation.z = 0.5;
     msg.pose.orientation.w = 0.6;   */
     
     ros::spin();

     return 0;
}
