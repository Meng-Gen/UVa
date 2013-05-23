#include <iostream>
#include <stdio.h>

inline int absolute(int a)
{
    return (a > 0) ? a : -a;
}

// Euclidean Algorithm
int gcd(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % t;
        a = t;
    }
    return a;
}

// Key: n|(a-b) iff a = x (mod n) and b = x (mod n).
int main(int argc, char* argv[])
{
    int first_num;
    while (std::cin >> first_num && first_num)
    {
        int second_num;
        std::cin >> second_num;

        int rv = first_num - second_num;
        int prev_num = second_num;
        int other_num;
        while (std::cin >> other_num && other_num)
        {
            rv = gcd(rv, other_num - prev_num);
            prev_num = other_num;
        }
        std::cout << absolute(rv) << std::endl;
    }
    return 0;
}