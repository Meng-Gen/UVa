#include <iostream>
#include <stdio.h>

// 11111111111111111# returns YES
// 131071 = 2^17 - 1 is a Mersenne prime.
int main(int argc, char* argv[])
{
    char binary_number_char;
    while (std::cin >> binary_number_char)
    {
        long long number = binary_number_char - '0';
        while (std::cin >> binary_number_char)
        {
            if (binary_number_char == '#')
            {
                break;
            }
            number <<= 1;
            number += (binary_number_char - '0');
            number %= 131071;
        }

        if (number == 0)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}