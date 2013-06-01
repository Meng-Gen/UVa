#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();

    std::string team_output;
    std::string judge_output;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        getline(std::cin, team_output);
        getline(std::cin, judge_output);

        if (team_output.compare(judge_output) == 0)
        {
            printf("Case %d: Yes\n", case_id);
            continue;
        }
        
        std::string::iterator end_pos; 
        
        end_pos = std::remove(team_output.begin(), team_output.end(), ' ');
        team_output.erase(end_pos, team_output.end());

        end_pos = std::remove(judge_output.begin(), judge_output.end(), ' ');
        judge_output.erase(end_pos, judge_output.end());
        
        if (team_output.compare(judge_output) == 0)
        {
            printf("Case %d: Output Format Error\n", case_id);
        }
        else
        {
            printf("Case %d: Wrong Answer\n", case_id);
        }
    }

    return 0;
}