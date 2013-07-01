#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int W;
    int y1, y2;
    bool is_possible = true;
    int possible_gap;

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {    
        if (case_id)
        {
            putchar('\n');
        }
    
        std::cin >> W;
        is_possible = true;
        for (int column_id = 0; column_id < W; column_id++)
        {
            std::cin >> y1 >> y2;
            if (column_id == 0)
            {
                possible_gap = y1 - y2;
            }
            else
            {
                if (possible_gap != y1 - y2)
                {
                    is_possible = false;
                }
            }
        }
        if (is_possible)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
