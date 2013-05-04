#include <iostream>
#include <stdio.h>

struct Point
{
	double x;
	double y;
};

Point T[3];

int main(int argc, char* argv[])
{
	while (1)
	{
		std::cin >> T[0].x >> T[0].y >> T[1].x >> T[1].y >> T[2].x >> T[2].y;

		if (T[0].x == 0 && T[0].y == 0 
			&& T[1].x == 0 && T[1].y == 0 
			&& T[2].x == 0 && T[2].y == 0)
		{
			break;
		}

		double double_triangle_area = 
			-T[1].y * T[2].x + T[0].y * (-T[1].x + T[2].x) + 
			T[0].x * (T[1].y - T[2].y) + T[1].x * T[2].y;

		if (double_triangle_area == 0.0)
		{
			// TODO...
		}

		int tree_count = 0;
		for (int i = 1; i < 100; i++)
		{
			for (int j = 1; j < 100; j++)
			{
				double s = 1.0 / double_triangle_area * 
					(T[0].y * T[2].x - T[0].x * T[2].y + 
					(T[2].y - T[0].y) * (double)(i) + 
					(T[0].x - T[2].x) * (double)(j));
				double t = 1.0 / double_triangle_area * 
					(T[0].x * T[1].y - T[0].y * T[1].x + 
					(T[0].y - T[1].y) * (double)(i) + 
					(T[1].x - T[0].x) * (double)(j));

				if (s >= 0.0 && s <= 1.0 && t >= 0.0 && t <= 1.0 && s+t <= 1.0)
				{
					tree_count++;
				}
			}
		}

		printf("%4d\n", tree_count);
	}
	
	return 0;
}