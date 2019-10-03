# This env bash file is a copy of the one we are using at Sep 16, 2019, which should be error-free.
# Just for safety recovery in the future
#!/bin/sh

export PYTHONPATH=$PYTHONPATH:/opt/ros/kinetic/lib/python2.7/dist-packages
alias killgazebogym='killall -9 rosout roslaunch rosmaster gzserver nodelet robot_state_publisher gzclient'



export MAIN_HOME=/local-scratch/xlv

# project 1
export PROJ_HOME=/local-scratch/xlv/reward_shaping_ttr
export QUADROTOR_WORLD_AIR_SPACE=$PROJ_HOME/worlds/air_space.world
export DUBINS_CAR_WORLD_CIRCUIT_GROUND=$PROJ_HOME/worlds/circuit_ground.world

# project 2
export PROJ_HOME_2=/local-scratch/xlv/quad_stabilization
export QUADROTOR_WORLD_CUBE_SPACE=$PROJ_HOME_2/worlds/cube_space.world

# project 3
export PROJ_HOME_3=/local-scratch/xlv/SL_optCtrl
export QUADROTOR_WORLD_AIR_SPACE_SL_OPTCTRL=$PROJ_HOME_3/worlds/air_space_2.world
export BICYCLE_MODEL_TRACK=$PROJ_HOME_3/worlds/track.world

export ROS_HOSTNAME=localhost
export ROS_MASTER_URI=http://localhost:11311

source /opt/ros/kinetic/setup.bash
source $MAIN_HOME/catkin_ws/devel/setup.bash
# source /local-scratch/xlv/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel/setup.bash

## >>> mujoco path >>>
export LD_LIBRARY_PATH="/home/xlv/.mujoco/mjpro150/bin:$LD_LIBRARY_PATH"
export MUJOCO_KEY_PATH=/home/xlv/.mujoco${MUJOCO_KEY_PATH}
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/nvidia-390:/usr/local/cuda-10.0/lib64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/nvidia-410
## <<< mujoco path <<<

alias pycharm='bash -ic "/local-scratch/xlv/pycharm-2018.3.3/bin/pycharm.sh" %f'
alias python3.5=/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5
alias protoc=/usr/bin/protoc
