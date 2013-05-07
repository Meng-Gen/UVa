#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcase;
    std::cin >> num_testcase;

    for (int case_id = 1; case_id <= num_testcase; case_id++)
    {
        long long sum;
        long long diff;
        std::cin >> sum >> diff;

        // Football scores are always non-negative ``integers.''
        if ((sum % 2) != (diff % 2))
        {
            std::cout << "impossible" << std::endl;
            continue;
        }

        long long team_score[2] = { (sum + diff)/2, (sum - diff)/2 };

        // Football scores are always ``non-negative'' integers.
        if (team_score[0] < 0 || team_score[1] < 0)
        {
            std::cout << "impossible" << std::endl;
            continue;
        }

        std::cout << team_score[0] << " " << team_score[1] << std::endl;
    }

    return 0;
}