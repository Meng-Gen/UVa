#include <iostream>
#include <string>
#include <stdio.h>

long long T[55][55] = {};

inline void InitPascalTriangle()
{
    for (int n = 1; n <= 50; n++)
    {
        T[n][0] = 1;
        T[n][n] = 1;
        for (int k = 1; k < n; k++)
        {
            T[n][k] = T[n-1][k-1] + T[n-1][k];
        }
    }
}

std::string buffer;
std::string a, b;
int n;

void ParseBuffer()
{
    int i = 1;
    while (buffer[i] != '+')
    {
        i++;
    }
    a = buffer.substr(1, i - 1);

    int j = i;
    while (buffer[j] != ')')
    {
        j++;
    }
    b = buffer.substr(i + 1, j - i - 1);

    n = 0;
    int k = j + 2;
    while (buffer[k])
    {
        n *= 10;
        n += buffer[k] - '0';
        k++;
    }
}

int main(int argc, char* argv[])
{
    InitPascalTriangle();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> buffer;
        ParseBuffer();

        printf("Case %d: ", case_id);
        if (n > 1)
        {
            printf("%s^%d", a.c_str(), n);
        }
        else
        {
            printf("%s", a.c_str());
        }
        for (int k = 1; k < n; k++)
        {
            printf("+%lld*", T[n][k]);
            if (n-k > 1)
            {
                printf("%s^%d", a.c_str(), n-k);
            }
            else
            {
                printf("%s", a.c_str());
            }
            putchar('*');
            if (k > 1)
            {
                printf("%s^%d", b.c_str(), k);
            }
            else
            {
                printf("%s", b.c_str());
            }
        }
        if (n > 1)
        {
            printf("+%s^%d\n", b.c_str(), n);
        }
        else
        {
            printf("+%s\n", b.c_str());
        }
    }

    return 0;
}