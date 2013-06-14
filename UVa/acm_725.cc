#include <iostream>
#include <stdio.h>

bool HasRepeatedDigits(int i, int j)
{
    bool visited[10] = {};

    // Check i
    if (i < 10000)
    {
        visited[0] = true;
    }
    while (i)
    {
        int r = i % 10;
        if (visited[r])
        {
            return true;
        }
        visited[r] = true;
        i /= 10;
    }

    // Check j
    if (j < 10000)
    {
        if (visited[0])
        {
            return true;
        }
        visited[0];
    }
    while (j)
    {
        int r = j % 10;
        if (visited[r])
        {
            return true;
        }
        visited[r] = true;
        j /= 10;
    }

    return false;
}

int main(int argc, char* argv[])
{
    bool is_first_testcase = true;
    int n;
    while (std::cin >> n && n)
    {
        if (is_first_testcase)
        {
            is_first_testcase = false;
        }
        else
        {
            putchar('\n');
        }
        bool has_solution = false;
        for (int i = 1234; i <= 98765; i++)
        {
            int j = i * n;
            if (j > 98765 || j < 1234)
            {
                continue;
            }
            if (HasRepeatedDigits(i, j))
            {
                continue;
            }
            has_solution = true;
            printf("%05d / %05d = %d\n", j, i, n);
        }
        if (!has_solution)
        {
            printf("There are no solutions for %d.\n", n);
        }
    }
    
    return 0;
}