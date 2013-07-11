#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char c;
    int repeated = 0;
    std::string buffer;
    while (getline(std::cin, buffer))
    {
        for (int i = 0; i < buffer.size(); i++)
        {
            c = buffer[i];
            if (c == '!')
            {
                putchar('\n');
            }
            else if (c >= '0' && c <= '9')
            {
                repeated += c - '0';
            }
            else 
            {
                for (int i = 0; i < repeated; i++)
                {
                    putchar((c != 'b') ? c : ' ');
                }
                repeated = 0;
            }
        }
        putchar('\n');
    }
    return 0;
}