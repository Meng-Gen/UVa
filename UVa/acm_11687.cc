#include <iostream>
#include <stdio.h>
#include <string.h>

inline int GetDigitCount(int number)
{
    int count = 0;
    do 
    {
        count++;
        number /= 10;
    } 
    while (number);
    return count;
}

char x0[1000005] = {};

int main(int argc, char* argv[])
{
    while (std::cin >> x0 && strcmp(x0, "END"))
    {
        if (!strcmp(x0, "1")) 
        {
            puts(x0);
            continue;
        }

        int curr_x = strlen(x0);
        int prev_x = 0;
        int pos = 1;
        while (curr_x != prev_x) 
        {
            prev_x = curr_x;
            curr_x = GetDigitCount(curr_x);
            pos++;
        }

        printf("%d\n", pos);
    }
    return 0;
}