# Commands

## Create Workspace

Create folder to store source code

```
mkdir -p /catkin_ws/src
```

## Build source

**Clone source**

```
cd /catkin_ws/src
git clone https://gitlab.com/team-kamayuc/rover_navigation/kamayucrover/erc_data_extraction.git
```
# git clone https://github.com/ros-perception/image_common

**Install dependencies from apt**

```
cd /catkin_ws
apt-get update
apt-get install zip
apt-get install time
rosdep update
rosdep install --from-paths src -iy
```

**Build ...**

```
cd /catkin_ws
catkin config --extend /opt/ros/melodic --no-install && catkin build
```



