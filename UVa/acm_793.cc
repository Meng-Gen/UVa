#include <iostream>
#include <map>
#include <stdio.h>

struct DisjointSets {
    std::map<int, int> parent_;
    std::map<int, int> rank_;
    int size_;

    DisjointSets(int size) : size_(size) { 
        for (int i = 1; i <= size; i++) {
            parent_[i] = i;
            rank_[i] = 0;
        }
    }

    void Union(int x, int y) {
        Link(FindSet(x), FindSet(y));
    }

    void Link(int x, int y) {
        if (rank_[x] > rank_[y]) {
            parent_[y] = x;
        } 
        else {
            parent_[x] = y;
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
};

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

        int size;
        std::cin >> size;
        getchar();

        DisjointSets network(size);

        int successful_count = 0;
        int unsuccessful_count = 0; 
        while (1)
        {
            char command = getchar();
            if (command == 'c') 
            {
                int x;
                int y;
                std::cin >> x >> y;
                getchar();
                network.Union(x, y);
            }
            else if (command == 'q')
            {
                int x;
                int y;
                std::cin >> x >> y;
                getchar();
                if (network.FindSet(x) == network.FindSet(y))
                {
                    successful_count++;
                }
                else
                {
                    unsuccessful_count++;
                }
            }
            else
            {
                break;
            }
        }
        printf("%d,%d\n", successful_count, unsuccessful_count);
    }
    return 0;
}