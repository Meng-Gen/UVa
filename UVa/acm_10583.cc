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
    int case_id = 1;

    int num_student;
    int num_same_religion;
    while (std::cin >> num_student >> num_same_religion)
    {
        if (num_student == 0 && num_same_religion == 0)
        {
            break;
        }

        DisjointSets query(num_student);

        for (int i = 0; i < num_same_religion; i++)
        {
            int student[2];
            std::cin >> student[0] >> student[1];
            query.Union(student[0], student[1]);
        }

        printf("Case %d: %d\n", case_id, query.GetGroupCount());
        case_id++;
    }
    return 0;
}