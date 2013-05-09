#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

typedef std::pair<int, int> Soldier;

bool compare_on_soldier(Soldier lhs, Soldier rhs)
{	
    if (lhs.second > rhs.second)
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    int case_id = 1;

    int N;
    int B;
    int J;

    while (1)
    {
        std::cin >> N;
        if (N == 0)
        {
            break;
        }

        std::vector< Soldier > soldiers;
        for (int i = 0; i < N; i++)
        {
            std::cin >> B >> J;
            soldiers.push_back(std::make_pair(B, J));
        }
    
        std::sort(soldiers.begin(), soldiers.end(), compare_on_soldier);

        long long accumulated_briefing_time = soldiers[0].first; 
        long long min_completing_time = soldiers[0].first + soldiers[0].second;
        for (unsigned int i = 1; i < soldiers.size(); i++)
        {
            accumulated_briefing_time += soldiers[i].first; 
            long long completing_time = accumulated_briefing_time + soldiers[i].second;
            if (completing_time > min_completing_time)
            {
                min_completing_time = completing_time;
            }
        }

        printf("Case %d: %lld\n", case_id, min_completing_time);
        case_id++;
    }

    return 0;
}