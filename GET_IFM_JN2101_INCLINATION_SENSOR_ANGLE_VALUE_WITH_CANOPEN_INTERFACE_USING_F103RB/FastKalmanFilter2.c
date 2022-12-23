/*
 * FastKalmanFilter2.c
 *
 *  Created on: Dec 22, 2022
 *      Author: yazilim
 */

#include "FastKalmanFilter2.h"

void FastKalmanFilter_setup_sensor1(double Qparam, double Rparam, double samplingPeriod, double PNStd, double MNstd, double initialValue)
{
    sensor1.Fparam = 1;
    sensor1.Hparam = 1;
    sensor1.Y = 0.0;
    sensor1.Bparam = samplingPeriod;
    sensor1.Qparam = Qparam * PNStd * PNStd;
    sensor1.Rparam = Rparam * MNstd * MNstd;
    //double PPresent = MNstd * MNstd;
    // system dynamic parameters
    //sensor1.XHatPresent = initialValue;//sonradan açmayı unutma
    sensor1.SPresent = MNstd * MNstd;
}

void FastKalmanFilter_setup_sensor2(double Qparam, double Rparam, double samplingPeriod, double PNStd, double MNstd, double initialValue)
{
    sensor2.Fparam = 1;
    sensor2.Hparam = 1;
    sensor2.Y = 0.0;
    sensor2.Bparam = samplingPeriod;
    sensor2.Qparam = Qparam * PNStd * PNStd;
    sensor2.Rparam = Rparam * MNstd * MNstd;
    //double PPresent = MNstd * MNstd;
    // system dynamic parameters
    //sensor2.XHatPresent = initialValue;//sonradan açmayı unutma
    sensor2.SPresent = MNstd * MNstd;
}
double GetEstimation_sensor1(double measuredData, double FinputValue)
{
    // state
    sensor1.XHatForward = sensor1.Fparam * sensor1.XHatPresent + sensor1.Bparam * FinputValue;

    // state uncertainty
    sensor1.PForward = sensor1.Fparam * sensor1.PPresent * sensor1.Fparam + sensor1.Qparam;

    // update
    sensor1.Y = measuredData - sensor1.Hparam * sensor1.XHatForward;

    // innovation
    sensor1.SForward = sensor1.Hparam * sensor1.PForward * sensor1.Hparam + sensor1.Rparam;

    // coefficient
    sensor1.Kparam = sensor1.PForward * sensor1.Hparam * 1.0 / sensor1.SForward;
    sensor1.XHatForward = sensor1.XHatForward + sensor1.Kparam * sensor1.Y;
    sensor1.PForward = (1.0 - sensor1.Kparam * sensor1.Hparam) * sensor1.PForward;

    // update previous values
    sensor1.PPresent = sensor1.PForward;
    sensor1.XHatPresent = sensor1.XHatForward;
    sensor1.SPresent = sensor1.SForward;

    return sensor1.XHatForward;
}

double GetEstimation_sensor2(double measuredData, double FinputValue)
{
    // state
    sensor2.XHatForward = sensor2.Fparam * sensor2.XHatPresent + sensor2.Bparam * FinputValue;

    // state uncertainty
    sensor2.PForward = sensor2.Fparam * sensor2.PPresent * sensor2.Fparam + sensor2.Qparam;

    // update
    sensor2.Y = measuredData - sensor2.Hparam * sensor2.XHatForward;

    // innovation
    sensor2.SForward = sensor2.Hparam * sensor2.PForward * sensor2.Hparam + sensor2.Rparam;

    // coefficient
    sensor2.Kparam = sensor2.PForward * sensor2.Hparam * 1.0 / sensor2.SForward;
    sensor2.XHatForward = sensor2.XHatForward + sensor2.Kparam * sensor2.Y;
    sensor2.PForward = (1.0 - sensor2.Kparam * sensor2.Hparam) * sensor2.PForward;

    // update previous values
    sensor2.PPresent = sensor2.PForward;
    sensor2.XHatPresent = sensor2.XHatForward;
    sensor2.SPresent = sensor2.SForward;

    return sensor2.XHatForward;
}
