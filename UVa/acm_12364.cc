#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

std::string braille[3][10] = 
{
    { "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*", ".*" },
    { "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*.", "**" },
    { "..", "..", "..", "..", "..", "..", "..", "..", "..", ".." },
};

std::map<std::string, char> braille_map;

void InitBrailleMap()
{
    std::string regular_literal("1234567890");

    for (int j = 0; j < 10; j++)
    {
        std::stringstream query;
        for (int i = 0; i < 3; i++)
        {
            query << braille[i][j];
        }
        braille_map[query.str()] = regular_literal[j];
    }
}

// -----------------------------------------------------------------------------

void PrintBrailleNumber(const std::string& number, int length)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%s", braille[i][(number[j] - '0' + 9) % 10].c_str());
            putchar((j != length-1) ? ' ' : '\n');
        }
    }
}

// -----------------------------------------------------------------------------

std::string numerical_expression;
std::string braille_expression[3];

void ReadBrailleExpression()
{
    for (int i = 0; i < 3; i++)
    {
        getline(std::cin, braille_expression[i]);
    }
}

char ParseBrailleLiteral(int pos)
{
    std::stringstream query;
    for (int i = 0; i < 3; i++)
    {
        query << braille_expression[i].substr(pos, 2);
    }
    return braille_map[query.str()];
}

std::string ParseBrailleExpression()
{
    std::stringstream builder;
    int length = braille_expression[0].size();
    for (int i = 0; i <= length - 2; i += 3)
    {
        builder << ParseBrailleLiteral(i);
    }
    return builder.str();
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitBrailleMap();

    int N;
    char type;
    while (std::cin >> N && N)
    {
        std::cin >> type;
        getchar();
        if (type == 'B')
        {
            ReadBrailleExpression();
            std::cout << ParseBrailleExpression() << std::endl;
        }
        else 
        {
            getline(std::cin, numerical_expression);
            PrintBrailleNumber(numerical_expression, N);
        }
    }
    return 0;
}