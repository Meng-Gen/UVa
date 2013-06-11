#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// -----------------------------------------------------------------------------

int HexToInt(const std::string& hex)
{
    int rv = 0;
    for (int i = 0; i < hex.size(); i++)
    {
        char c = hex[i];
        rv *= 16;
        if (IsInRange(c, '0', '9'))
        {
            rv += c - '0';
        }
        else 
        {
            rv += AsciiAlphaToLower(c) - 'a' + 10;
        }
    }
    return rv;
}

std::map<char, std::string> hex_to_binary_map;

void InitHexToBinaryMap()
{
    hex_to_binary_map['0'] = "0000";
    hex_to_binary_map['1'] = "0001";
    hex_to_binary_map['2'] = "0010";
    hex_to_binary_map['3'] = "0011";
    hex_to_binary_map['4'] = "0100";
    hex_to_binary_map['5'] = "0101";
    hex_to_binary_map['6'] = "0110";
    hex_to_binary_map['7'] = "0111";
    hex_to_binary_map['8'] = "1000";
    hex_to_binary_map['9'] = "1001";
    hex_to_binary_map['a'] = "1010";
    hex_to_binary_map['b'] = "1011";
    hex_to_binary_map['c'] = "1100";
    hex_to_binary_map['d'] = "1101";
    hex_to_binary_map['e'] = "1110";
    hex_to_binary_map['f'] = "1111";
}

std::string HexToBinary(const std::string& hex)
{
    std::stringstream rv;
    rv << "0";
    int length = hex.size();
    for (int i = 0; i < 3 - length; i++)
    {
        rv << "0000";
    }

    for (int i = 0; i < length; i++)
    {
        rv << hex_to_binary_map[AsciiAlphaToLower(hex[i])];
    }
    return rv.str();
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitHexToBinaryMap();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        std::string hex[2];
        char op;

        std::cin >> hex[0] >> op >> hex[1];
        int rv = 0;
        if (op == '+')
        {
            rv = HexToInt(hex[0]) + HexToInt(hex[1]);
        }
        else if (op == '-')
        {
            rv = HexToInt(hex[0]) - HexToInt(hex[1]);
        }
        printf("%s %c %s = %d\n", 
            HexToBinary(hex[0]).c_str(), op, HexToBinary(hex[1]).c_str(), rv);
    }
    return 0;
}