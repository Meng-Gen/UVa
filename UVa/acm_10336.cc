#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <stdio.h>

int m;
int n;

struct Node
{
    int x_;
    int y_;

    Node(int x, int y) : x_(x), y_(y) { }
};

bool visited[1000][1000];
char grid[1000][1000];

void visit(int x, int y, char letter)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x_ < 0 || top.x_ >= m || top.y_ < 0 || top.y_ >= n)
        {
            continue;
        }
        if (grid[top.x_][top.y_] != letter)
        {
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;

        for (int dx = -1; dx <= 1; dx += 2)
        {
            Node next(top.x_ + dx, top.y_);
            dfs_stack.push(next);
        }

        for (int dy = -1; dy <= 1; dy += 2)
        {
            Node next(top.x_, top.y_ + dy);
            dfs_stack.push(next);
        }
    }
}

bool compare(const std::pair<char, int>& a, const std::pair<char, int>& b)
{
    if (a.second > b.second)
    {
        return true;
    }
    if (a.second < b.second)
    {
        return false;
    }
    return a.first < b.first;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++)
        {
            std::cin >> grid[i];
        }

        std::map<char, int> rank_map;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char letter = grid[i][j];
                if (!visited[i][j])
                {
                    visit(i, j, letter);
                    rank_map[letter]++;
                }
            }
        }

        // Hack for sorting std::map with customized comparsion function.
        std::vector< std::pair<char, int> > 
            rank(rank_map.begin(), rank_map.end());
        std::sort(rank.begin(), rank.end(), compare);

        printf("World #%d\n", case_id);
        
        std::vector< std::pair<char, int> >::iterator it;
        for (it = rank.begin(); it != rank.end(); it++)
        {
            printf("%c: %d\n", it->first, it->second);
        }
    }

    return 0;
}