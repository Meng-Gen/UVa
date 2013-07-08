#include <iostream>
#include <string>
#include <stdio.h>

std::string number;
int set_size, set_element;

bool IsDivisibleBy(int n)
{
    int r = 0;
    for (int i = 0; i < number.size(); i++)
    {
        r *= 10;
        r += number[i] - '0';
        r %= n;
    }

    return r == 0;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> number;
        
        std::cin >> set_size;
        bool is_wonderful = true;
        for (int i = 0; i < set_size; i++)
        {
            std::cin >> set_element;
            if (is_wonderful && !IsDivisibleBy(set_element))
            {
                is_wonderful = false;
            }
        }
        
        if (is_wonderful)
        {
            printf("%s - Wonderful.\n", number.c_str());
        }
        else
        {
            printf("%s - Simple.\n", number.c_str());
        }
    }
    return 0;
}