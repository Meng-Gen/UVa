#include <algorithm>
#include <iostream>
#include <stdio.h>

int station[2000];

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            std::cin >> station[i];
        }
        std::sort(station, station + n);

        bool is_possible = true;
        for (int i = 0; i < n-1; i++)
        {
            if (station[i+1] - station[i] > 200) 
            {
                is_possible = false;
                break;
            }
        }
        if (1422 - station[n-1] > 100) 
        {
            is_possible = false;
        }
        if (is_possible)
        {
            std::cout << "POSSIBLE" << std::endl;
        }
        else
        {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
    }

    return 0;
}