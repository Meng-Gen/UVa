#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

int c[102][102];

int LCS(const std::string& a, const std::string& b)
{
    memset(c, 0, 102 * 102);
    int m = a.size();
    int n = b.size();
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                c[i+1][j+1] = c[i][j] + 1;
            }
            else if (c[i][j+1] >= c[i+1][j])
            {
                c[i+1][j+1] = c[i][j+1];
            }
            else
            {
                c[i+1][j+1] = c[i+1][j];
            }
        }
    }
    return c[m][n];
}

int main(int argc, char* argv[])
{
    std::string a;
    std::string b;
    int case_id = 1;
    while (getline(std::cin, a) && a != "#")
    {
        getline(std::cin, b);
        printf("Case #%d: you can visit at most %d cities.\n", case_id, LCS(a,b));
        case_id++;
    }
    return 0;
}