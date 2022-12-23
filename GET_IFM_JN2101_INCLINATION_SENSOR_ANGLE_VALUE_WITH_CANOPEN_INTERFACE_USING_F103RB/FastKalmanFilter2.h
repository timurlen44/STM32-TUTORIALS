/*
 * Fast Kalman Filter is a non-model based Kalman Filter with one-dimensional input. 
 * It's more likely an implementation of a Low Pass Filter with minimal latency.
 * Created by Phinite Lab - www.phinitelab.com
 * 
 */

#ifndef FastKalmanFilter2_h
#define FastKalmanFilter2_h
#include "main.h"
struct FastKalmanFilter
{


    // system parameters
    double Bparam;
    double Fparam;
    double Qparam;
    double Hparam;
    double Rparam;
    double Kparam;

    // system dynamic parameters
    double XHatPresent;
    double XHatForward;
    double SPresent;
    double SForward;
    double PPresent;
    double PForward;
    double Y;

   
};

void FastKalmanFilter_setup_sensor1(double Qparam, double Rparam, double samplingPeriod, double PNStd, double MNstd, double initialValue);
void FastKalmanFilter_setup_sensor2(double Qparam, double Rparam, double samplingPeriod, double PNStd, double MNstd, double initialValue);
double GetEstimation_sensor1(double measuredData, double FinputValue);
double GetEstimation_sensor2(double measuredData, double FinputValue);
struct FastKalmanFilter sensor1;
struct FastKalmanFilter sensor2;
#endif
