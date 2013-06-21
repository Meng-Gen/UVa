#include <iterator>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>

int m;
int n;

struct Node 
{
    int x;
    int y;

    Node(int init_x, int init_y) : x(init_x), y(init_y) { }

    static Node Build(const std::string& buffer) 
    {
        std::stringstream tokenizer(buffer);
        std::istream_iterator<int> it(tokenizer);
        std::istream_iterator<int> end;
        std::vector<int> tokens(it, end);
        if (tokens.size() == 2)
        {
            // 1-based to 0-based
            return Node(tokens[0] - 1, tokens[1] - 1);
        }
        else 
        {
            return Node(-1, -1);
        }
    }
};

bool visited[101][101];
char grid[101][101];

inline void InitGridMatrix()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            grid[i][j] = 0;
        }
    }
}

inline void InitVisitedMatrix()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            visited[i][j] = false;
        }
    }
}

int Visit(const Node& node)
{
    InitVisitedMatrix();
    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    int size = 0;
    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= n || top.y < 0 || top.y >= m)
        {
            continue;
        }
        if (grid[top.x][top.y] != 'W')
        {
            continue;
        }

        if (visited[top.x][top.y])
        {
            continue;
        }
        visited[top.x][top.y] = true;

        size++;
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++) 
            {
                Node next(top.x + dx, top.y + dy);
                dfs_stack.push(next);
            }
        }
    }
    return size;
}

int main(int argc, char* argv[])
{
    std::string buffer;

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        InitGridMatrix();

        if (case_id)
        {
            putchar('\n');
        }
        
        m = 0;
        n = 0;
        while (getline(std::cin, buffer)) 
        {
            if (buffer.size() && buffer[0] != 'L' && buffer[0] != 'W')
            {
                break;
            }
            m = buffer.size();
            for (int j = 0; j < m; j++)
            {
                grid[n][j] = buffer[j];
            }
            n++;
        }

        do
        {
            Node query = Node::Build(buffer);
            printf("%d\n", Visit(query));
        }
        while (getline(std::cin, buffer) && buffer.size());
    }

    return 0;
}