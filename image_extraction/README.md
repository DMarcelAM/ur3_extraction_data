# Extraction Stack

_Extraction stack for the 1st Test Drive_

### Prerequisites 📋

The simulation requires ROS (Robot Operating System) and was mainly developed and tested with these distributions:

* [ROS Melodic Morenia](http://wiki.ros.org/melodic/Installation/) on Ubuntu 18.04 Bionic Beaver
* [ROS Noetic Ninjemys](http://wiki.ros.org/noetic/Installation/) on Ubuntu 20.04 Focal Fossa

### Warning ⚠️

For the Time Clock to work properly, the 
```
roslaunch image_extraction save_video.launch

```
must be executed before
```
roslaunch leo_erc_gazebo leo_marsyard.launch

```


### Launching 🔧

Make sure you source the devel space on each terminal session you want to use the simulation on:

```
source devel/setup.bash
```
To start the extraction,type:

```
roslaunch image_extraction save_video.launch 

```

