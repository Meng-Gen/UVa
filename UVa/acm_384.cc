#include <iostream>
#include <string>
#include <stdio.h>

bool IsSlump(const std::string& s)
{
    int len = s.size();
    if (len <= 0 || (s[0] != 'D' && s[0] != 'E'))
    {
        return false;
    }
    if (len <= 1 || s[1] != 'F') 
    {
        return false;
    }
    int last_pos = 1;
    for (; s[last_pos] == 'F'; last_pos++);
    if (last_pos == len-1 && s[last_pos] == 'G')
    {
        return true;
    }
    return IsSlump(s.substr(last_pos));
}

bool IsSlimp(const std::string& s)
{
    int len = s.size();
    if (len <= 0 || s[0] != 'A')
    {
        return false;
    }
    if (len == 2)
    {
        return s[1] == 'H';
    }
    if (len < 2)
    {
        return false;
    }
    if (s[len-1] != 'C')
    {
        return false;
    }
    return (s[1] == 'B' && IsSlimp(s.substr(2, len-3))) || 
        IsSlump(s.substr(1, len-2));
}

bool IsSlurpy(const std::string& s)
{
    int len = s.size();
    for (int i = 1; i < len; i++)
    {
        if (IsSlimp(s.substr(0, i)) && IsSlump(s.substr(i)))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    puts("SLURPYS OUTPUT");
    while (num_testcases--)
    {
        std::string buffer;
        std::cin >> buffer;
        if (IsSlurpy(buffer))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    puts("END OF OUTPUT");
    return 0;
}