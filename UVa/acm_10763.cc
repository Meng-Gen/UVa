#include <iostream>
#include <map>
#include <stdio.h>

std::map< std::pair<long long, long long>, int > exchanges;

bool HasWay()
{
    if (exchanges.size() % 2 == 1)
    {
        return false;
    }

    std::pair<long long, long long> student;
    std::map< std::pair<long long, long long>, int >::iterator it;
    for (it = exchanges.begin(); it != exchanges.end(); it++)
    {
        student = it->first;
        if (student.first == student.second)
        {
            return false;
        }
        if (exchanges[std::make_pair(student.second, student.first)] != 
            it->second)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) 
{
    int num_candidates;
    while (std::cin >> num_candidates && num_candidates)
    {
        exchanges.clear();
        long long original_location, target_location; 
        for (int i = 0; i < num_candidates; i++)
        {
            std::cin >> original_location >> target_location; 
            exchanges[std::make_pair(original_location, target_location)]++;
        }
       
        if (HasWay())
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}