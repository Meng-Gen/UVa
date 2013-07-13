#include <iostream>
#include <string>
#include <stdio.h>

bool IsMutagenic(const std::string& structure);

bool IsSimple(const std::string& structure)
{
    return structure == "A";
}

bool IsFullyGrown(const std::string& structure)
{
    int len = structure.size();
    if (len < 3 || structure[len-2] != 'A' || structure[len-1] != 'B')
    {
        return false;
    }
    std::string next = structure.substr(0, len - 2);
    return IsSimple(next) || IsFullyGrown(next) || IsMutagenic(next);
}

bool IsMutagenic(const std::string& structure)
{
    int len = structure.size();
    if (len < 3 || structure[0] != 'B' || structure[len-1] != 'A')
    {
        return false;
    }
    std::string next = structure.substr(1, len - 2);
    return IsSimple(next) || IsFullyGrown(next) || IsMutagenic(next);
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::string buffer;
        std::cin >> buffer;
        if (IsSimple(buffer))
        {
            puts("SIMPLE");
        }
        else if (IsFullyGrown(buffer))
        {
            puts("FULLY-GROWN");
        }
        else if (IsMutagenic(buffer))
        {
            puts("MUTAGENIC");
        }
        else
        {
            puts("MUTANT");
        }
    }
    return 0;
}