#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_operations;
    std::cin >> num_operations;

    long long account = 0;
    for (int i = 0; i < num_operations; i++)
    {
        std::string operation;
        std::cin >> operation;
        if (operation.compare("donate") == 0)
        {
            long long K;
            std::cin >> K;
            account += K;
        }
        else
        {
            std::cout << account << std::endl;
        }
    }

    return 0;
}