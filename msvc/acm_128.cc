#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int g = 34943;

    std::string message;
    while (1)
    {
        getline(std::cin, message);
        if (message.compare("#") == 0)
        {
            break;
        }
        
        long long sum = 0;
        for (unsigned int i = 0; i < message.length(); i++)
        {
            sum <<= 8;
            sum %= g;
            sum += message[i];
            sum %= g;
        }
        sum <<= 16;
        sum %= g;
        int r = (g - sum) % g;
        printf("%02X %02X\n", r >> 8, r % (1 << 8));
    }
    return 0;
}