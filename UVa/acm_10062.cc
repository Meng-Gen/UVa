#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>

char buffer[1001];

bool compare(std::pair<char, int> lhs, std::pair<char, int> rhs)
{       
    if (lhs.second < rhs.second)
    {
        return true;
    }
    if (lhs.second > rhs.second)
    {
        return false;
    }
    if (lhs.first > rhs.first) 
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    while (std::cin.getline(buffer, 1001))
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        std::map<char, int> frequencies;

        for (int i = 0; buffer[i] != 0; i++)
        {
            frequencies[buffer[i]]++;
        }

        std::vector< std::pair<char, int> > rv;
        for (std::map<char, int>::iterator it = frequencies.begin(); 
            it != frequencies.end(); it++)
        {
            rv.push_back(std::make_pair(it->first, it->second));
        }
        std::sort(rv.begin(), rv.end(), compare);

        for (unsigned i = 0; i != rv.size(); i++)
        {
            printf("%d %d\n", rv[i].first, rv[i].second);
        }

        case_id++;
    }

    return 0;
}
