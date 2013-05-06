#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    while (1)
    {
        std::string buffer;
        std::cin >> buffer;

        if (buffer.compare("0") == 0)
        {
            break;
        }

        int is_alternative = 0;
        int sum[2] = {};
        for (int i = 0; i < buffer.size(); i++)
        {
            sum[is_alternative] += (buffer[i] - '0');
            is_alternative = 1 - is_alternative;
        }

        int eleven_mod = (sum[0] - sum[1]) % 11;
        if (eleven_mod == 0)
        {
            std::cout << buffer << " is a multiple of 11." << std::endl;
        }
        else
        {
            std::cout << buffer << " is not a multiple of 11." << std::endl;
        }
    }

    return 0;
}