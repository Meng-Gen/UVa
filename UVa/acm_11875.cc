#include <iostream>
#include <stdio.h>

int ages[12] = {};

// Median.
int main(int argc, char* argv[])
{
    int num_testcase;
    std::cin >> num_testcase;

    for (int case_id = 1; case_id <= num_testcase; case_id++)
    {
        int num_member;
        std::cin >> num_member;
        
        // 0-based.
        for (int member_id = 0; member_id < num_member; member_id++)
        {
            std::cin >> ages[member_id];
        }
        
        // If we use 1-based index for each member, take care the median
        // of |ages| is |ages[(num_member+1)/2]|. 
        printf("Case %d: %d\n", case_id, ages[num_member/2]);
    }

    return 0;
}