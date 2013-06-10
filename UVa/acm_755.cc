#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

std::map<char, char> keypad;

void InitKeypadMap()
{
    std::string source("0123456789ABCDEFGHIJKLMNOPRSTUVWXY");
    std::string destination("0123456789222333444555666777888999");
    for (int i = 0; i < source.size(); i++)
    {
        keypad[source[i]] = destination[i];
    }
}

std::string Normalize(const std::string& phone_number)
{
    std::stringstream builder;
    for (int i = 0; i < phone_number.size(); i++)
    {
        char c = keypad[phone_number[i]];
        if (c)
        {
            builder << c;
        }
    }
    return builder.str();
}

bool Compare(const std::pair<std::string, int>& a, 
             const std::pair<std::string, int>& b)
{
    return a.first < b.first;
}

int main(int argc, char* argv[]) 
{
    InitKeypadMap();

    int num_testcases;
    std::cin >> num_testcases;

    int num_phone_numbers;
    std::string phone_number;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        std::map<std::string, int> frequency;
        std::cin >> num_phone_numbers;
        for (int i = 0; i < num_phone_numbers; i++)
        {
            std::cin >> phone_number;
            frequency[Normalize(phone_number)]++;
        }

        std::vector< std::pair<std::string, int> > phone_numbers;
        for (std::map<std::string, int>::iterator it = frequency.begin(); 
            it != frequency.end(); it++)
        {
            phone_numbers.push_back(std::make_pair(it->first, it->second));
        }

        std::sort(phone_numbers.begin(), phone_numbers.end(), Compare);
        bool is_duplicated = false;
        for (int i = 0; i < phone_numbers.size(); i++)
        {
            if (phone_numbers[i].second > 1)
            {
                is_duplicated = true;
                printf("%s-%s %d\n", 
                    phone_numbers[i].first.substr(0, 3).c_str(), 
                    phone_numbers[i].first.substr(3).c_str(), 
                    phone_numbers[i].second);
            }
        }
        if (!is_duplicated)
        {
            puts("No duplicates.");
        }
    }
    return 0;
}