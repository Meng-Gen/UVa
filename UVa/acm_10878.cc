#include <iostream>
#include <string>
#include <stdio.h>

char DecodeAscii(const std::string& tape)
{
    int length = tape.size();
    if (length != 11)
    {
        return 0;
    }
    int ascii_value = 0;
    for (int i = 1; i < 10; i++)
    {
        if (i != 6)
        {
            ascii_value *= 2;
        }

        if (tape[i] == 'o')
        {    
            ascii_value += 1;
        }
    }

    return ascii_value;
}

int main(int argc, char* argv[])
{
    std::string tape;
    while (getline(std::cin, tape))
    {
        char decoded = DecodeAscii(tape);
        if (decoded)
        {
            putchar(decoded);
        }
    }

    return 0;
}