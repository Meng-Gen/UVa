#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>

std::string buffer;
std::string candidate, party;
int n, m;

int main(int argc, char* argv[])
{
    int num_testcases; 
    std::cin >> num_testcases;
    while (getchar() != '\n');
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        std::map< std::string, std::string > associated_party;
        std::map< std::string, int > ballot_stat;

        std::cin >> n;
        while (getchar() != '\n');
        for (int i = 0; i < n; i++)
        {
            getline(std::cin, candidate);
            getline(std::cin, party);
            associated_party[candidate] = party;
        }

        std::cin >> m;
        while (getchar() != '\n');
        for (int i = 0; i < m; i++)
        {
            getline(std::cin, candidate);
            ballot_stat[candidate]++;
        }

        std::vector< std::pair<int, std::string> > sorted;
        for (std::map< std::string, int >::iterator it = ballot_stat.begin();
            it != ballot_stat.end(); it++)
        {
            sorted.push_back(std::make_pair(it->second, it->first));
        }
        sort(sorted.begin(), sorted.end(), 
            std::greater< std::pair<int, std::string> >());
        
        if ((sorted.size() > 1) && (sorted[0].first == sorted[1].first))
        {
            puts("tie");
        }
        else
        {
            printf("%s\n", associated_party[sorted[0].second].c_str());
        }
    }

    return 0;
}