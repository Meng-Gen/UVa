//  Greedy.
#include <iostream>
#include <string>
#include <stdio.h>

//  Sanity test: 
//      aa aaa => Yes
//      aaa aaa => Yes
//      aaa aa => No
int main(int argc, char* argv[])
{
    std::string s;
    std::string t;

    while (std::cin >> s >> t)
    {
        bool is_matched = false;
        unsigned int matching_index = 0;
        for (unsigned int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[matching_index])
            {
                matching_index++;
            }

            if (matching_index == s.size())
            {
                is_matched = true;
                break;
            }
        }

        if (is_matched)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}