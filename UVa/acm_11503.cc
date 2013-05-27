#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

struct DisjointSets {
    int Union(const std::string& x, const std::string& y) {
        Init(x);
        Init(y);
        return Link(FindSet(x), FindSet(y));
    }

    int Link(const std::string& x, const std::string& y) {
        if (x.compare(y) == 0) {
            return group_size_[x];
        }
        if (rank_[x] > rank_[y]) {
            parent_[y] = x;
            group_size_[x] += group_size_[y];
            group_size_[y] = 0;
            return group_size_[x];
        } 
        else {
            parent_[x] = y;
            group_size_[y] += group_size_[x];
            group_size_[x] = 0;
            if (rank_[x] == rank_[y]) {
                rank_[y]++;
            }
            return group_size_[y];
        }
        return -1;
    }

    std::string FindSet(const std::string& x) {
        if (x.compare(parent_[x]) != 0) {
            parent_[x] = FindSet(parent_[x]);
        }
        return parent_[x];
    }
    
    void Init(const std::string& x) {
        if (parent_.find(x) == parent_.end()) {
            parent_[x] = x;
            rank_[x] = 0;
            group_size_[x] = 1;
        }
    }

    std::map<std::string, std::string> parent_;
    std::map<std::string, int> rank_;
    std::map<std::string, int> group_size_;
};

// Time: 3.432s
// Slow but AC anyway.
int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++) 
    {
        DisjointSets network;

        int num_pairs;
        std::cin >> num_pairs;
        std::string x;
        std::string y;
        for (int i = 0; i < num_pairs; i++) 
        {
            std::cin >> x >> y;
            printf("%d\n", network.Union(x, y));
        }
    }
    return 0;
}