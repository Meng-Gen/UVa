#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::string a;
    std::string b;
    while (getline(std::cin, a))
    {
        getline(std::cin, b);
        std::multiset<char> set_b(b.begin(), b.end());

        std::vector<char> rv;
        std::multiset<char>::iterator j;
        for (unsigned int i = 0; i != a.size(); i++)
        {
            j = set_b.find(a[i]);
            if (j != set_b.end())
            {
                rv.push_back(a[i]);
                set_b.erase(j);
            }
        }

        sort(rv.begin(), rv.end());

        for (unsigned int i = 0; i != rv.size(); i++)
        {
            putchar(rv[i]);
        }
        putchar('\n');
    }
    return 0;
}