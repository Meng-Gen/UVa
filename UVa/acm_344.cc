#include <iostream>
#include <stdio.h>

// i, v, x, l, c
int roman_digit_base1[10][5] = 
{ 
    { 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0 },
    { 2, 0, 0, 0, 0 },
    { 3, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 2, 1, 0, 0, 0 },
    { 3, 1, 0, 0, 0 },
    { 1, 0, 1, 0, 0 },
};

int roman_digit_base10[10][5] =
{ 
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 2, 0, 0 },
    { 0, 0, 3, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 2, 1, 0 },
    { 0, 0, 3, 1, 0 },
    { 0, 0, 1, 0, 1 },
};

int roman_digit_base100[2][5] = 
{
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1 },
};

// -----------------------------------------------------------------------------

int query[101][5] = {};

void InitQueryTable()
{
    for (int i = 1; i <= 100; i++)
    {
        int base1 = i % 10;
        int base10 = (i/10) % 10;
        int base100 = i/100;
        for (int j = 0; j < 5; j++)
        {
            query[i][j] = query[i-1][j];
            query[i][j] += roman_digit_base1[base1][j];
            query[i][j] += roman_digit_base10[base10][j];
            query[i][j] += roman_digit_base100[base100][j];
        }
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitQueryTable();

    int n;
    while (std::cin >> n && n)
    {        
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, 
            query[n][0], query[n][1], query[n][2], query[n][3], query[n][4]);
    }
    
    return 0;
}