#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

bool CompareDelegate(char a, char b) 
{
    if (AsciiAlphaToLower(a) < AsciiAlphaToLower(b))
    {
        return true;
    }
    else if (AsciiAlphaToLower(a) > AsciiAlphaToLower(b))
    {
        return false;
    }
    return a < b;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::string word;
        std::cin >> word;

        sort(word.begin(), word.end(), CompareDelegate);
        do
        {
            std::cout << word << std::endl;
        }
        while (std::next_permutation(word.begin(), word.end(), CompareDelegate));
    }

    return 0;
}