#include <iostream>
#include <math.h>
#include <stdio.h>

// Or using 2 * acos(0) to avoid floating precision error.
// However, UVa online judge accepted my solution.  Ha.
#define CONSTANT_PI 3.14159265358979323846 

// Area of the polygon = N/2 * r^2 * sin(2PI/N).  
// As N -> infinity, area of the polygon -> area of the circle = 1/2 * PI r^2.
int main(int argc, char* argv[])
{
	// Use |long long| will be WA.  Try |double|.
	double radius;
	double num_edges;
	while (std::cin >> radius >> num_edges) 
	{
		double area = num_edges * radius * radius * 
			sin(2.0 * CONSTANT_PI / num_edges) * 0.5;

		printf("%.3lf\n", area);
	}
	return 0;
}
