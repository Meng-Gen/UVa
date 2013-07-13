#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n, m;
    int curr;
    int k, v, pos;
    while (std::cin >> n >> m)
    {
        std::map< int, std::vector<int> > pos_map;
        std::map< int, int > frequency;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> curr;
            pos_map[curr].push_back(i);
            frequency[curr]++;
        }

        for (int i = 1; i <= m; i++) 
        {
            std::cin >> k >> v;
            pos = (k > frequency[v]) ? 0 : pos_map[v][k-1];
            printf("%d\n", pos);
        }
    }
    return 0;
}