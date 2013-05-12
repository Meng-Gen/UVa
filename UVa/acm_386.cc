#include <iostream>
#include <stdio.h>

// This problem requires that you write a program to find all sets of numbers.
// I get WA because I only find one solution for each |a|.
int main(int argc, char* argv[])
{
    // Do not loop impossible values.
    for (int a = 6; a <= 200; a++)
    {
        for (int b = 2; b < 200; b++)
        {
            for (int c = b; c < 200; c++)
            {
                for (int d = c; d < 200; d++)
                {
                    // Maybe I can truncate impossible loop here.
                    if (a*a*a == b*b*b + c*c*c + d*d*d)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}