#include <iostream>
#include <map>
#include <stdio.h>

inline int maximum(int x, int y) {
    return (x > y) ? x : y;
}

struct DisjointSets {
    DisjointSets(int size) : size_(size) { 
        for (int i = 1; i <= size; i++) {
            parent_[i] = i;
            rank_[i] = 0;
            group_size_[i] = 1;
        }
        max_group_size_ = (size > 0) ? 1 : 0;
    }

    int GetMaxGroupSize() const { return max_group_size_; } 

    void Union(int x, int y) {
        Link(FindSet(x), FindSet(y));
    }

    void Link(int x, int y) {
        if (x == y) {
            return;
        }
        if (rank_[x] > rank_[y]) {
            parent_[y] = x;
            group_size_[x] += group_size_[y];
            group_size_[y] = 0;
            max_group_size_ = maximum(max_group_size_, group_size_[x]);
        } 
        else {
            parent_[x] = y;
            group_size_[y] += group_size_[x];
            group_size_[x] = 0;
            max_group_size_ = maximum(max_group_size_, group_size_[y]);
            if (rank_[x] == rank_[y]) {
                rank_[y]++;
            }
        }
    }

    int FindSet(int x) {
        if (x != parent_[x]) {
            parent_[x] = FindSet(parent_[x]);
        }
        return parent_[x];
    }
    
    std::map<int, int> parent_;
    std::map<int, int> rank_;
    std::map<int, int> group_size_;
    int max_group_size_;
    int size_;
};

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++) 
    {
        int num_citizens;
        int num_pairs;
        std::cin >> num_citizens >> num_pairs;
        DisjointSets network(num_citizens);
    
        for (int i = 0; i < num_pairs; i++) 
        {
            int A;
            int B;
            std::cin >> A >> B;
            network.Union(A, B);
        }
        printf("%d\n", network.GetMaxGroupSize());
    }
    return 0;
}