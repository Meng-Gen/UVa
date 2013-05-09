#include <iostream>
#include <stdio.h>

// We compute the final result in the backend.
char* rv_2[3] = 
{ 
    "00", "01", "81" 
};
char* rv_4[5] = 
{ 
    "0000", "0001", "2025", "3025", "9801" 
};
char* rv_6[5] = 
{ 
    "000000", "000001", "088209", "494209", "998001" 
};
char* rv_8[9] = 
{ 
    "00000000", "00000001", "04941729", "07441984", "24502500", 
    "25502500", "52881984", "60481729", "99980001" 
};

int main(int argc, char* argv[])
{
    int num_digits = 0;

    while (std::cin >> num_digits)
    {
        if (num_digits == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                printf("%s\n", rv_2[i]);
            }
        }
        else if (num_digits == 4)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("%s\n", rv_4[i]);
            }
        }
        else if (num_digits == 6)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("%s\n", rv_6[i]);
            }
        }
        else if (num_digits == 8)
        {
            for (int i = 0; i < 9; i++)
            {
                printf("%s\n", rv_8[i]);
            }
        }

        // It is slow but it can help us build the final results.
        // Might get TLE if we use the following live computing code?
        /*
        long long upper_limit = 1;
        for (int i = 0; i < num_digits; i++)
        {
            upper_limit *= 10;
        }

        long long sqrt_upper_limit = 1;
        for (int i = 0; i < num_digits/2; i++)
        {
            sqrt_upper_limit *= 10;
        }

        for (int i = 0; i < upper_limit; i++)
        {
            long long first_split = i / sqrt_upper_limit;
            long long second_split = i % sqrt_upper_limit;
            long long sum_splits = first_split + second_split;
            long long square_sum_splits = sum_splits * sum_splits;
            if (square_sum_splits == i)
            {
                if (num_digits == 2)
                {
                    printf("%02d\n", i);
                }
                else if (num_digits == 4)
                {
                    printf("%04d\n", i);
                }
                else if (num_digits == 6)
                {
                    printf("%06d\n", i);
                }
                else if (num_digits == 8)
                {
                    printf("%08d\n", i);
                }
            }
        }
        */
    }

    return 0;
}