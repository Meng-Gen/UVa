#include <iostream>
#include <string>
#include <stdio.h>

// Ad Hoc on chess games
int main(int argc, char* argv[])
{
	while (1)
	{
		// Queen location = (x[0], y[0]).
		// Target location = (x[1], y[1]).
		int x[2];
		int y[2];
		std::cin >> x[0] >> y[0] >> x[1] >> y[1];

		if (x[0] == 0 && y[0] == 0 && x[1] == 0 && y[1] == 0)
		{
			break;
		}

		int dx = x[0] - x[1];
		int dy = y[0] - y[1];
		if (dx == 0 && dy == 0)
		{
			printf("0\n");
		}
		else if (dx == 0 || dy == 0 || dx == dy || dx == -dy)
		{
			printf("1\n");		
		}
		else
		{
			printf("2\n");
		}		
	}
	return 0;
}