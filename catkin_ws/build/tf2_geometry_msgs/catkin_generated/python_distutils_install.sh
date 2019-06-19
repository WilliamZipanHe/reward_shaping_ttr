#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/local-scratch/xlv/reward_shaping_ttr/catkin_ws/src/geometry2/tf2_geometry_msgs"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/local-scratch/xlv/reward_shaping_ttr/catkin_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/local-scratch/xlv/reward_shaping_ttr/catkin_ws/install/lib/python3/dist-packages:/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/tf2_geometry_msgs/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/tf2_geometry_msgs" \
    "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python" \
    "/local-scratch/xlv/reward_shaping_ttr/catkin_ws/src/geometry2/tf2_geometry_msgs/setup.py" \
    build --build-base "/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/tf2_geometry_msgs" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/local-scratch/xlv/reward_shaping_ttr/catkin_ws/install" --install-scripts="/local-scratch/xlv/reward_shaping_ttr/catkin_ws/install/bin"
