#include <iostream>
#include <string>
#include <stdio.h>

int GetPeriod(const std::string& query)
{
    int length = query.size();
    for (int period = 1; period <= length/2; period++)
    {
        bool is_possible = true;
        for (int i = 0; i < length - period; i++)
        {
            if (query[i] != query[i + period])
            {
                is_possible = false;
                break;
            }
        }
        if (is_possible && (length % period == 0))
        {
            return period;
        }
    }
    return length;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id > 0)
        {
            putchar('\n');
        }
        std::string buffer;
        std::cin >> buffer;
        std::cout << GetPeriod(buffer) << std::endl;        
    }

    return 0;
}