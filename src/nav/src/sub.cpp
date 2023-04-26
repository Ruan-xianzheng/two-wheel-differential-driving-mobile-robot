#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <iostream>

    void domsg(const geometry_msgs::PoseWithCovarianceStampedConstPtr& msg)
    {
        geometry_msgs::PointStamped msgPointStamped;
        msgPointStamped.point=msg->pose.pose.position;
        msgPointStamped.header.stamp = msg->header.stamp;
        msgPointStamped.header.frame_id = "map";
        //读取坐标信息并输出在终端中
        ROS_INFO("x=%.2f y=%.2f z=%.2f",msgPointStamped.point.x,msgPointStamped.point.y,msgPointStamped.point.z);
    }

int main(int argc, char** argv)
{
    ros::init(argc, argv,"amcl_pose_sub_pub");
     ros::NodeHandle nh;  // 定义ROS句柄
    ros::Subscriber sub= nh.subscribe("/amcl_pose", 1000,domsg);
    ros::spin();
    return 0;
}
