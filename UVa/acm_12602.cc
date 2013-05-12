#include <iostream>
#include <stdio.h>

char plate[9];

bool is_nice()
{
    // Format: LLL-DDDD
    int letters = 0;
    for (int i = 0; i < 3; i++)
    {
        letters += (plate[i] - 'A');
        if (i != 2)
        {
            letters *= 26;
        }
    }

    int digits = 0;
    for (int i = 4; i < 8; i++)
    {
        digits += (plate[i] - '0');
        if (i != 7)
        {
            digits *= 10;
        }
    }

    int diff = digits - letters;
    if (diff < 0)
    {
        diff = -diff;
    }
    return (diff <= 100);
}

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        std::cin >> plate; 
        if (is_nice())
        {
            std::cout << "nice" << std::endl;
        }
        else
        {
            std::cout << "not nice" << std::endl;
        }
    }
    return 0;
}