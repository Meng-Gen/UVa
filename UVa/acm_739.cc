#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

std::map<char, int> code;

inline void InitSoundexCode()
{
    code['B'] = code['P'] = code['F'] = code['V'] = 1;
    code['C'] = code['S'] = code['K'] = code['G'] = code['J'] = 
        code['Q'] = code['X'] = code['Z'] = 2;
    code['D'] = code['T'] = 3;
    code['L'] = 4;
    code['M'] = code['N'] = 5;
    code['R'] = 6;
}

std::string GetSoundexIndexing(const std::string& word)
{
    int length = word.size();
    if (length == 0)
    {
        return "";
    }

    std::stringstream builder;
    builder << word[0];

    int curr_code;
    int prev_code = code[word[0]];
    for (int i = 1; i < length; i++)
    {
        curr_code = code[word[i]];
        if (prev_code != curr_code && curr_code)
        {
            builder << curr_code;
        }
        prev_code = curr_code;
    }

    // Trailing zeros are appended to short codes
    builder << "000";

    // Longer codes are truncated after the third digit.
    return builder.str().substr(0, 4);
}

int main(int argc, char* argv[])
{
    InitSoundexCode();

    puts("         NAME                     SOUNDEX CODE");

    std::string buffer;    
    while (getline(std::cin, buffer))
    {
        printf("         %-25s%-s\n", 
            buffer.c_str(), 
            GetSoundexIndexing(buffer).c_str());
    }
    
    puts("                   END OF OUTPUT");
    return 0;
}