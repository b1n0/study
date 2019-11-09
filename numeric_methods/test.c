#include "h.h"

void f(double x, double* y, double* res) { x++; res[0] = y[1]; res[1] = -1*y[0]; }
double eigen_value(double x, double* y) { x++; y++; return 0; }
void discrepancy(double* y0, double* y, double* res) { y0++; res[0] = y[1] - 1.; }
void start_value(double* y0) { y0[1] = 1.; }

int main(void) {
	double y0[2], a, b;
	a = 0.; b = 2*PI;
	y0[0] = 0.;
	shoot(a, b, y0, 2, 1, 1.e-5, discrepancy);
	printf("%lf %lf \n", y0[0], y0[1]);
	return 0;
}
