#include <iostream>
#include <string>
#include <stdio.h>

int GetDigitSum(const std::string& num)
{
    int rv = 0;
    for (unsigned int i = 0; i != num.size(); i++)
    {
        rv += (num[i] - '0');
    }
    return rv;
}

int GetDigitSum(int num)
{
    int rv = 0;
    while (num > 0)
    {
        rv += (num % 10);
        num /= 10;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    std::string line;
    while (1)
    {
        getline(std::cin, line);
        if (line == "0")
        {
            break;
        }

        if (line.size() == 1)
        {
            if (line[0] == '9')
            {
                puts("9 is a multiple of 9 and has 9-degree 1.");
            }
            else
            {
                printf("%c is not a multiple of 9.\n", line[0]);
            }
        }
        else
        {
            int degree = 1;
            int digit_sum = GetDigitSum(line);
            while (digit_sum >= 10)
            {
                digit_sum = GetDigitSum(digit_sum);
                degree++;
            }

            if (digit_sum == 9)
            {
                printf("%s is a multiple of 9 and has 9-degree %d.\n", line.c_str(), degree);
            }
            else
            {
                printf("%s is not a multiple of 9.\n", line.c_str());
            }
        }
    }
    return 0;
}