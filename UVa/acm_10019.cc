#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

int GetBitCount(int a) 
{
    int rv = 0;
    while (a > 0) 
    { 
        if ((a & 1) == 1)
        {
            rv++;
        }
        a >>= 1;
    }
    return rv;
}

int ConvertIntLiteralToReversedHex(int a)
{
    int rv = 0;
    while (a > 0) 
    {
        rv *= 16;
        rv += (a % 10);
        a /= 10;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int i = 0; i < num_testcases; i++)
    {
        int N;
        std::cin >> N;

        int B1 = GetBitCount(N); // X1 = N

        // Hack: GetBitCount(X2) = GetBitCount(Permuting any digits of X2). 
        int X2_reversed = ConvertIntLiteralToReversedHex(N);
        int B2 = GetBitCount(X2_reversed);

        std::cout << B1 << " " << B2 << std::endl;
    }

    return 0;
}