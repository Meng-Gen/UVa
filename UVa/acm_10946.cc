#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
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

bool visited[51][51];
char grid[51][51];

int visit(int x, int y, char hole_type)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    int size = 0;
    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= m || top.y < 0 || top.y >= n)
        {
            continue;
        }
        if (grid[top.x][top.y] != hole_type)
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

struct Hole
{
    char type;
    int size;

    Hole()
    {
        this->type = 0;
        this->size = 0;
    }

    Hole(char type, int size)
    {
        this->type = type;
        this->size = size;
    }
};

bool compare_on_hole(const Hole& a, const Hole& b)
{
    if (a.size > b.size)
    {
        return true;
    }
    if (a.size < b.size)
    {
        return false;
    }
    return a.type < b.type;
}

int main(int argc, char* argv[])
{
    int problem_id = 1;
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0 && n == 0)
        {
            break;
        }
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

        std::vector<Hole> holes;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char type = grid[i][j];
                if (type != '.' && !visited[i][j])
                {
                    Hole hole(type, visit(i, j, type));
                    holes.push_back(hole);
                }
            }
        }

        std::sort(holes.begin(), holes.end(), compare_on_hole);

        printf("Problem %d:\n", problem_id);
        for (unsigned int i = 0; i < holes.size(); i++)
        {
            printf("%c %d\n", holes[i].type, holes[i].size);
        }
        problem_id++;
    }

    return 0;
}