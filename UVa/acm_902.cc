#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int password_size;
    std::string encoded_messages;
    while (std::cin >> password_size >> encoded_messages)
    {
        std::map<std::string, int> candidates;

        int length = encoded_messages.size();
        for (int i = 0; i < length - password_size + 1; i++)
        {
            std::string candidate = encoded_messages.substr(i, password_size);
            candidates[candidate]++;
        }

        int max_appearence = -1;
        std::string password;
        std::map<std::string, int>::iterator it;
        for (it = candidates.begin(); it != candidates.end(); it++)
        {
            if ((*it).second > max_appearence)
            {
                password = (*it).first; 
                max_appearence = (*it).second;
            }
        }

        std::cout << password << std::endl;
    }

    return 0;
}