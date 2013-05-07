#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcase;
    std::cin >> num_testcase;

    for (int case_id = 1; case_id <= num_testcase; case_id++)
    {
        // LLONG_MAX = 9223372036854775807 > 10^18.
        // You might use C++ double data type also.  long long is good enough.
        long long n;
        std::cin >> n;
        
        // Take k such that k(k+1)/2 >= n > k(k-1)/2.
        long long num_row = (long long)(0.5 * (sqrt(8.0 * n + 1.0) - 1.0));
        std::cout << num_row << std::endl;
    }

    return 0;
}