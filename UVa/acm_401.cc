#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<char, char> mirrored_alpha;

void InitMirroredAlpha()
{
    std::string character("AEHIJLMOSTUVWXYZ12358");
    std::string reversed("A3HILJMO2TUVWXY51SEZ8");

    for (int i = 0; i < character.size(); i++)
    {
        mirrored_alpha[character[i]] = reversed[i];
    }
}

bool IsPalindrome(const std::string& word)
{
    int length = word.size();
    for (int i = 0; i < length/2; i++)
    {
        if (word[i] != word[length-1-i])
        {
            return false;
        }
    }
    return true;
}

bool IsMirrored(const std::string& word)
{
    int length = word.size();
    for (int i = 0; i < length/2; i++)
    {
        if (mirrored_alpha[word[i]] == 0)
        {
            return false;
        }
        if (mirrored_alpha[word[i]] != word[length-1-i])
        {
            return false;
        }
    }

    if ((length % 2 != 0) && (mirrored_alpha[word[length/2]] == 0))
    {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) 
{   
    InitMirroredAlpha();

    std::string word;
    while (std::cin >> word)
    {
        if (IsPalindrome(word))
        {
            if (IsMirrored(word))
            {
                printf("%s -- is a mirrored palindrome.\n\n", word.c_str());
            }
            else
            {
                printf("%s -- is a regular palindrome.\n\n", word.c_str());   
            }
        }
        else if (IsMirrored(word))
        {
            printf("%s -- is a mirrored string.\n\n", word.c_str());
        }
        else
        {
            printf("%s -- is not a palindrome.\n\n", word.c_str());
        }
    }
    return 0;
}
