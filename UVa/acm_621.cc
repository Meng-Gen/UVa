#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::string result;
        std::cin >> result;
        unsigned int length = result.size();

        if (result.compare("1") == 0
            || result.compare("4") == 0
            || result.compare("78") == 0)
        {
            printf("+\n");
        }
        else if (result[length - 2] == '3' && result[length - 1] == '5')
        {
            printf("-\n");
        }
        else if (result[0] == '9' && result[length - 1] == '4')
        {
            printf("*\n");
        }
        else 
        {
            printf("?\n");
        }
    }

    return 0;
}