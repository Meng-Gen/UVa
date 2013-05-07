// Graph :: Graph Traversal :: Flood Fill/Finding Connected Components
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int N;

int neighbor_dx[6] = { -1, -1,  0, 0, 1, 1 };
int neighbor_dy[6] = { -1,  0, -1, 1, 0, 1 };

struct Node
{
    int x;
    int y;

    Node() 
    { 
        x = 0;
        y = 0;
    }

    Node(int some_x, int some_y)
    {
        x = some_x;
        y = some_y;
    }
};

bool visited[201][201];
char grid[201][201];

int get_min(int a, int b)
{
    if (a > b) 
    {
        return b;
    }
    return a;
}

int get_max(int a, int b)
{
    if (a > b) 
    {
        return a;
    }
    return b;
}

bool visit(int start_x, int start_y, char color)
{
    int interval_x[2] = { start_x, start_x };
    int interval_y[2] = { start_y, start_y };

    Node node(start_x, start_y);
    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= N || top.y < 0 || top.y >= N)
        {
            continue;
        }
        if (grid[top.x][top.y] != color)
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        interval_x[0] = get_min(top.x, interval_x[0]);
        interval_x[1] = get_max(top.x, interval_x[1]);
        interval_y[0] = get_min(top.y, interval_y[0]);
        interval_y[1] = get_max(top.y, interval_y[1]);
       
        for (int i = 0; i < 6; i++)
        {
            Node next(top.x + neighbor_dx[i], top.y + neighbor_dy[i]);
            dfs_stack.push(next);
        }
    }

    // Check the status of the game.
    if (color == 'b' && interval_x[0] == 0 && interval_x[1] == (N-1))
    {
        return true;
    }
    if (color == 'w' && interval_y[0] == 0 && interval_y[1] == (N-1))
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    while (1)
    {
        std::cin >> N;
        if (N == 0)
        {
            break;
        }

        // Initialize |visited| because we might reuse it.
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < N; i++)
        {
            std::string grid_ith_row;
            std::cin >> grid_ith_row;
            for (int j = 0; j < N; j++)
            {
                grid[i][j] = grid_ith_row[j];
            }
        }

        bool is_game_end = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    is_game_end = visit(i, j, grid[i][j]);
                    if (is_game_end)
                    {
                        if (grid[i][j] == 'b')
                        {
                            printf("%d B\n", case_id);
                            break;
                        }
                        else 
                        {
                            printf("%d W\n", case_id);
                            break;
                        }
                    }
                }
            }
            if (is_game_end)
            {
                break;
            }
        }

        case_id++;
    }

    return 0;
}