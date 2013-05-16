#include <iostream>
#include <stack>
#include <stdio.h>

int m;
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

bool visited[21][21];
char grid[21][21];
char land;

int visit_continent(int x, int y)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    int continent_size = 0;
    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= m)
        {
            continue;
        }
        if (top.y < 0)
        {
            top.y = n-1;
        }
        if (top.y >= n)
        {
            top.y = 0;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        if (grid[top.x][top.y] != land)
        {
            continue;
        }

        continent_size++;
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
    return continent_size;
}

int main(int argc, char* argv[])
{
    while (scanf("%d %d", &m, &n) == 2)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%s", grid[i]);
        }

        int x;
        int y;
        scanf("%d %d", &x, &y);

        // |l| does not always represent the land.  So I got a lot of WA.
        land = grid[x][y];

        // Find the biggest continent except the one in which he resides.
        //                            ^^^^^^
        // I got a lot of WA from here.
        visit_continent(x, y);

        int biggest_continent = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr_continent = visit_continent(i, j);
                if (curr_continent > biggest_continent)
                {
                    biggest_continent = curr_continent;
                }
            }
        }
        printf("%d\n", biggest_continent);
    }

    return 0;
}