# CMake generated Testfile for 
# Source directory: /local-scratch/xlv/catkin_ws/src/geometry2/tf2_kdl
# Build directory: /local-scratch/xlv/catkin_ws/build/tf2_kdl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_tf2_kdl_rostest_test_test.launch "/local-scratch/xlv/catkin_ws/build/tf2_kdl/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/catkin_ws/build/tf2_kdl/test_results/tf2_kdl/rostest-test_test.xml" "--return-code" "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/local-scratch/xlv/catkin_ws/src/geometry2/tf2_kdl --package=tf2_kdl --results-filename test_test.xml --results-base-dir \"/local-scratch/xlv/catkin_ws/build/tf2_kdl/test_results\" /local-scratch/xlv/catkin_ws/src/geometry2/tf2_kdl/test/test.launch ")
add_test(_ctest_tf2_kdl_rostest_test_test_python.launch "/local-scratch/xlv/catkin_ws/build/tf2_kdl/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/catkin_ws/build/tf2_kdl/test_results/tf2_kdl/rostest-test_test_python.xml" "--return-code" "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/local-scratch/xlv/catkin_ws/src/geometry2/tf2_kdl --package=tf2_kdl --results-filename test_test_python.xml --results-base-dir \"/local-scratch/xlv/catkin_ws/build/tf2_kdl/test_results\" /local-scratch/xlv/catkin_ws/src/geometry2/tf2_kdl/test/test_python.launch ")
subdirs(gtest)
