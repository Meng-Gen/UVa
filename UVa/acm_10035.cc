#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long a;
    long long b;

    while (std::cin >> a >> b && !(a == 0 && b == 0))
    {
        if (b > a)
        {
            long long temp = a;
            a = b; 
            b = temp;
        }
        
        int result[15] = {};
        int pos = 0;
        while (a > 0)
        {
            result[pos] = (a % 10) + (b % 10);
            pos++;
            a /= 10;
            b /= 10;
        }

        int carry_count = 0;
        for (int i = 0; i < 15; i++)
        {
            if (result[i] > 9) 
            {
                carry_count++;
                result[i+1]++;
            }
        }

        if (carry_count == 0)
        {
            printf("No carry operation.\n");
        }
        else if (carry_count == 1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n", carry_count);
        }
    }

    return 0;
}