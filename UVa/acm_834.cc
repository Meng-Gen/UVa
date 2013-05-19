#include <iostream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x;
    int y;

    while (std::cin >> x >> y)
    {
        if (x == 0 && y == 0)
        {
            printf("[0]\n");
            continue;
        }

        std::vector<int> b;

        while (y && (x % y))
        {
            if (x < y)
            {
                b.push_back(0);
                int temp = x;
                x = y;
                y = temp;
            }
            b.push_back(x / y);
            int temp = y;
            y = x % y;
            x = temp;
        }
        if (y) 
        {
            b.push_back(x / y);
        }

        unsigned int b_size = b.size();
        if (b_size == 1)
        {
            printf("[%d]\n", b[0]);
        }
        else
        {
            printf("[%d;", b[0]);
            for (unsigned int i = 1; i < b_size - 1; i++)
            {
                printf("%d,", b[i]);
            }
            printf("%d]\n", b[b_size - 1]);
        }
    }

    return 0;
}