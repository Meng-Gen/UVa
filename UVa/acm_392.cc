#include <iostream>
#include <stdio.h>

int C[9];

int get_abs(int x)
{
    return (x < 0) ? -x : x;
}

int main(int argc, char* argv[])
{
    while (std::cin >> C[0] >> C[1] >> C[2] >> C[3] >> C[4] >> C[5] >> C[6] >> C[7] >> C[8])
    {
        bool has_found_leading = false;
        for (int i = 0; i < 9; i++)
        {
            if (C[i] != 0)
            {
                int abs = get_abs(C[i]);
                if (!has_found_leading)
                {
                    has_found_leading = true;
                    if (C[i] < 0)
                    {
                        printf("-");
                    }
                }
                else
                {
                    if (C[i] < 0)
                    {
                        printf(" - ");
                    }
                    else 
                    {
                        printf(" + ");
                    }
                }

                if (i < 7)
                {
                    if (abs != 1)
                    {
                        printf("%dx^%d", abs, 8 - i);
                    }
                    else
                    {
                        printf("x^%d", 8 - i);
                    }
                }
                else if (i == 7) 
                {
                    if (abs != 1)
                    {
                        printf("%dx", abs);
                    }
                    else
                    {
                        printf("x");
                    }
                }
                else if (i == 8)
                {
                    printf("%d", abs);
                }
            }
        }

        if (!has_found_leading)
        {
            printf("0\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}