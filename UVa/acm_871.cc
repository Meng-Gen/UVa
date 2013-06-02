#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// ----------------------------------------------------------------------------
// DFS

int m;
int n;

struct Node
{
    int x_;
    int y_;

    Node(int x, int y) : x_(x), y_(y) { }
};

bool visited[27][27];
char grid[27][27];

void InitVisitTable()
{
    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            visited[i][j] = false;
        }
    }
}

int VisitBlob(int x, int y)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    int blob_size = 0;
    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x_ < 0 || top.x_ >= m || top.y_ < 0 || top.y_ >= n)
        {
            continue;
        }
        if (grid[top.x_][top.y_] != '1')
        {
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;
        blob_size++;

        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                Node next(top.x_ + dx, top.y_ + dy);
                dfs_stack.push(next);
            }
        }
    }

    return blob_size;
}

// ----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }
        InitVisitTable();
        m = 0;
        n = 0;

        std::string grid_config;
        while (getline(std::cin, grid_config) && grid_config.size())
        {
            n = grid_config.size();
            for (int j = 0; j < n; j++)
            {
                grid[m][j] = grid_config[j];
            }
            m++;
        }

        int max_blob_size = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    max_blob_size = maximum(max_blob_size, VisitBlob(i, j));
                }
            }
        }
        printf("%d\n", max_blob_size);
    }

    return 0;
}