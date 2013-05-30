#include <iostream>
#include <string>
#include <stdio.h>

int doubled[] = { 0, 2, 5, 7, 10, 12, 15, 17 };
int undoubled[] = { 1, 3, 6, 8, 11, 13, 16, 18 };

// |a| cannot be 3-digit or more-digit.
inline int DigitSum(int a)
{
    return a/10 + a%10;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    while (num_testcases--)
    {
        std::string credit_number;
        getline(std::cin, credit_number);

        int sum = 0;
        for (int i = 0; i < 8; i++)
        {
            sum += DigitSum(2 * (credit_number[doubled[i]] - '0'));
        }
        for (int i = 0; i < 8; i++)
        {
            sum += DigitSum(credit_number[undoubled[i]] - '0');
        }

        if (sum % 10 == 0)
        {
            puts("Valid");
        }
        else
        {
            puts("Invalid");
        }
    }
    return 0;
}
