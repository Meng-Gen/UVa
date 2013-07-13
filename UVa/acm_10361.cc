#include <iostream>
#include <string>
#include <stdio.h>

std::string line[2];
std::string s[5];

// s1<s2>s3<s4>s5
void Tokenize(const std::string& buffer)
{
    char delimiters[4] = { '<', '>', '<', '>' };
    int pos[5] = { -1 };
    for (int i = 1; i < 5; i++)
    {
        for (pos[i] = pos[i-1]+1; buffer[pos[i]] != delimiters[i-1]; pos[i]++);
        s[i-1] = buffer.substr(pos[i-1]+1, pos[i]-pos[i-1]-1);
    }
    s[4] = buffer.substr(pos[4]+1);
}

void PrintPoetry()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s", s[i].c_str());
    }
    putchar('\n');

    printf("%s", line[1].substr(0, line[1].size() - 3).c_str());
    printf("%s", s[3].c_str());
    printf("%s", s[2].c_str());
    printf("%s", s[1].c_str());
    printf("%s", s[4].c_str());
    putchar('\n');
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    while(num_testcases--)
    {
        getline(std::cin, line[0]);
        getline(std::cin, line[1]);
        Tokenize(line[0]);
        PrintPoetry();
    }
    return 0;
}