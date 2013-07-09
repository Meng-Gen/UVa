#include <iostream>
#include <map>
#include <stdio.h>

std::map<char, long long> hieroglyphs_map;

inline void InitHieroglyphsMap()
{
    hieroglyphs_map['B'] = 1;
    hieroglyphs_map['U'] = 10;
    hieroglyphs_map['S'] = 100;
    hieroglyphs_map['P'] = 1000;
    hieroglyphs_map['F'] = 10000;
    hieroglyphs_map['T'] = 100000;
    hieroglyphs_map['M'] = 1000000;
}

char hieroglyphs[505] = {};

int main(int argc, char* argv[])
{
    InitHieroglyphsMap();

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> hieroglyphs;

        bool is_ascending = false;
        bool is_descending = false;
        std::map<char, int> hieroglyphs_count;

        hieroglyphs_count[hieroglyphs[0]]++;
        long long rv = hieroglyphs_map[hieroglyphs[0]];
        long long prev_value = rv;

        long long curr_value;
        for (int i = 1; hieroglyphs[i]; i++)
        {
            hieroglyphs_count[hieroglyphs[i]]++;
            curr_value = hieroglyphs_map[hieroglyphs[i]];

            rv += curr_value;
            if (curr_value > prev_value)
            {
                is_ascending = true;
            }
            else if (curr_value < prev_value)
            {
                is_descending = true;
            }
            prev_value = curr_value;
        }
        
        bool is_over_used = false;
        for (std::map<char, int>::iterator it = hieroglyphs_count.begin();
            it != hieroglyphs_count.end(); it++)
        {
            if ((it->second) > 9)
            {
                is_over_used = true;
                break;
            }
        }

        if (is_ascending && is_descending)
        {
            puts("error");
        }
        else if (is_over_used)
        {
            puts("error");
        }
        else
        {
            printf("%lld\n", rv);
        }
    }
    return 0;
}