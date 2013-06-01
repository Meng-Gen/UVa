#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

long long factorial[21] = {};

void InitFactorial()
{
    factorial[1] = 1LL;
    for (int i = 2; i < 21; i++)
    {
        factorial[i] = factorial[i-1] * i;
    }
}

int main(int argc, char* argv[])
{
    InitFactorial();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++) 
    {
        std::string word;
        std::cin >> word;
        std::map<char, int> letter_frequency;
        for (std::string::iterator it = word.begin(); it != word.end(); it++)
        {
            letter_frequency[*it]++;
        }
        
        long long ways = factorial[word.size()];
        for (std::map<char, int>::iterator it = letter_frequency.begin();
            it != letter_frequency.end(); it++)
        {
            ways /= factorial[it->second];
        }
        printf("Data set %d: %lld\n", case_id, ways);
    }

    return 0;
}