#include <iostream>
#include <math.h>
#include <stdio.h>

int get_level(int which_term)
{
	int possible = (int)(sqrt((double)which_term * 2.0));
	for (int j = possible - 1; j <= possible + 2; j++)
	{
		if ((j*(j+1)/2 < which_term) && (which_term <= (j+1)*(j+2)/2))
		{
			return j + 1;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int which_term;
	while (std::cin >> which_term) 
	{
		// 1-based level.
		int level = get_level(which_term);
		
		// 1-based index in |level|.
		int which_term_of_level = level * (level + 1) / 2 - which_term + 1;
		int numerator;
		int denominator;
		if (level % 2 == 0)
		{
			numerator = level + 1 - which_term_of_level;	
		}
		else
		{
			numerator = which_term_of_level;
		}
		denominator = level - numerator + 1;

		printf("TERM %d IS %d/%d\n", which_term, numerator, denominator);
	}
	return 0;
}
