#include <iostream>
#include <stdio.h>

long long sum_digits(long long n)
{
    if (n < 10)
    {
        return n;
    }
    long long sum = 0;
    while (n != 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum_digits(sum);
}

int main(int argc, char* argv[])
{
    while (1)
    {
        long long n;
        std::cin >> n;
        if (n == 0)
        {
            break;
        }
        std::cout << sum_digits(n) << std::endl;
    }
    return 0;
}