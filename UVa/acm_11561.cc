// Graph :: Graph Traversal :: Flood Fill/Finding Connected Components
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int W;
int H;

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

bool visited[51][51];
char grid[51][51];

bool is_possible_trap(int x, int y)
{
    // We don't need to check the boundary because 
    // the border of the map will always contain walls.
    return (grid[x - 1][y] == 'T' || grid[x + 1][y] == 'T' || 
        grid[x][y - 1] == 'T' || grid[x][y + 1] == 'T');
    {
        return true;
    }
}

int visit(int start_x, int start_y)
{
    int gold_count = 0;

    Node node(start_x, start_y);
    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        // We don't need to check the boundary because 
        // the border of the map will always contain walls.
        // Surely, you can check the boundary but it is the same.

        if (grid[top.x][top.y] == '#')
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        if (grid[top.x][top.y] == 'G')
        {
            gold_count++;
        }

        // If we are not dangerous, try to find more golds.
        if (!is_possible_trap(top.x, top.y))
        {
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
    }

    return gold_count;
}

int main(int argc, char* argv[])
{
    while (std::cin >> W >> H)
    {
        // Initialize |visited| because we might reuse it.
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                visited[i][j] = false;
            }
        }

        int player_x = 0;
        int player_y = 0;
        for (int j = 0; j < H; j++)
        {
            std::string grid_jth_row;
            std::cin >> grid_jth_row;
            for (int i = 0; i < W; i++)
            {
                grid[i][j] = grid_jth_row[i];
                if (grid[i][j] == 'P')
                {
                    player_x = i;
                    player_y = j;
                }
            }
        }

        std::cout << visit(player_x, player_y) << std::endl;
    }
    return 0;
}