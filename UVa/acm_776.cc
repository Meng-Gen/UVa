#include <iterator>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int digit_count(int positive_integer)
{
    int count = 0;
    while (positive_integer)
    {
        count++;
        positive_integer /= 10;
    }
    return count;
}

std::vector<char> Tokenize(const std::string& buffer) 
{
    std::stringstream tokenizer(buffer);
    std::istream_iterator<char> it(tokenizer);
    std::istream_iterator<char> end;
    return std::vector<char>(it, end);
}

// -----------------------------------------------------------------------------

int M;
int N;

struct Node 
{
    int x;
    int y;

    Node() : x(0), y(0) { }
    Node(int some_x, int some_y) : x(some_x), y(some_y) { }
};

int curr_label = 0;
int visited[201][201];
int alignment[201];
char grid[201][201];

void Visit(int x, int y, char species)
{
    Node node(x, y);

    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x < 0 || top.x >= M || top.y < 0 || top.y >= N)
        {
            continue;
        }
        if (visited[top.x][top.y])
        {
            continue;
        }
        if (grid[top.x][top.y] != species)
        {
            continue;
        }

        visited[top.x][top.y] = curr_label;

        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                Node next(top.x + dx, top.y + dy);
                dfs_stack.push(next);
            }
        }
    }
}

void PrintSolution()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            alignment[i] = maximum(alignment[i], visited[i][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        alignment[i] = digit_count(alignment[i]);
    }

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (i)
            {
                putchar(' ');
            }
            std::stringstream format;
            format << "%" << alignment[i] << "d";
            printf(format.str().c_str(), visited[i][j]);
        }
        putchar('\n');
    }
    puts("%");
}

int main(int argc, char* argv[])
{
    std::vector<char> species;
    std::string buffer;
    int curr_row;
    while (getline(std::cin, buffer) && buffer != "%")
    {
        // Read input
        curr_row = 0;
        species = Tokenize(buffer);
        M = species.size();
        for (int i = 0; i < M; i++)
        {
            grid[i][curr_row] = species[i];
            visited[i][curr_row] = 0;
            alignment[i] = 1;
        }
        while (getline(std::cin, buffer) && buffer != "%")
        {
            curr_row++;
            species = Tokenize(buffer);
            for (int i = 0; i < M; i++)
            {
                grid[i][curr_row] = species[i];
                visited[i][curr_row] = 0;
            }
        }
        N = curr_row + 1;

        curr_label = 1;
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < M; i++)
            {
                if (visited[i][j] == 0)
                {
                    Visit(i, j, grid[i][j]);
                    curr_label++;
                }
            }
        }

        PrintSolution();
    }

    return 0;
}