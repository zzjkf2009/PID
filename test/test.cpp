/**@file test.cpp
 *@brief This is the unit test source file
 *@author Zejiang Zeng
 *@Copyright [2017] <Zejiang Zeng> [MIT]
 */
#include <gtest/gtest.h>
#include"PID_controller.h"

PID_controller test_pid;

TEST(PID, test_1) {
  EXPECT_EQ(20, test_pid.Calcu_error(20, 0));
}

TEST(PID, test_2) {
  double error = test_pid.Calcu_error(20, 18);
  EXPECT_EQ(36, test_pid.Pterm(error, 18));
}

TEST(PID, test_3) {
  double e = test_pid.Calcu_error(20, 10);
  EXPECT_EQ(30, test_pid.Iterm(e, 10, 2));
}

TEST(PID, test_4) {
  test_pid.PID_set(20, 10, 5);
  EXPECT_EQ(71, test_pid.pid_control(100, 0));
}
