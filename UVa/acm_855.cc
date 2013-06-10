#include <algorithm>
#include <iostream>
#include <stdio.h>

int pos_street[50002];
int pos_avenue[50002];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        int num_streets;
        int num_avenues;
        int num_friends;
        std::cin >> num_streets >> num_avenues >> num_friends;
         
        for (int i = 0; i < num_friends; i++)
        {
            std::cin >> pos_street[i] >> pos_avenue[i];
        }

        // Find the median
        std::sort(pos_street, pos_street + num_friends);
        std::sort(pos_avenue, pos_avenue + num_friends);

        if (num_friends % 2 == 0)
        {
            printf("(Street: %d, Avenue: %d)\n", 
                pos_street[num_friends/2 - 1], 
                pos_avenue[num_friends/2 - 1]);
        }
        else
        {
            printf("(Street: %d, Avenue: %d)\n", 
                pos_street[num_friends/2],
                pos_avenue[num_friends/2]);
        }
    }
    return 0;
}