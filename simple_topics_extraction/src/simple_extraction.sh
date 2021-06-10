#!/bin/bash
mkdir -p /root/data/camera_info

rosbag record /usb_cam/camera_info --bz2 -l 1 -o /root/data/camera_info/camera_image_raw_camera_info

