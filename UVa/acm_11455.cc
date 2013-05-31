#include <algorithm>
#include <iostream>
#include <stdio.h>

long long side[4] = {};

int main(int argc, char* argv[]) 
{   
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> side[0] >> side[1] >> side[2] >> side[3];
        std::sort(side, side + 4);

        if (side[0] == side[3])
        {
            puts("square");
        }
        else if ((side[0] == side[1]) && (side[2] == side[3]))
        {
            puts("rectangle");
        }
        // Similar to triangles.  
        // After sorting we check whether the longest side is longer or 
        // equal to the sum of the rest three sides.
        else if (side[0] + side[1] + side[2] <= side[3])
        {
            puts("banana");
        }
        else
        {
            puts("quadrangle");
        }
    }
    return 0;
}
