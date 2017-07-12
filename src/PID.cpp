#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = -1.0*Kp;
	this->Ki = -1.0*Ki;
	this->Kd = -1.0*Kd;

	d_error = 0;
	p_error = 0;
	i_error = 0;
}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	i_error = i_error + cte;

}

double PID::TotalError() {
	return i_error;
}

double PID::Steer() {
	double steer = Kp * p_error + Kd * d_error + Ki * i_error;
	return steer;
}

