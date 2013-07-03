#include <iostream>
#include <stdio.h>

inline int minimum(int a, int b) {
    return (a < b) ? a : b;
}

// -----------------------------------------------------------------------------

int stick_length;
int num_places;
int coord[55] = {};

bool visited[55][55] = {};
int memoization_cut[55][55] = {};

int Cut(int left, int right)
{
    if (!visited[left][right])
    {
        int cost = 1 << 30;
        for (int i = left + 1; i < right; i++)
        {
            cost = minimum(cost, 
                Cut(left, i) + Cut(i, right) + (coord[right] - coord[left]));
        }
        memoization_cut[left][right] = cost;
        visited[left][right] = true;
    }
    return memoization_cut[left][right];
}

int main(int argc, char* argv[])
{    
    while (std::cin >> stick_length && stick_length)
    {
        coord[0] = 0;
        std::cin >> num_places;
        for (int i = 1; i <= num_places; i++)
        {
            std::cin >> coord[i];
        }
        coord[num_places+1] = stick_length;

        for (int i = 0; i <= num_places+1; i++)
        {
            for (int j = i+1; j <= num_places+1; j++)
            {
                visited[i][j] = (i+1 == j) ? true : false;
                memoization_cut[i][j] = 0;
            }
        }

        printf("The minimum cutting is %d.\n", Cut(0, num_places+1));
    }
    return 0;
}