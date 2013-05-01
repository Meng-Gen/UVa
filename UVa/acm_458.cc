#include <iostream>

char buffer[50000];

int main(int argc, char* argv[])
{
	while(std::cin.getline(buffer, 50000))
	{
		for (int i = 0; buffer[i] != 0; i++)
		{
			// '*' - '1' is the integer -7.
			std::cout << (char)(buffer[i] - 7);
		}
		std::cout << std::endl;
	}
	return 0;
}