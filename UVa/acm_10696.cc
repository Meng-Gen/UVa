#include <iostream>

int main(int argc, char* argv[])
{
	long long N;

	while (std::cin >> N) 
	{
		if (N == 0)
		{
			break;
		}
		std::cout << "f91(" << N << ") = " << ((N >= 101) ? N - 10 : 91) << std::endl;
	}
	return 0;
}
