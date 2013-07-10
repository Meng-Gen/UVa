#include <iostream>
#include <string>
#include <stdio.h>

inline int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int main(int argc, char* argv[])
{
    int N;
    while (std::cin >> N && N)
    {
        std::string buffer;
        std::cin >> buffer;

        int min_distance = N;
        int restaurant_pos = -1;
        int drugstore_pos = -1;
        for (int i = 0; i < N; i++)
        {
            if (buffer[i] == 'Z')
            {
                min_distance = 0;
                break;
            }
            else if (buffer[i] == 'R')
            {
                restaurant_pos = i;
                if (drugstore_pos != -1)
                {
                    min_distance = minimum(min_distance, 
                        restaurant_pos - drugstore_pos);
                }
            }
            else if (buffer[i] == 'D')
            {
                drugstore_pos = i;
                if (restaurant_pos != -1)
                {
                    min_distance = minimum(min_distance, 
                        drugstore_pos - restaurant_pos);
                }
            }
        }

        printf("%d\n", min_distance);
    }

    return 0;
}