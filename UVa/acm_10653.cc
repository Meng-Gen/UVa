#include <iostream>
#include <queue>
#include <stdio.h>

struct Node
{
    int x_;
    int y_;
    int moves_;

    Node() : x_(0), y_(0), moves_(0) { }
    Node(int x, int y) : x_(x), y_(y), moves_(0) { }
    Node(int x, int y, int moves) : x_(x), y_(y), moves_(moves) { }
};

int M; // number of rows
int N; // number of columns

bool bomb[1001][1001];
bool visited[1001][1001];

int Visit(const Node& starting, const Node& destination)
{
    std::queue<Node> bfs_queue;
    bfs_queue.push(starting);

    while (bfs_queue.size() > 0)
    {
        Node top = bfs_queue.front();
        bfs_queue.pop();

        if (top.x_ < 0 || top.x_ >= M || top.y_ < 0 || top.y_ >= N)
        {
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;

        // BFS implies that |moves| is minimal.
        if (top.x_ == destination.x_ && top.y_ == destination.y_)
        {
            return top.moves_;
        }
        else if (bomb[top.x_][top.y_])
        {
            continue;
        }

        for (int dx = -1; dx <= 1; dx += 2)
        {
            Node next(top.x_ + dx, top.y_, top.moves_ + 1);
            bfs_queue.push(next);
        }

        for (int dy = -1; dy <= 1; dy += 2)
        {
            Node next(top.x_, top.y_ + dy, top.moves_ + 1);
            bfs_queue.push(next);
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    while (std::cin >> M >> N)
    {
        if (M == 0 && N == 0) 
        {
            break;
        }

        for (int m = 0; m < M; m++)
        {
            for (int n = 0; n < N; n++)
            {
                bomb[m][n] = false;
                visited[m][n] = false;
            }
        }

        int bomb_rows_count;
        std::cin >> bomb_rows_count;
        for (int i = 0; i < bomb_rows_count; i++)
        {
            int bomb_rows;
            int bomb_count;
            std::cin >> bomb_rows >> bomb_count;
            for (int j = 0; j < bomb_count; j++)
            {
                int bomb_columns;
                std::cin >> bomb_columns;
                bomb[bomb_rows][bomb_columns] = true;
            }
        }

        Node starting;
        Node destination;
        std::cin >> starting.x_ >> starting.y_;
        std::cin >> destination.x_ >> destination.y_;
        std::cout << Visit(starting, destination) << std::endl;
    }

    return 0;
}