#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
	while (1)
	{
		int initial_position;
		int number[3];
		std::cin >> initial_position >> number[0] >> number[1] >> number[2];

		if (initial_position == 0 && number[0] == 0 &&
			number[1] == 0 && number[2] == 0)
		{
			break;
		}

		int diff_calibration;

		// turn the dial clockwise 2 full turns
		int degree = 720;

		// stop at the first number of the combination
		diff_calibration = (initial_position - number[0]) % 40;
		if (diff_calibration < 0)
		{
			diff_calibration += 40;
		}
		degree = degree + diff_calibration * 9;

		// turn the dial counter-clockwise 1 full turn
		degree += 360;

		// continue turning counter-clockwise until the 2nd number is reached
		diff_calibration = (number[1] - number[0]) % 40;
		if (diff_calibration < 0)
		{
			diff_calibration += 40;
		}
		degree = degree + diff_calibration * 9;

		// turn the dial clockwise again until the 3rd number is reached
		diff_calibration = (number[1] - number[2]) % 40;
		if (diff_calibration < 0)
		{
			diff_calibration += 40;
		}
		degree = degree + diff_calibration * 9;

		std::cout << degree << std::endl;
	}

	return 0;
}