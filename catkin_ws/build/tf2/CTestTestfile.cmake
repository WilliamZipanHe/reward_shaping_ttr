# CMake generated Testfile for 
# Source directory: /local-scratch/xlv/catkin_ws/src/geometry2/tf2
# Build directory: /local-scratch/xlv/catkin_ws/build/tf2
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_tf2_gtest_test_cache_unittest "/local-scratch/xlv/catkin_ws/build/tf2/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_cache_unittest.xml" "--return-code" "/local-scratch/xlv/catkin_ws/devel/.private/tf2/lib/tf2/test_cache_unittest --gtest_output=xml:/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_cache_unittest.xml")
add_test(_ctest_tf2_gtest_test_static_cache_unittest "/local-scratch/xlv/catkin_ws/build/tf2/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_static_cache_unittest.xml" "--return-code" "/local-scratch/xlv/catkin_ws/devel/.private/tf2/lib/tf2/test_static_cache_unittest --gtest_output=xml:/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_static_cache_unittest.xml")
add_test(_ctest_tf2_gtest_test_simple "/local-scratch/xlv/catkin_ws/build/tf2/catkin_generated/env_cached.sh" "/local-scratch/xlv/miniconda3/envs/py35_no_specific/bin/python3.5" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_simple.xml" "--return-code" "/local-scratch/xlv/catkin_ws/devel/.private/tf2/lib/tf2/test_simple --gtest_output=xml:/local-scratch/xlv/catkin_ws/build/tf2/test_results/tf2/gtest-test_simple.xml")
subdirs(gtest)
