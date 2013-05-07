#include <iostream>

// Test cases: (1, 1), (300, 300)...
int main(int argc, char* argv[])
{
    int M;
    int N;
    while (std::cin >> M >> N)
    {
        std::cout << M * N - 1 << std::endl;
    }
    return 0;
}