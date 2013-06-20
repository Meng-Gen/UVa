#include <iostream>
#include <stdio.h>

#define INFINITY_WEIGHT (999)

inline int minimum(int a, int b) {
    return (a < b) ? a : b;
}

// -----------------------------------------------------------------------------

int N;
int directed_graph[102][102] = {};

inline void InitDirectedGraph()
{
    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
        {
            directed_graph[i][j] = INFINITY_WEIGHT;
        }
    }
}

inline void ReadDirectedGraph()
{
    int edge_begin;
    int edge_end;
    while (std::cin >> edge_begin && edge_begin)
    {
        while (std::cin >> edge_end && edge_end)
        {
            directed_graph[edge_begin][edge_end] = 1;
        }
    }
}

inline void FloydWarshallAlgorithm()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                directed_graph[i][j] = minimum(
                    directed_graph[i][j], 
                    directed_graph[i][k] + directed_graph[k][j]);
            }
        }
    }
}

int inaccessible_vertex[102] = {};

inline void Query()
{
    int num_queries;
    int query_vertex;
    std::cin >> num_queries;
    for (int query_id = 0; query_id < num_queries; query_id++)
    {
        std::cin >> query_vertex;
        
        int curr_pos = 0;
        for (int j = 1; j <= N; j++)
        {
            if (directed_graph[query_vertex][j] == INFINITY_WEIGHT)
            {
                inaccessible_vertex[curr_pos] = j;
                curr_pos++;
            }
        }

        printf("%d", curr_pos);
        for (int i = 0; i < curr_pos; i++)
        {
            printf(" %d", inaccessible_vertex[i]);
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[])
{
    while (std::cin >> N && N)
    {
        InitDirectedGraph();
        ReadDirectedGraph();
        FloydWarshallAlgorithm();
        Query();
    }
    return 0;
}