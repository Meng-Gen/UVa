#include <iostream>
#include <queue>
#include <float.h>
#include <math.h>
#include <stdio.h>

int N; // the number of freckles on Dick's back

struct Node
{
    double x;
    double y;
    bool visited;

    Node() : x(0.0), y(0.0), visited(false) { }

    double distance(const Node& another)
    {
        double dx = x - another.x;
        double dy = y - another.y;
        return sqrt(dx * dx + dy * dy);
    }
};

Node v[101];

double cost[101][101];
bool visited[101];

void InitCost()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0.0;
            }
            else
            {
                cost[i][j] = v[i].distance(v[j]);
                cost[j][i] = cost[i][j];
            }
        }
    }
}

double GetMinCost()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    visited[0] = true;

    int num_edges = 0;
    double min_cost = 0.0;
    while (num_edges < N - 1) 
    {
        double min = DBL_MAX;
        int x = 0; 
        int y = 0;
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < N; j++)
                {
                    if (!visited[j])
                    {
                        if (min > cost[i][j])
                        {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = true;
        min_cost += min;
        num_edges++;
    }

    return min_cost;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }
        std::cin >> N;
        for (int n = 0; n < N; n++)
        {
            std::cin >> v[n].x >> v[n].y;
        }
        InitCost();
        printf("%.2lf\n", GetMinCost());
    }
    return 0;
}