#include <iostream>
#include <string>
#include <stdio.h>

int GetPeriodByKMP(const std::string& query)
{
    int length = query.size();

    int P[100] = {};
	P[0] = -1;
    int j = -1;
    for (int i = 1; i < length; i++)
    {
		while(j >= 0 && query[j+1] != query[i])
        {
			j = P[j];
        }
        if (query[j+1] == query[i])
        {
			j++;
        }
		P[i] = j; 
	}

    int period = length - j - 1;
    if (length % period == 0)
    {
        return period;
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
        std::cout << GetPeriodByKMP(buffer) << std::endl; 
    }

    return 0;
}