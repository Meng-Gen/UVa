#include <iostream>
#include <string>
#include <stdio.h>

inline bool IsVowelChar(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool AreEqual(const std::string& a, const std::string& b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    
    for (unsigned int i = 0; i != a.size(); i++)
    {
        if (a[i] != b[i]) 
        {
            if (!IsVowelChar(a[i]) || !IsVowelChar(b[i])) 
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int i = 0; i < num_testcases; i++)
    {
        std::string names[2];
        std::cin >> names[0] >> names[1];

        if (AreEqual(names[0], names[1]))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}