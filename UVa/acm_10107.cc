#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

int sequence[10001] = {};

int main(int argc, char* argv[])
{
    int num = 0;
    int i = 0;
    while (std::cin >> num)
    {
        sequence[i] = num;
        i++;
        std::sort(sequence, sequence + i);

        int median;
        if (i % 2 == 0)
        {
            median = (sequence[i/2-1] + sequence[i/2])/2;
        }
        else 
        {
            median = sequence[i/2];
        }

        printf("%d\n", median);
    }
    
    return 0;
}