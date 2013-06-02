#include <iostream>
#include <stack>
#include <stdio.h>

// ----------------------------------------------------------------------------
// DFS

struct Node
{
    int x_;
    int y_;

    Node(int x, int y) : x_(x), y_(y) { }
};

bool visited[10][10];
char grid[10][10];

void InitVisitTable()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            visited[i][j] = false;
        }
    }
}

int point = 0;
bool is_o_point = false;
bool is_x_point = false;

void Visit(int x, int y)
{
    point = 0;
    is_o_point = false;
    is_x_point = false;

    Node node(x, y);
    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x_ < 0 || top.x_ >= 9 || top.y_ < 0 || top.y_ >= 9)
        {
            continue;
        }
        if (grid[top.x_][top.y_] == 'O')
        {
            is_o_point = true;
            continue;
        }
        if (grid[top.x_][top.y_] == 'X')
        {
            is_x_point = true;
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;
        point++;

        for (int dx = -1; dx <= 1; dx += 2)
        {
            Node next(top.x_ + dx, top.y_);
            dfs_stack.push(next);
        }

        for (int dy = -1; dy <= 1; dy += 2)
        {
            Node next(top.x_, top.y_ + dy);
            dfs_stack.push(next);
        }
    }
}

// ----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        InitVisitTable();

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                std::cin >> grid[i][j];
            }
        }

        int o_point = 0;
        int x_point = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 'O')
                {
                    o_point++;
                }
                else if (grid[i][j] == 'X')
                {
                    x_point++;
                }
                if (!visited[i][j] && grid[i][j] == '.')
                {
                    Visit(i, j);
                    if (is_o_point && !is_x_point)
                    {
                        o_point += point;
                    }
                    else if (is_x_point && !is_o_point)
                    {
                        x_point += point;
                    }
                }
            }
        }
        printf("Black %d White %d\n", x_point, o_point);
    }

    return 0;
}