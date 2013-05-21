#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

bool prime[2000] = {};

void InitPrimeTable()
{
    memset(prime, 1, 2000);
    prime[0] = false;
    prime[1] = true;
    for (int i = 2; i < 2000; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i < 2000; j++)
            {
                prime[j*i] = false;
            }
        }
    }
}

int GetValue(const std::string& word)
{
    int rv = 0;
    for (unsigned int i = 0; i != word.size(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            rv += (word[i] - 'a' + 1);
        }
        else 
        {
            rv += (word[i] - 'A' + 27);
        }
    }
    return rv;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    std::string word;
    while (std::cin >> word)
    {
        if (prime[GetValue(word)])
        {
            puts("It is a prime word.");
        }
        else
        {
            puts("It is not a prime word.");
        }
    }
    return 0;
}