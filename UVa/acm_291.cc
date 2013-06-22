#include <iostream>
#include <stdio.h>

bool graph[6][6] = {};

inline void InitGraph()
{
    graph[1][2] = graph[1][3] = graph[1][5] = true;
    graph[2][1] = graph[2][3] = graph[2][5] = true;
    graph[3][1] = graph[3][2] = graph[3][4] = graph[3][5] = true;
    graph[4][3] = graph[4][5] = true;
    graph[5][1] = graph[5][2] = graph[5][3] = graph[5][4] = true;
}

bool visited[6][6] = {};

inline void InitVisitedEdges()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            visited[i][j] = false;
        }
    }
}

int travel[9] = {};

bool IsGoodPosition(int pos, int vertex)
{
    InitVisitedEdges();
    if (!graph[travel[pos-1]][vertex])
    {
        return false;
    }

    for (int i = 0; i < pos-1; i++)
    {
        if (visited[travel[i]][travel[i+1]] || 
            visited[travel[i+1]][travel[i]])
        {
            return false;
        }
        else
        {
            visited[travel[i]][travel[i+1]] = true;
            visited[travel[i+1]][travel[i]] = true;
        }
    }
    if (visited[travel[pos-1]][vertex] ||
        visited[vertex][travel[pos-1]])
    {
        return false;
    }

    return true;
}

void PrintSolution()
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d", travel[i]);
    }
    putchar('\n');
}

void Visit(int pos) 
{
    for (int i = 1; i <= 5; i++)
    {
        if (IsGoodPosition(pos, i))
        {
            travel[pos] = i;
            if (pos == 8)
            {
                PrintSolution();
            }
            else 
            {
                Visit(pos + 1);
            }
        }
    }
}

int main(int argc, char* argv[]) 
{
    InitGraph();
    travel[0] = 1;
    Visit(1);
    return 0;
}