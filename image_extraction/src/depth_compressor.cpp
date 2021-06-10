#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class DepthConverter
{
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	
	std::vector<int> compression_params_;
	std::string dir_path1_ ;
	std::string dir_path2_ ;
	int cnt_;
	int filepath_indicator_;

	ros::WallTime start_, end_;

	int num_files_ = 150;


public:
	DepthConverter()
		: it_(nh_)
	{
		// Subscrive to input video feed and publish output video feed
		image_sub_ = it_.subscribe("/zed2/depth/depth_registered", 1,
								   &DepthConverter::imageCompressor, this);

		// Compression params
		compression_params_.push_back(CV_IMWRITE_PXM_BINARY);
		// dir_path_ = "/catkin_ws/src/erc_data_extraction/image_extraction/data/";

		dir_path1_ = "/root/data/depth1/";
		dir_path2_ = "/root/data/depth2/";
		cnt_ = 0;
		filepath_indicator_ = 1;								
	}

	void imageCompressor(const sensor_msgs::ImageConstPtr &msg)
	{
		int seq = msg->header.seq;
		cv_bridge::CvImageConstPtr cv_ptr;

		try
		{
			start_ = ros::WallTime::now();

			cv_ptr = cv_bridge::toCvShare(msg);			

			ros::Time begin = ros::Time::now();
        	double secs = begin.toSec();
        	std::string secs_str = std::to_string(secs);

			std::string depth_path;

			if (filepath_indicator_==1)
			{
				depth_path = dir_path1_ + "depth_" + secs_str + ".bmp";
			}
			else
			{
				depth_path = dir_path2_ + "depth_" + secs_str + ".bmp";
			}
						
			cv::imwrite(depth_path.c_str(), cv_ptr->image, compression_params_);

			end_ = ros::WallTime::now();

			double execution_time = (end_ - start_).toNSec() * 1e-6;
			ROS_INFO_STREAM("Exectution time (ms): " << execution_time);

			cnt_++;

			
			std::cout << " count: " << cnt_ << "| difference: " << seq - cnt_ << std::endl;

			if(cnt_==num_files_){
				cnt_ = 0;
				filepath_indicator_ = -filepath_indicator_;
				ROS_INFO_STREAM("  ");
				ROS_INFO_STREAM(" CAMBIO DE CARPETA ");
				ROS_INFO_STREAM("  ");
				
			}
		}
		catch (cv_bridge::Exception &e)
		{
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}
	}
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "depth_converter");
	DepthConverter ic;
	ros::spin();
	return 0;
}