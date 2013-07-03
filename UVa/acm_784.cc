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

char maze[101][101];

void Visit(int x, int y)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (maze[top.x][top.y] == 'X' || maze[top.x][top.y] == '#')
        {
            continue;
        }
        maze[top.x][top.y] = '#';

        dfs_stack.push(Node(top.x - 1, top.y));
        dfs_stack.push(Node(top.x + 1, top.y));
        dfs_stack.push(Node(top.x, top.y - 1));
        dfs_stack.push(Node(top.x, top.y + 1));
    }
}

int main(int argc, char* argv[])
{
    int num_mazes;
    std::cin >> num_mazes;
    getchar(); // Eat newline, otherwise you will get WA
    for (int maze_id = 0; maze_id < num_mazes; maze_id++)
    {
        int N = 0;
        while (gets(maze[N]))
        {
            if (maze[N][0] == '_')
            {
                break;
            }
            N++;
        }

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; maze[i][j]; j++)
            {
                if (maze[i][j] == '*')
                {
                    Visit(i, j);
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