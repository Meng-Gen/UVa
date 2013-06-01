#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        std::string plaintext;
        getline(std::cin, plaintext);
        std::string substitution;
        getline(std::cin, substitution);

        puts(substitution.c_str());
        puts(plaintext.c_str());

        std::map<char, char> cypher;
        for (int i = 0; i < plaintext.size(); i++)
        {
            cypher[plaintext[i]] = substitution[i];
        }

        std::string text;
        while (getline(std::cin, text) && text.size())
        {
            for (int i = 0; i < text.size(); i++)
            {
                char encoded = cypher[text[i]];
                if (encoded) 
                {
                    putchar(encoded);
                }
                else
                {
                    putchar(text[i]);
                }
            }
            putchar('\n');
        }
    }

    return 0;
}