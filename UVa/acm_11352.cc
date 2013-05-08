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

int M; // number of rows
int N; // number of columns

bool visited[101][101];
char grid[101][101];
bool is_in_threat[101][101];

int horse_threat_dx[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int horse_threat_dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

void init_visited_table()
{
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            visited[m][n] = false;
        }
    }
}

void init_threat_table()
{
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            is_in_threat[m][n] = false;
        }
    }

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            if (grid[m][n] != 'Z')
            {
                continue;
            }
            for (int i = 0; i < 8; i++)
            {
                int x = m + horse_threat_dx[i];
                int y = n + horse_threat_dy[i];
                if (x >= 0 && x < M && y >= 0 && y < N)
                {
                    is_in_threat[x][y] = true;
                }
            }
        }
    }
}

int visit()
{
    int start_x = -1;
    int start_y = -1;
    bool is_found_start = false;
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            if (grid[m][n] == 'A')
            {
                is_found_start = true;
                start_x = m;
                start_y = n;
                break;
            }
        }
        if (is_found_start)
        {
            break;
        }
    }
    Node node(start_x, start_y);
    std::queue<Node> bfs_queue;
    bfs_queue.push(node);

    while (bfs_queue.size() > 0)
    {
        Node top = bfs_queue.front();
        bfs_queue.pop();

        if (top.x < 0 || top.x >= M || top.y < 0 || top.y >= N)
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        // BFS implies that |moves| is minimal.
        if (grid[top.x][top.y] == 'B')
        {
            return top.moves;
        }
        // King can`t move to a square X, if a horse of the enemy is on that 
        // square.
        else if (grid[top.x][top.y] == 'Z')
        {
            continue;
        }

        // Except for the case when square X is either kingdom A or B.
        // We've checked B before but do not check A yet.  So we check here. 
        if (is_in_threat[top.x][top.y] && grid[top.x][top.y] != 'A')
        {
            continue;
        }

        // Enqueue possible moves of King Peter.
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                Node next(top.x + dx, top.y + dy, top.moves + 1);
                bfs_queue.push(next);
            }
        }
    }

    // King Peter has no choice to visit his daughter.
    return -1;
}

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        std::cin >> M >> N;
        for (int m = 0; m < M; m++)
        {
            std::cin >> grid[m];
        }

        init_visited_table();
        
        init_threat_table();
        
        int rv = visit();
        if (rv < 0)
        {
            printf("King Peter, you can't go now!\n");
        }
        else
        {
            printf("Minimal possible length of a trip is %d\n", rv);
        }
    }

    return 0;
}