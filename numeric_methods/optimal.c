#include "h.h"
#define ALPHA 0.
#define BETA 1.

double u(double* y);
double u(double* y) { return y[3] > 0 ? 2. : -2.; }

void f(double x, double* y, int size, double* res) {
	res[0] = u(y); // y
	res[1] = y[0]; // x
	res[2] = -BETA*pow(y[1], BETA - 1)/(1 + exp(ALPHA*y[0]*y[0])); //px
	res[3] = -1*y[2] + 2*ALPHA*pow(y[1], BETA)*y[0]*exp(ALPHA*y[0]*y[0])/pow(1+exp(ALPHA*y[0]*y[0]), 2); //py
}

double eigen_value(double x, double* y) { return 0; }

void discrepancy(double* y0, double* y, double* v) { 
	v[0] = y[0];
	v[1] = y[1] + y0[1];
	v[2] = y[2] + y0[2];	
}

int main(void) {
	double a, b, y0[4], y[4];
	a = 0.; b = 4.;
	y0[0] = 0;
	shoot(a, b, y0, 4, 1, 0.000001);
	printf("%lf %lf %lf %lf \n", y0[0], y0[1], y0[2], y0[3]);	
	return 0;
}