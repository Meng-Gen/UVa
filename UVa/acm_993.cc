#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        long long n;
        std::cin >> n;

        // Find the minimal natural.  
        // Hmmm, I think 0 is also a natural number.
        if (n == 0)
        {
            puts("10");
            continue;
        }
        else if (n == 1) 
        {
            puts("1");    
            continue;
        }

        std::map<int, int> digits;
        for (int i = 9; i > 1; i--) 
        {
            while (n % i == 0)
            {
                digits[i]++;
                n /= i;
            }
        }
        if (n > 1) 
        {
            puts("-1");
        }
        else 
        {
            for (std::map<int, int>::iterator it = digits.begin();
                it != digits.end(); it++)
            {
                for (int i = 0; i < it->second; i++)
                {
                    putchar(it->first + '0');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}