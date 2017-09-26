/**
 *@file PID_contoller.h
 *@Author Zejiang Zeng
 *@date Sep, 2017
 *@copyright 2017.2-2017.5 by Zejiang Zeng (zzeng@terpmail.umd.edu)
 *@brif A PID controller is build and to compute a new velocity given a target setpoint and actual velocity
 */

#ifndef INCLUDE_PID_CONTROLLER_H_
#define INCLUDE_PID_CONTROLLER_H_
class PID_controller {
 public:
  double setpoint, actual_v;

  void PID_set(double p, double i, double d);

  double Calcu_error(double setpoint, double actual_v);

  double Pterm(double error, double Kp);

  double Iterm(double error, double Ki, double integralSum);

  double Dterm(double error, double prevError, double Kd);

  double pid_control(double setpoint, double actual_v);

 private:
  double error, v_out, prevError, dT = 0.1, integralSum = 0;
  double Kp, Ki, Kd;
};

#endif  // INCLUDE_PID_CONTROLLER_H_
