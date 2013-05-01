#include <iostream>

int main(int argc, char* argv[])
{
	long long hashmat;
	long long opponent;

	while (std::cin >> hashmat >> opponent) 
	{
		long long diff = (hashmat < opponent) ? opponent - hashmat : hashmat - opponent;
		std::cout << diff << std::endl;
	}
	return 0;
}
