#include <iostream>
#include <stdio.h>

inline int minimum(int a, int b) 
{ 
    return (a < b) ? a : b; 
}

inline int maximum(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int main(int argc, char* argv[]) 
{   
    int M, N;
    while (std::cin >> M >> N && (M || N))
    {
        int min_side = minimum(M, N);
        int max_side = maximum(M, N);

        int largest = 0;
        if (min_side == 0)
        {
            largest = 0;
        }
        else if (min_side == 1)
        {
            largest = M*N;
        }
        //  nn..nn..nn..
        //  nn..nn..nn..
        else if (min_side == 2)
        {
            largest = 4 * (max_side/4);
            int r = max_side % 4;
            if (r == 1)
            {
                largest += 2;
            }
            else if (r == 2 || r == 3)
            {
                largest += 4;
            }
        }
        else 
        {
            largest = (M*N + 1)/2;
        }

        printf("%d knights may be placed on a %d row %d column board.\n", 
            largest, M, N);
    }
    return 0;
}
