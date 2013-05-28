#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsAsciiAlpha(char c) {
    return IsInRange(c, 'a', 'z');
}

bool CompareDelegate(std::pair<char, int> lhs, std::pair<char, int> rhs)
{	
    if (lhs.second > rhs.second)
    {
        return true;
    }
    if (lhs.second < rhs.second)
    {
        return false;
    }
    if (lhs.first < rhs.first) 
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    while (num_testcases--) 
    {
        std::string buffer;
        getline(std::cin, buffer);
        
        std::pair<char, int> frequency[26];
        for (int i = 0; i < 26; i++)
        {
            frequency[i].first = 'a' + i;
            frequency[i].second = 0;
        }

        for (std::string::iterator it = buffer.begin(); 
            it != buffer.end(); it++)
        {
            char c = AsciiAlphaToLower(*it);
            if (IsAsciiAlpha(c))
            {
                frequency[c - 'a'].second++;
            }
        }

        std::sort(frequency, frequency + 26, CompareDelegate);
        int max_count = frequency[0].second;
        for (int i = 0; i < 26; i++)
        {
            if (frequency[i].second != max_count) 
            {
                break;
            }
            putchar(frequency[i].first);
        }
        putchar('\n');
    }
    return 0;
}