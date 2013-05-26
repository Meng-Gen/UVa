#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int L;
        int W;
        int H;
        std::cin >> L >> W >> H;
        if (L > 20 || W > 20 || H > 20) 
        {
            printf("Case %d: bad\n", case_id);
        }
        else
        {
            printf("Case %d: good\n", case_id);
        }
    }
}