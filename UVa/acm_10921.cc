#include <iostream>
#include <map>
#include <stdio.h>

// Each expression is in a line by itself and has C characters, 
// where 1 <= C <= 30. 
char buffer[40];

int main(int argc, char* argv[])
{
    std::map<char, char> keyboard_map;
    for (int i = 0; i < 18; i++)
    {
        keyboard_map['A' + i] = '2' + (i / 3);
    }
    keyboard_map['S'] = '7';
    for (int i = 19; i < 25; i++)
    {
        keyboard_map['A' + i] = '2' + ((i-1) / 3);
    }
    keyboard_map['Z'] = '9';

    keyboard_map['-'] = '-';
    keyboard_map['0'] = '0';
    keyboard_map['1'] = '1';

    while (std::cin.getline(buffer, 40))
    {
        for (int j = 0; buffer[j] != '\0'; j++)
        {
            printf("%c", keyboard_map[buffer[j]]);
        }
        printf("\n");
    }
    return 0;
}