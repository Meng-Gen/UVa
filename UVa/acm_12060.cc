#include <algorithm>
#include <iostream>
#include <stdio.h>

// Euclidean Algorithm
int GetGCD(int a, int b) {
    while (b) {
        int t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int GetDigitLength(int a) {
    int rv = 0;
    while (a > 0) 
    {
        a /= 10;
        rv++;
    }
    return rv;
}

int main(int argc, char* argv[]) 
{
    int n;
    int case_id = 1;
    while (std::cin >> n && n)
    {
        int positive_sum = 0;
        int curr_num;
        for (int i = 0; i < n; i++)
        {
            std::cin >> curr_num;
            positive_sum += curr_num;
        }

        bool is_negative = false;
        if (positive_sum < 0) 
        {
            positive_sum = -positive_sum;
            is_negative = true;
        }

        printf("Case %d:\n", case_id);
        if (positive_sum % n == 0)
        {
            if (is_negative) 
            {
                printf("- ");
            }
            printf("%d\n", positive_sum / n);
        }
        else
        {
            int gcd = GetGCD(positive_sum, n);
            positive_sum /= gcd;
            n /= gcd; // it is also c

            int a = positive_sum / n;
            int b = positive_sum % n;
            int a_length = (a == 0) ? 0 : GetDigitLength(a);
            int b_length = GetDigitLength(b);
            int c_length = GetDigitLength(n); // c is n.

            // give 2 extra space for negative sign
            if (is_negative) 
            {
                a_length += 2;
            }

            // print whitespace before showing b.
            for (int i = 0; i < a_length + c_length - b_length; i++)
            {
                putchar(' ');
            }
            printf("%d\n", b);

            // print a with negative sign if necessary
            if (is_negative)
            {
                if (a > 0)
                {
                    printf("- %d", a);
                }
                else
                {
                    printf("- ");
                }
            }
            else
            {
                if (a > 0)
                {
                    printf("%d", a);
                }
            }

            // after showing a, print horizontal bar
            for (int i = 0; i < c_length; i++)
            {
                putchar('-');
            }
            putchar('\n');

            // print whitespace before showing c.
            for (int i = 0; i < a_length; i++)
            {
                putchar(' ');
            }
            printf("%d\n", n);
        }
        case_id++;
    }
    return 0;
}