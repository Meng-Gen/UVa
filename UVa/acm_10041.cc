// To minimize F(x) = sum_{i} |x - s_i|, we need to get the median of {s_i}.
// You can prove the fact by using mathematical induction.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int streets[501];

int norm(int num)
{
    return (num < 0) ? -num : num;
}

int main(int argc, char* argv[])
{
    int num_testcase;
    std::cin >> num_testcase;

    for (int case_id = 0; case_id < num_testcase; case_id++)
    {
        int num_relative;
        std::cin >> num_relative;

        // 0-based.
        for (int i = 0; i < num_relative; i++)
        {
            std::cin >> streets[i];
        }

        std::sort(streets, streets + num_relative);

        int median = streets[num_relative/2];

        int sum = 0;
        for (int i = 0; i < num_relative; i++)
        {
            sum += norm(median - streets[i]);
        }

        std::cout << sum << std::endl;
    }

    return 0;
}