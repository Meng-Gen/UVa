#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

struct Node 
{
    int x;
    int y;

    Node() : x(0), y(0) { }
    Node(int some_x, int some_y) : x(some_x), y(some_y) { }
};

bool visited[101][101];
char maze[101][101];

void InitVisitedMatrix()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            visited[i][j] = false;
        }
    }
}

void Visit(int x, int y, char marking)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (maze[top.x][top.y] == 'X')
        {
            continue;
        }
        if (visited[top.x][top.y])
        {
            continue;
        }
        maze[top.x][top.y] = marking;
        visited[top.x][top.y] = true;

        dfs_stack.push(Node(top.x - 1, top.y));
        dfs_stack.push(Node(top.x + 1, top.y));
        dfs_stack.push(Node(top.x, top.y - 1));
        dfs_stack.push(Node(top.x, top.y + 1));
    }
}

int main(int argc, char* argv[])
{
    int N;
    while (gets(maze[0]))
    {
        if (maze[0][0] == '_')
        {
            puts(maze[0]);
            continue;
        }
        N = 1;
        while (gets(maze[N]))
        {
            if (maze[N][0] == '_')
            {
                break;
            }
            N++;
        }

        InitVisitedMatrix();
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; maze[i][j]; j++)
            {
                char c = maze[i][j];
                if (!visited[i][j] && c != 'X' && c != ' ' && c != '_')
                {
                    Visit(i, j, maze[i][j]);
                }
            }
        }

        for (int i = 0; i <= N; i++)
        {
            puts(maze[i]);
        }
    }
    return 0;
}