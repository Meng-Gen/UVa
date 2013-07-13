#include <iostream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long N;
    while (std::cin >> N && N)
    {
        std::vector<int> binary_number;
        int num_ones = 0;
        
        long long d = N;
        int r;
        while (d)
        {
            r = d % 2;
            if (r) 
            {
                num_ones++;
            }
            binary_number.push_back(r);
            d /= 2;
        }

        long long a = 0;
        long long b = 0;
        bool is_even = num_ones % 2 == 1;
        for (int i = binary_number.size() - 1; i >= 0; i--)
        {
            a *= 2;
            b *= 2;
            if (binary_number[i] == 1)
            {
                if (is_even)
                {
                    a += 1;
                }
                else
                {
                    b += 1;
                }
                is_even = !is_even;
            }
        }
        std::cout << a << " " << b << std::endl;
    }
    return 0;
}