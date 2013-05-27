#include <algorithm>
#include <iostream>
#include <stdio.h>

int stores[22];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        int num_stores;
        std::cin >> num_stores;
        for (int i = 0; i < num_stores; i++)
        {
            std::cin >> stores[i];
        }
        std::sort(stores, stores + num_stores);
        int rv = (stores[num_stores - 1] - stores[0]) * 2;
        printf("%d\n", rv);
    }
    return 0;
}