#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        int num_paid_characters;
        std::cin >> num_paid_characters;
        
        std::map<char, long long> paid_characters;
        char character;
        long long value;
        for (int i = 0; i < num_paid_characters; i++)
        {
            std::cin >> character >> value;
            paid_characters[character] = value;
        }

        int num_lines;
        std::cin >> num_lines;
        getchar();

        long long pay = 0;
        std::string line;
        for (int i = 0; i < num_lines; i++)
        {
            getline(std::cin, line);
            for (std::string::iterator it = line.begin(); 
                it != line.end(); it++)
            {
                pay += paid_characters[*it];
            }
        }
        printf("%lld.%.02lld$\n", pay/100, pay%100);
    }
    return 0;
}