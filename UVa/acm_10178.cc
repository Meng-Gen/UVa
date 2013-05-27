#include <iostream>
#include <map>
#include <stdio.h>

struct DisjointSets {
    DisjointSets(int size) : size_(size), group_count_(size) { 
        for (int i = 1; i <= size; i++) {
            parent_[i] = i;
            rank_[i] = 0;
        }
    }

    int GetGroupCount() const { return group_count_; }

    void Union(int x, int y) {
        Link(FindSet(x), FindSet(y));
    }

    void Link(int x, int y) {
        if (x == y) {
            return;
        }
        if (rank_[x] > rank_[y]) {
            parent_[y] = x;
        } 
        else {
            parent_[x] = y;
            if (rank_[x] == rank_[y]) {
                rank_[y]++;
            }
        }
        group_count_--;
    }

    int FindSet(int x) {
        if (x != parent_[x]) {
            parent_[x] = FindSet(parent_[x]);
        }
        return parent_[x];
    }
    
    std::map<int, int> parent_;
    std::map<int, int> rank_;
    int size_;
    int group_count_;
};

int main(int argc, char* argv[]) 
{
    int V;
    int E;
    while (std::cin >> V >> E) 
    {
        DisjointSets G(V);
        std::map<char, int> vertex_map;
        int vertex_id = 1;
        for (int edge_id = 0; edge_id < E; edge_id++)
        {
            char vertex[2];
            std::cin >> vertex[0] >> vertex[1];
            for (int i = 0; i < 2; i++)
            {
                if (vertex_map.find(vertex[i]) == vertex_map.end())
                {
                    vertex_map[vertex[i]] = vertex_id;
                    vertex_id++;
                }
            }
            G.Union(vertex_map[vertex[0]], vertex_map[vertex[1]]);
        }

        // V - E + F = C + 1
        // Reference: http://en.wikipedia.org/wiki/Euler_characteristic
        int euler_characteristic = G.GetGroupCount() + 1; 
        int face_count = euler_characteristic - V + E;
        printf("%d\n", face_count);
    }
    return 0;
}