#include <stdio.h>
#include <string.h>

char m[105] = {};
char n[105] = {};
int m_len = 0;
int n_len = 0;
int reduced_m;
int reduced_n;

int query[10][4] =
{
    {0, 0, 0, 0}, {1, 1, 1, 1}, {6, 2, 4, 8}, {1, 3, 9, 7}, {6, 4, 6, 4}, 
    {5, 5, 5, 5}, {6, 6, 6, 6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1, 9, 1, 9}
};

int main(int argc, char* argv[])
{
    while (scanf("%s%s", m, n) == 2)
    {
        m_len = strlen(m);
        n_len = strlen(n);

        if (m_len == 1 && m[0] == '0' && n_len == 1 && n[0] == '0')
        {
            break;
        }
        reduced_m = m[m_len-1] - '0';
        if (n_len == 1)
        {
            reduced_n = n[0] - '0';
        }
        else
        {
            reduced_n = (n[n_len-2] - '0') * 10 + n[n_len-1] - '0';
        }
        printf("%d\n", query[reduced_m][reduced_n % 4]);
    }
    return 0;
}