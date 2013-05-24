#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>

bool composite[2002] = {};

inline void InitCompositeTable()
{
    composite[1] = true;
    for (int i = 2; i < 2002; i++)
    {
        if (!composite[i])
        {
            for (int j = i + i; j < 2002; j += i)
            {
                composite[j] = true;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitCompositeTable();

    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::string buffer;
        std::cin >> buffer;
        
        std::map<char, int> frequency;
        for (std::string::iterator it = buffer.begin(); 
            it != buffer.end(); it++)
        {
            frequency[*it]++;
        }

        // Print solution.
        printf("Case %d: ", case_id);
        bool is_empty = true;
        for (std::map<char, int>::iterator it = frequency.begin();
            it != frequency.end(); it++)
        {
            if (!composite[it->second])
            {
                is_empty = false;
                putchar(it->first);
            }
        }
        if (is_empty)
        {
            puts("empty");
        }
        else
        {
            putchar('\n');
        }
    }
    return 0;
}