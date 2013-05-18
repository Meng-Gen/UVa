#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int case_id = 1;
    std::string word;
    while (getline(std::cin, word))
    {
        if (word == "*")
        {
            break;
        }
        
        if (word == "Hajj")
        {
            printf("Case %d: Hajj-e-Akbar\n", case_id);
        }
        else if (word == "Umrah")
        {
            printf("Case %d: Hajj-e-Asghar\n", case_id);
        }
        case_id++;
    }
    
    return 0;
}