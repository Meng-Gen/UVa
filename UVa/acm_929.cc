#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

struct Node
{
    int x_;
    int y_;
    int costs_;

    Node(int x, int y) : x_(x), y_(y), costs_(0) { }

    Node(int x, int y, int cost) : x_(x), y_(y), costs_(cost) { }
    
    bool operator < (const Node& node) const 
    {
        return costs_ > node.costs_;
    }
};

int N, M;
int maze[1001][1001] = {};
int visited[1001][1001] = {};

int Visit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    std::priority_queue<Node> dijkstra_queue;
    dijkstra_queue.push(Node(0, 0));

    while (dijkstra_queue.size() > 0)
    {
        Node top = dijkstra_queue.top();
        dijkstra_queue.pop();

        if (top.x_ < 0 || top.x_ >= N || top.y_ < 0 || top.y_ >= M)
        {
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;

        int cost = top.costs_ + maze[top.x_][top.y_];
        if (top.x_ == N - 1 && top.y_ == M - 1)
        {
            return cost;
        }
        dijkstra_queue.push(Node(top.x_ - 1, top.y_, cost));
        dijkstra_queue.push(Node(top.x_ + 1, top.y_, cost));
        dijkstra_queue.push(Node(top.x_, top.y_ - 1, cost));
        dijkstra_queue.push(Node(top.x_, top.y_ + 1, cost));
    }

    return -1;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while(num_testcases--)
    {
        std::cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::cin >> maze[i][j];
            }
        }

        printf("%d\n", Visit());
    }

    return 0;
}