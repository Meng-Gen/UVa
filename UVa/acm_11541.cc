#include <iostream>
#include <string>
#include <stdio.h>

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsUpperAlpha(char c) {
    return IsInRange(c, 'A', 'Z');
}

char buffer[201] = {};

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;
    getchar();
    for (int case_id = 1; case_id <= T; case_id++)
    {
        printf("Case %d: ", case_id);
        std::cin.getline(buffer, 201);

        char c0_ = 0;
        int num = -1;
        for (int i = 0; buffer[i] != 0; i++)
        {
            if (IsUpperAlpha(buffer[i]))
            {
                for (int j = 0; j < num; j++)
                {
                    putchar(c0_);
                }
                c0_ = buffer[i];
                num = 0;
            }
            else 
            {
                num *= 10;
                num += (buffer[i] - '0');
            }
        }
        for (int j = 0; j < num; j++)
        {
            putchar(c0_);
        } 

        putchar('\n');
    }

    return 0;
}