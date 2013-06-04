#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

bool CompareLength(const std::string& a, const std::string& b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    return a > b;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }
        
        std::vector< std::string > fragmentations;
        std::string fragmentation;
        while (getline(std::cin, fragmentation) && fragmentation.size())
        {
            fragmentations.push_back(fragmentation);
        }
        std::sort(fragmentations.begin(), fragmentations.end(), CompareLength);

        int fragmentations_count = fragmentations.size();
        int file_length = fragmentations[0].size() + 
            fragmentations[fragmentations_count - 1].size();

        std::map<std::string, int> file_candidates;
        for (int i = 0; i < fragmentations_count; i++)
        {
            for (int j = fragmentations_count - 1; j > i; j--)
            {
                if (fragmentations[i].size() + fragmentations[j].size() == 
                    file_length)
                {
                    file_candidates[fragmentations[i] + fragmentations[j]]++;
                    file_candidates[fragmentations[j] + fragmentations[i]]++;
                }
            }
        }

        int max_voting_count = 0;
        std::string file;
        for (std::map<std::string, int>::iterator it = file_candidates.begin();
            it != file_candidates.end(); it++)
        {
            if (it->second > max_voting_count)
            {
                file = it->first;
                max_voting_count = it->second;
            }
        }
        
        std::cout << file << std::endl;
    }
    return 0;
}