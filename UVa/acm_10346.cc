#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long n;
    long long k;
    while (std::cin >> n >> k)
    {
        long long used_cigarette = n;
        while (n >= k)
        {
            used_cigarette += n/k;
            n = n/k + n%k;
        }
        std::cout << used_cigarette << std::endl;
	}

	return 0;
}