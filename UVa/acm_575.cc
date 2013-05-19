//   (10120)_{skew} 
// = 1*(2^5 - 1) + 0*(2^4 - 1) + 1*(2^3 - 1) + 2*(2^2 - 1) + 0*(2^1 - 1)
// = (1*2^5 + 0*2^4 + 1*2^3 + 2*2^2 + 0*2^1) - (1 + 0 + 1 + 2 + 0)
// = (101200)_{2}      - (1 + 0 + 1 + 2 + 0).
//   ^^^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^^
//   It is easy to get   The sum of all digits

#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::string skew_binary;
    while (std::cin >> skew_binary)
    {
        if (skew_binary == "0")
        {
            break;
        }

        long long rv = 0;
        long long digit_sum = 0;
        for (int i = 0; i < skew_binary.size(); i++)
        {
            rv += skew_binary[i] - '0';
            rv *= 2;
            digit_sum += skew_binary[i] - '0';
        }
        rv -= digit_sum;

        std::cout << rv << std::endl;
    }
    return 0;
}