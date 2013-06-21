#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

struct Edge
{
    int end_vertex;
    int latency;

    Edge(int init_end_vertex, int init_latency) 
        : end_vertex(init_end_vertex), latency(init_latency) { }
};

struct Vertex 
{
    int id;
    int time;
    bool visited;
    std::vector<Edge> edges;

    bool operator < (const Vertex& v) const 
    {
        return time > v.time;
    }
};

// -----------------------------------------------------------------------------

int n;
Vertex graph[20001];

inline void InitGraph()
{
    for (int i = 0; i < n; i++)
    {
        graph[i].id = i;
        graph[i].time = 0;
        graph[i].visited = false;
        graph[i].edges.clear();
    }
}

struct Compare  
{  
    bool operator()(int a, int b)  
    {  
        return graph[a].time > graph[b].time;  
    }  
};

int Visit(const Vertex& S, const Vertex& T)
{
    std::priority_queue<Vertex> dijkstra_queue;
    dijkstra_queue.push(S);

    while (dijkstra_queue.size() > 0)
    {
        Vertex top = dijkstra_queue.top();
        dijkstra_queue.pop();

        if (top.visited)
        {
            continue;
        }
        top.visited = true;

        if (top.id == T.id)
        {
            return top.time;
        }

        for (std::vector<Edge>::iterator it = top.edges.begin();
            it != top.edges.end(); it++)
        {
            int next = it->end_vertex;
            graph[next].time = top.time + it->latency;
            dijkstra_queue.push(graph[next]);
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int m, S, T;
        std::cin >> n >> m >> S >> T;

        InitGraph();

        for (int edge_id = 0; edge_id < m; edge_id++)
        {
            int vectex[2];
            int latency;
            std::cin >> vectex[0] >> vectex[1] >> latency;
            graph[vectex[0]].edges.push_back(Edge(vectex[1], latency));
            graph[vectex[1]].edges.push_back(Edge(vectex[0], latency));
        }

        int time = Visit(graph[S], graph[T]);
        if (time < 0)
        {
            printf("Case #%d: unreachable\n", case_id);
        }
        else
        {
            printf("Case #%d: %d\n", case_id, time);
        }
    }

    return 0;
}