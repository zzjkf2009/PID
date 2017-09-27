/*
 *@file PID_controller.cpp
 *@Author Zejiang Zeng
 *@Copyright 2017-2018 by Zejiang Zeng (zzeng@terpmail.umd.edu)
 *@brief see PID_controller.h
 */

#include"PID_controller.h"
#include<cmath>

/*
 *@brief The function that initiate the the p,i,d parameters
 *@param Three doubles to set kp,ki,kd
 *@return None
 */
void PID_controller::PID_set(double p, double i, double d) {
  Kp = p;
  Ki = i;
  Kd = d;
}

double PID_controller::Calcu_error(double setpoint, double actual_v) {
  double result = setpoint - actual_v;
  return result;              // Implement error equation
}

/**
 *@brief Get Proportional term from error and Kp
 *@param The calculated error and Kp variable
 *@return [double] The proportional term P
 */
double PID_controller::Pterm(double error, double Kp) {
  double result = error*Kp;
  return result;              // Implement proportional gain equation here
}

/**
 *@brief Get Integral term from error, Ki, dT, and previous integral term. Integral Sum represents integral so far, 0 here. So term I will use the current error with dT, and Ki
 *@param the calculated error, Ki variable, change in time dT, and current integral Sum
 *@return The integral term I
 */
double PID_controller::Iterm(double error, double Ki, double integralSum) {
  double result = (integralSum + error * dT)*Ki;
  return result;             // Implement integral gain equation here
}

/**
 *@brief Get Derivative term as slope using points current error and previous error
 *@param calculated error, previous Error, Kd, dT
 *@return The derivative term D
 */
double PID_controller::Dterm(double error, double prevError, double Kd) {
  double result = (error - prevError)*Kd;
  return result;           // Implement derivetive gain equation here
}

/**
 *@brif A function to implment the PID control method when a setpoint and actual velocity are given
 *@param [double] setpoint (desired speed), [double] pv (current speed)
 *@return The controlled speed is returned in double
 */

double PID_controller::pid_control(double setpoint, double actual_v) {
  error = Calcu_error(setpoint, actual_v);
  double P = Pterm(error, Kp);
  double I = Iterm(error, Ki, integralSum);
  double D = Dterm(error, prevError, Kd);
  prevError = error;
  v_out = P + I + D;
  return v_out/100;
}



