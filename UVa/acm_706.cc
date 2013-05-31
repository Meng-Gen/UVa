#include <iostream>
#include <string>
#include <stdio.h>

bool lcd[10][5][3] = 
{
    // 0
    { 
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 0, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
    },
    // 1
    {
        { 0, 0, 0 },
        { 0, 0, 1 },
        { 0, 0, 0 },
        { 0, 0, 1 },
        { 0, 0, 0 },
    },
    // 2
    {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 },
        { 1, 0, 0 },
        { 0, 1, 0 },
    },
    // 3
    { 
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 },
    },
    // 4
    {
        { 0, 0, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 0, 0 },
    },
    // 5
    {
        { 0, 1, 0 },
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 },
    },
    // 6
    { 
        { 0, 1, 0 },
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
    },
    // 7
    {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 0, 0 },
        { 0, 0, 1 },
        { 0, 0, 0 },
    },
    // 8
    {
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
    },
    // 9
    { 
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 },
    },
};

int s;
std::string n;

void PrintHorizontalDisplay(int position)
{
    int digit_length = n.size();
    for (int digit_index = 0; digit_index < digit_length; digit_index++)
    {
        int digit = n[digit_index] - '0';
        
        putchar(' ');
        for (int i = 0; i < s; i++)
        {
            if (lcd[digit][position][1])
            {
                putchar('-');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar(' ');

        if (digit_index == digit_length - 1)
        {
            putchar('\n');
        }
        else
        {
            putchar(' ');
        }
    }
}

void PrintVerticalDisplay(int position)
{
    int digit_length = n.size();
    for (int i = 0; i < s; i++)
    {
        for (int digit_index = 0; digit_index < digit_length; digit_index++)
        {
            int digit = n[digit_index] - '0';

            if (lcd[digit][position][0])
            {
                putchar('|');
            }
            else
            {
                putchar(' ');
            }
            for (int j = 0; j < s; j++)
            {
                putchar(' ');
            }
            if (lcd[digit][position][2])
            {
                putchar('|');
            }
            else
            {
                putchar(' ');
            }

            if (digit_index == digit_length - 1)
            {
                putchar('\n');
            }
            else
            {
                putchar(' ');
            }
        }
    }
}

int main(int argc, char* argv[])
{
    while (std::cin >> s >> n && (s != 0 || n != "0"))
    {
        PrintHorizontalDisplay(0);
        PrintVerticalDisplay(1);
        PrintHorizontalDisplay(2);
        PrintVerticalDisplay(3);
        PrintHorizontalDisplay(4);
        putchar('\n');
    }
    return 0;
}