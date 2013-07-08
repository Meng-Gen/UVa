#include <iostream>
#include <queue>
#include <stdio.h>

int sieve_visited[10000] = {};

inline void InitPrimeTable()
{
    for (int i = 2; i < 10000; i++)
    {
        if (!sieve_visited[i]) 
        {
            for (int j = i + i; j < 10000; j += i)
            {
                sieve_visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

struct Node
{
    int x_;
    int moves_;

    Node(int x) : x_(x), moves_(0) { }
    Node(int x, int moves) : x_(x), moves_(moves) { }
};

int Visit(int starting, int destination)
{
    bool visited[10000] = {};
    std::queue<Node> bfs_queue;
    bfs_queue.push(Node(starting));

    while (bfs_queue.size() > 0)
    {
        Node top = bfs_queue.front();
        bfs_queue.pop();

        if (visited[top.x_])
        {
            continue;
        }
        visited[top.x_] = true;

        // BFS implies that |moves| is minimal.
        if (top.x_ == destination)
        {
            return top.moves_;
        }

        int digit[4] = {};
        int d = top.x_;
        for (int i = 3; i >= 0; i--)
        {
            digit[i] = d % 10;
            d /= 10;
        }
        for (int k = 0; k <= 9; k++)
        {
            for (int i = 0; i < 4; i++)
            {
                int next = 0;
                for (int j = 0; j < 4; j++)
                {
                    next *= 10;
                    next = next + ((j != i) ? digit[j] : k);
                }

                if (next < 1000 || next > 9999)
                {
                    continue;
                }
                if (sieve_visited[next])
                {
                    continue;
                }
                bfs_queue.push(Node(next, top.moves_ + 1));
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();
    
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        int starting, destination;
        std::cin >> starting >> destination;
        int moves = Visit(starting, destination);
        if (moves < 0)
        {
            puts("Impossible");
        }
        else
        {
            printf("%d\n", moves);
        }
    }

    return 0;
}