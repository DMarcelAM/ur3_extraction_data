#!/bin/bash
mkdir -p /home/lsi04/data/camera_info

rosbag record /camera_image/color/camera_info --bz2 -l 1 -o /home/lsi04/data/camera_info/camera_image_raw_camera_info

