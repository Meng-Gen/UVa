#include <iostream>

int main(int argc, char* argv[])
{
    unsigned int a;
    unsigned int b;
    while (std::cin >> a >> b)
    {
        std::cout << (a^b) << std::endl;
    }
    return 0;
}