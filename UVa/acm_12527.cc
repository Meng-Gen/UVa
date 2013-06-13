#include <iostream>
#include <stdio.h>

int num_different_digit[5001] = {};

bool HasRepeatedDigits(int number)
{
    bool visited[10] = {};
    int d = number;
    while (d)
    {
        int r = d % 10;

        if (visited[r])
        {
            return true;
        }
        else
        {
            visited[r] = true;
        }

        d /= 10;
    }
    return false;
}

void InitNumDifferentDigit()
{
    for (int n = 1; n < 5001; n++)
    {
        num_different_digit[n] = num_different_digit[n-1];
        if (!HasRepeatedDigits(n))
        {
            num_different_digit[n]++;
        }
    }
}

int main(int argc, char* argv[])
{
    InitNumDifferentDigit();

    int N, M;
    while (std::cin >> N >> M)
    {
        std::cout << num_different_digit[M] - num_different_digit[N-1] 
            << std::endl;
    }
    
    return 0;
}