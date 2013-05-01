#include <iostream>
#include <math.h>
#include <stdio.h>

// r = sqrt[(x1-h)^2+(y1-k)^2] with the center (h,k) where
//
//         |x1^2+y1^2  y1  1|        |x1  x1^2+y1^2  1|
//         |x2^2+y2^2  y2  1|        |x2  x2^2+y2^2  1|
//         |x3^2+y3^2  y3  1|        |x3  x3^2+y3^2  1|
//     h = ------------------,   k = ------------------
//             |x1  y1  1|               |x1  y1  1|
//           2*|x2  y2  1|             2*|x2  y2  1|
//             |x3  y3  1|               |x3  y3  1|
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
	double constant_term;
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
		
		// Print the formula (x-h)^2 + (y-k)^2 = r^2.
		if (h == 0.0)
		{
			printf("x^2");
		}
		else 
		{
			printf("(x %c %.3lf)^2", ((h < 0.0) ? '+' : '-'), ((h < 0.0) ? -h : h));
		}
		printf(" + ");
		if (k == 0.0)
		{
			printf("y^2");
		}
		else 
		{
			printf("(y %c %.3lf)^2", ((k < 0.0) ? '+' : '-'), ((k < 0.0) ? -k : k));
		}
		printf(" = %.3lf^2\n", r);

		printf("x^2 + y^2");
		if (h != 0.0)
		{
			printf(" %c %.3lfx", ((h < 0.0) ? '+' : '-'), ((h < 0.0) ? -h * 2 : h * 2));
		}
		if (k != 0.0)
		{
			printf(" %c %.3lfy", ((k < 0.0) ? '+' : '-'), ((k < 0.0) ? -k * 2 : k * 2));
		}

		constant_term = h * h + k * k - r * r;
		if (constant_term != 0.0)
		{
			printf
				(
					" %c %.3lf", 
					((constant_term < 0.0) ? '-' : '+'), 
					((constant_term < 0.0) ? -constant_term : constant_term)
				);
		}
		// Print a single blank line after each equation pair.
		// I got a lot of WA without fitting this requirement.
		printf(" = 0\n\n");
	}
	return 0;
}
