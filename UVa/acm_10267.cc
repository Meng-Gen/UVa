#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <stdio.h>

std::string command;
std::vector<std::string> command_args;

char table[252][252] = {};
int M = 0;
int N = 0;

inline void ColorPixelSafely(int x, int y, char color)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
    {
        return;
    }
    table[x][y] = color;
}

void ParseCommandArgs()
{
    if (command.size() < 2)
    {
        return;
    }
    std::stringstream command_stream(command.substr(2));
    std::istream_iterator<std::string> it(command_stream);
    std::istream_iterator<std::string> end;
    command_args = std::vector<std::string>(it, end);
}

int ConvertToInteger(const std::string &config) 
{
    std::stringstream builder(config);
    int rv;
    builder >> rv;
    return rv;
}

void CreateTable()
{
    if (command_args.size() != 2)
    {
        return;
    }
    M = ConvertToInteger(command_args[0]);
    N = ConvertToInteger(command_args[1]);

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            table[i][j] = 'O';
        }
    }
}

void ClearTable()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            table[i][j] = 'O';
        }
    }
}

void ColorPixel()
{
    if (command_args.size() != 3)
    {
        return;
    }
    int X = ConvertToInteger(command_args[0]);
    int Y = ConvertToInteger(command_args[1]);
    char C = command_args[2][0];
    ColorPixelSafely(Y-1, X-1, C);
}

void DrawVerticalSegment()
{
    if (command_args.size() != 4)
    {
        return;
    }
    int X = ConvertToInteger(command_args[0]);
    int Y1 = ConvertToInteger(command_args[1]);
    int Y2 = ConvertToInteger(command_args[2]);
    char C = command_args[3][0];
    
    if (Y1 > Y2)
    {
        int temp = Y1;
        Y1 = Y2;
        Y2 = temp;
    }

    for (int i = Y1; i <= Y2; i++)
    {
        ColorPixelSafely(i-1, X-1, C);
    }
}

void DrawHorizontalSegment()
{
    if (command_args.size() != 4)
    {
        return;
    }
    int X1 = ConvertToInteger(command_args[0]);
    int X2 = ConvertToInteger(command_args[1]);
    int Y = ConvertToInteger(command_args[2]);
    char C = command_args[3][0];

    if (X1 > X2)
    {
        int temp = X1;
        X1 = X2;
        X2 = temp;
    }

    for (int i = X1; i <= X2; i++)
    {
        ColorPixelSafely(Y-1, i-1, C);
    }
}

void DrawFilledRectangle()
{
    if (command_args.size() != 5)
    {
        return;
    }
    int X1 = ConvertToInteger(command_args[0]);
    int Y1 = ConvertToInteger(command_args[1]);
    int X2 = ConvertToInteger(command_args[2]);
    int Y2 = ConvertToInteger(command_args[3]);
    char C = command_args[4][0];

    if (X1 > X2)
    {
        int temp = X1;
        X1 = X2;
        X2 = temp;
    }
    if (Y1 > Y2)
    {
        int temp = Y1;
        Y1 = Y2;
        Y2 = temp;
    }
    for (int i = X1; i <= X2; i++)
    {
        for (int j = Y1; j <= Y2; j++)
        {
            ColorPixelSafely(j-1, i-1, C);
        }
    }
}

// ----------------------------------------------------------------------------
// DFS

bool visited[252][252] = {};

struct Node
{
    int x_;
    int y_;

    Node(int x, int y) : x_(x), y_(y) { }
};

void FillRegion()
{
    if (command_args.size() != 3)
    {
        return;
    }
    int X = ConvertToInteger(command_args[0]);
    int Y = ConvertToInteger(command_args[1]);
    char C = command_args[2][0];

    if (X < 0 || X >= N || Y < 0 || Y >= M)
    {
        return;
    } 
    char old_color = table[Y-1][X-1];

    for (int i = 0; i < 252; i++) 
    {
        for (int j = 0; j < 252; j++)
        {
            visited[i][j] = false;
        }
    }
    Node node(Y-1, X-1);
    std::stack<Node> dfs_stack;
    dfs_stack.push(node);

    while (dfs_stack.size() > 0)
    {
        Node top = dfs_stack.top();
        dfs_stack.pop();

        if (top.x_ < 0 || top.x_ >= N || top.y_ < 0 || top.y_ >= N)
        {
            continue;
        }
        if (table[top.x_][top.y_] != old_color)
        {
            continue;
        }

        if (visited[top.x_][top.y_])
        {
            continue;
        }
        visited[top.x_][top.y_] = true;
        table[top.x_][top.y_] = C;

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

void WriteToFile()
{
    std::cout << command.substr(2) << std::endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            putchar(table[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[]) 
{   
    bool is_terminated = false;
    while (getline(std::cin, command) && !is_terminated && (command.size() != 0))
    {
        char op = command[0];
        ParseCommandArgs();
        switch (op)
        {
        case 'I':
            CreateTable();
            break;
        case 'C':
            ClearTable();
            break;
        case 'L':
            ColorPixel();
            break;
        case 'V':
            DrawVerticalSegment();
            break;
        case 'H':
            DrawHorizontalSegment();
            break;
        case 'K':
            DrawFilledRectangle();
            break;
        case 'F':
            FillRegion();
            break;
        case 'S':
            WriteToFile();
            break;
        case 'X':
            is_terminated = true;
            break;
        default:
            break;
        }
    }
    return 0;
}
