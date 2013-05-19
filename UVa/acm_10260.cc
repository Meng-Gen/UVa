#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::map<char, int> soundex;
    soundex['B'] = 1;
    soundex['F'] = 1;
    soundex['P'] = 1;
    soundex['V'] = 1;
    soundex['C'] = 2;
    soundex['G'] = 2;
    soundex['J'] = 2;
    soundex['K'] = 2;
    soundex['Q'] = 2;
    soundex['S'] = 2;
    soundex['X'] = 2;
    soundex['Z'] = 2;
    soundex['D'] = 3;
    soundex['T'] = 3;
    soundex['L'] = 4;
    soundex['M'] = 5;
    soundex['N'] = 5;    
    soundex['R'] = 6;

    std::string word;
    while (getline(std::cin, word))
    {
        char last_sound = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int sound = soundex[word[i]];
            if (sound == last_sound) 
            {
                continue;
            }
            last_sound = sound;
            if (sound)
            {
                std::cout << sound;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}