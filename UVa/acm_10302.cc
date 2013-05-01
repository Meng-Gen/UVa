#include <iostream>

// S(n) = ( n(n+1)/2 )^2
int main(int argc, char* argv[])
{
	long long x;
	long long temp;
	while (std::cin >> x) 
	{
		temp = x * (x + 1) / 2;
		std::cout << temp * temp << std::endl;
	}
	return 0;
}
