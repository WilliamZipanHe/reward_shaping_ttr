# CMake generated Testfile for 
# Source directory: /local-scratch/xlv/reward_shaping_ttr/catkin_ws/src/xacro
# Build directory: /local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/xacro
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_xacro_nosetests_test "/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/xacro/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/xacro/test_results/xacro/nosetests-test.xml" "--return-code" "/usr/bin/cmake -E make_directory /local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/xacro/test_results/xacro" "/usr/bin/nosetests3 -P --process-timeout=60 --where=/local-scratch/xlv/reward_shaping_ttr/catkin_ws/src/xacro/test --with-xunit --xunit-file=/local-scratch/xlv/reward_shaping_ttr/catkin_ws/build/xacro/test_results/xacro/nosetests-test.xml")
subdirs(gtest)
subdirs(test)
