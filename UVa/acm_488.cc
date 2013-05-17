#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;
    getchar();
    getchar();
    for (int case_id = 1; case_id <= T; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        int amplitude;
        std::cin >> amplitude;
        getchar();
        
        int frequency;
        std::cin >> frequency;
        getchar();

        for (int times = 0; times < frequency; times++)
        {
            if (times > 0)
            {
                putchar('\n');
            }
            for (int i = 1; i <= amplitude; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    putchar(i + '0');
                }
                putchar('\n');
            }
            for (int i = amplitude - 1; i >= 1; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    putchar(i + '0');
                }
                putchar('\n');
            }
        }
    }

    return 0;
}