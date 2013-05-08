// Graph :: Single-Source Shortest Paths (SSSP) :: On Unweighted Graph: BFS
#include <iostream>
#include <queue>
#include <stdio.h>

struct Node
{
    int x;
    int y;
    int moves;

    Node(int some_x, int some_y)
    {
        x = some_x;
        y = some_y;
        moves = 0;
    }

    Node(int some_x, int some_y, int some_moves)
    {
        x = some_x;
        y = some_y;
        moves = some_moves;
    }
};

bool visited[8][8];

int knight_next_dx[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int knight_next_dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

int visit(int start_x, int start_y, int goal_x, int goal_y)
{
    Node node(start_x, start_y);

    std::queue<Node> bfs_queue;
    bfs_queue.push(node);

    while (bfs_queue.size() > 0)
    {
        Node top = bfs_queue.front();
        bfs_queue.pop();

        if (top.x < 0 || top.x >= 8 || top.y < 0 || top.y >= 8)
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        if (top.x == goal_x && top.y == goal_y)
        {
            return top.moves;
        }

        // Enqueue 8 possible moves of knights.
        for (int i = 0; i < 8; i++)
        {
            Node next
            (
                top.x + knight_next_dx[i], 
                top.y + knight_next_dy[i], 
                top.moves + 1
            );
            bfs_queue.push(next);
        }
    }

    // It should not be here.
    return -1;
}

int main(int argc, char* argv[])
{
    char start_grid[2];
    char goal_grid[2];

    while (std::cin >> start_grid >> goal_grid)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                visited[i][j] = false;
            }
        }

        int start_x = start_grid[0] - 'a';
        int start_y = start_grid[1] - '1';
        int goal_x = goal_grid[0] - 'a';
        int goal_y = goal_grid[1] - '1';

        int moves = visit(start_x, start_y, goal_x, goal_y);
        printf
        (
            "To get from %s to %s takes %d knight moves.\n", 
            start_grid, 
            goal_grid, 
            moves
        );
    }

    return 0;
}