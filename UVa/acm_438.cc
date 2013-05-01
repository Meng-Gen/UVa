#include <iostream>
#include <math.h>
#include <stdio.h>

#define CONSTANT_PI 3.14159265358979323846

// Source code are copied from UVa 190.
double det
	(
		double a, double b, double c,
		double d, double e, double f,
		double g, double h, double i
	)
{
	return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
}

int main(int argc, char* argv[])
{
	double x[3];
	double y[3];
	double cross;
	double h;
	double k;
	double r;
	while (std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]) 
	{
		// The three points will not be on a straight line.  
		// So |cross| could not be 0.
		cross = det
			(
				x[0], y[0], 1, 
				x[1], y[1], 1, 
				x[2], y[2], 1
			);
		h = det
			(
				x[0] * x[0] + y[0] * y[0], y[0], 1,
				x[1] * x[1] + y[1] * y[1], y[1], 1,
				x[2] * x[2] + y[2] * y[2], y[2], 1
			) / (2.0 * cross);
		k = det
			(
				x[0], x[0] * x[0] + y[0] * y[0], 1,
				x[1], x[1] * x[1] + y[1] * y[1], 1,
				x[2], x[2] * x[2] + y[2] * y[2], 1
			) / (2.0 * cross);
		r = sqrt((x[0] - h) * (x[0] - h) + (y[0] - k) * (y[0] - k));
		printf("%.2lf\n", 2.0 * CONSTANT_PI * r);	
	}
	return 0;
}
