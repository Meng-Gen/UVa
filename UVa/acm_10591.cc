#include <iostream>
#include <stdio.h>

// Go to http://uhunt.felix-halim.net/ to query UVa statistics.
// If a lot of people get TLE, we can create query table.
// For n = 1 to 10^9, DigitSquareSum(n) <= DigitSquareSum(999999999) = 729.
// So the size of query table could be 729.
//
// However, % TLE can be ignored.  I am lazy.

int DigitSquareSum(int n)
{
    int rv = 0;
    while (n > 0)
    {
        int mod = n % 10;
        rv = rv + mod * mod;
        n /= 10;
    }
    return rv;
}

bool IsHappyNumber(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n == 4)
    {
        return false;
    }
    return IsHappyNumber(DigitSquareSum(n));
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int n;
        std::cin >> n;
        if (IsHappyNumber(n))
        {
            printf("Case #%d: %d is a Happy number.\n", case_id, n);
        }
        else
        {
            printf("Case #%d: %d is an Unhappy number.\n", case_id, n);
        }
    }
    return 0;
}
