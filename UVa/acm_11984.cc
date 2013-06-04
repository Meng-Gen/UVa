#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int C, d;
        std::cin >> C >> d;
        double rv = (double)C + (double)(d * 5)/9.0;
        printf("Case %d: %.2lf\n", case_id, rv);
    }

    return 0;
}