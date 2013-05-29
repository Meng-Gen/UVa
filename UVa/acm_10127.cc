#include <iostream>
#include <vector>
#include <stdio.h>

std::vector<long long> r;

//     111 = 0 (mod 3)
// <=> 100 + 10 + 1 = 0 (mod 3)
// <=> 100 (mod 3) + 10 (mod 3) + 1 (mod 3) = 0 (mod 3)
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int OnesCount(int n)
{
    int r = 1 % n;
    int count = 1;
    while (r)
    {
        r = 10 * r + 1;
        r %= n;
        count++;
    }
    return count;
}

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n)
    {
        printf("%d\n", OnesCount(n));
    }
    return 0;
}