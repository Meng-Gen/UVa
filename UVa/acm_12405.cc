#include <iostream>
#include <stdio.h>

char field[102];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int num_spots;
        std::cin >> num_spots;

        for (int i = 0; i < num_spots; i++)
        {
            std::cin >> field[i];
        }

        int scarecrow_pos = -2;
        int scarecrow_count = 0;
        for (int i = 0; i < num_spots; i++)
        {
            if (field[i] == '.' && 
                (scarecrow_pos < i-1 || scarecrow_pos > i+1))
            {
                scarecrow_pos = i+1;
                scarecrow_count++;
            }
        }
 
        printf("Case %d: %d\n", case_id, scarecrow_count);
    }
    return 0;
}