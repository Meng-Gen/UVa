#include <iterator>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
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

// Slow but AC.
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

        DisjointSets circuit(size);

        std::string buffer;
        while (getline(std::cin, buffer)) 
        {
            if (buffer.size() == 0) 
            {
                break;
            }

            std::stringstream buffer_stream(buffer);
            std::istream_iterator<int> it(buffer_stream);
            std::istream_iterator<int> end;
            std::vector<int> pins(it, end);

            // Wiring
            for (unsigned int i = 0; i != pins.size(); i += 2) 
            {
                circuit.Union(pins[i], pins[i+1]);
            }
        }

        printf("%d\n", circuit.GetGroupCount());
    }
    return 0;
}