#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdio.h>

int n;

struct Node
{
    int x;
    int y;

    Node(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool visited[101][101];
char grid[101][101];

int visit(int x, int y, int id)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    int size = 0;
    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= n || top.y < 0 || top.y >= n)
        {
            continue;
        }
        if (grid[top.x][top.y] != id)
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        size++;
        for (int dx = -1; dx <= 1; dx += 2)
        {
            Node next(top.x + dx, top.y);
            dfs_stack.push(next);
        }
            
        for (int dy = -1; dy <= 1; dy += 2)
        {
            Node next(top.x, top.y + dy);
            dfs_stack.push(next);
        }
    }
    return size;
}

int main(int argc, char* argv[])
{
    std::stringstream buffer (std::stringstream::in | std::stringstream::out);
    while (scanf("%d\n", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
                grid[i][j] = 0;
            }
        }

        // UVa input is really dirty.
        for (int i = 1; i < n; i++)
        {
            buffer.clear();
            std::string line;
            getline(std::cin, line);
            buffer << line;
            int x;
            int y;
            while (buffer >> x)
            {
                buffer >> y;
                grid[x-1][y-1] = i;
            }
        }

        bool is_good = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    if (n != visit(i, j, grid[i][j]))
                    {
                        is_good = false;
                        break;
                    }
                    
                }
            }
            if (!is_good)
            {
                break;
            }
        }

        if (is_good)
        {
            std::cout << "good" << std::endl;
        }
        else
        {
            std::cout << "wrong" << std::endl;
        }
    }

    return 0;
}