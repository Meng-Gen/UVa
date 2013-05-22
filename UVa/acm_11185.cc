#include <iostream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n && (n >= 0))
    {
        // If you don't process case n = 0, you will get WA.
        if (n == 0)
        {
            putchar('0');
        }
        else
        {
            // Use |std::vector| to simulate digit stack.
            std::vector<char> reversed_ternary; 
            while (n > 0)
            {
                reversed_ternary.push_back((n % 3) + '0');
                n /= 3;
            }
            for (int i = reversed_ternary.size() - 1; i >= 0; i--)
            {
                putchar(reversed_ternary[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
