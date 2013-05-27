#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id > 0)
        {
            putchar('\n');
        }

        std::map<std::string, int> species;
        std::string tree;
        int num_trees = 0;
        while (getline(std::cin, tree))
        {
            if (tree.size() == 0)
            {
                break;
            }
            species[tree]++;
            num_trees++;
        }

        for (std::map<std::string, int>::iterator it = species.begin();
            it != species.end(); it++)
        {
            printf("%s %.4lf\n", 
                (*it).first.c_str(), 
                (double)(it->second)/(double)(num_trees) * 100.0);
        }
    }
    return 0;
}