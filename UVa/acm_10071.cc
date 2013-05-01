#include <iostream>

int main(int argc, char* argv[])
{
	int v;
	int t;

	while (std::cin >> v >> t) 
	{
		std::cout << v * t * 2 << std::endl;
	}
	return 0;
}
