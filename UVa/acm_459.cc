#include <iostream>
#include <map>
#include <string>
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
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id > 0)
        {
            putchar('\n');
        }

        char V;
        std::cin >> V;
        getchar();

        DisjointSets G(V - 'A' + 1);

        std::string buffer;
        while (getline(std::cin, buffer))
        {
            if (buffer.size() == 0)
            {
                break;
            }
            G.Union(buffer[0] - 'A' + 1, buffer[1] - 'A' + 1);
        }

        printf("%d\n", G.GetGroupCount());
    }
    return 0;
}