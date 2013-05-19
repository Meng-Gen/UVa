#include <iostream>
#include <string>
#include <stdio.h>

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsPlainChar(char c) {
    return IsInRange(c, 'a', 'z') || IsInRange(c, 'A', 'Z') 
        || c == ' ' || c == '!' || c == ',' || c == '.' 
        || c == ':' || c == ';' || c == '?'; 
}

void Encode(const std::string& message) 
{
    for (int i = message.size() - 1; i >= 0; i--)
    {
        int c = message[i];
        int encoded = 0;
        while (c > 0) 
        {
            encoded *= 10;
            encoded += (c % 10);
            c /= 10;
        }
        std::cout << encoded;
    }
    std::cout << std::endl;
}

void Decode(const std::string& message) 
{
    for (int i = message.size() - 1; i >= 0; i--)
    {
        int c = message[i];
        int decoded = 0;
        if (c == '1' && i >= 2)
        {
            decoded = 100 + 10 * (message[i-1] - '0') + message[i-2] - '0';
            i -= 2;
        }
        else if (i >= 1)
        {
            decoded = 10 * (c - '0') + message[i-1] - '0';
            i -= 1;
        }
        printf("%c", decoded);
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::string message;
    while (getline(std::cin, message))
    {
        if (IsPlainChar(message[0]))
        {
            Encode(message);
        }
        else
        {
            Decode(message);
        }
    }

    return 0;
}