#include <iostream>
#include <string>
#include <stdio.h>

int BigIntegerMod(const std::string& number, int mod)
{
    int rv = 0;

    for (std::string::const_iterator it = number.begin(); 
        it != number.end(); it++)
    {
        rv *= 10;
        rv += ((*it) - '0');
        rv %= mod;
    }

    return rv;
}

// -----------------------------------------------------------------------------

bool IsLessThanBaseYear(const std::string& number)
{
    if (number.size() > 4)
    {
        return false;
    }

    int year = 0;
    for (int i = 0; i < number.size(); i++)
    {
        year *= 10;
        year += number[i] - '0';
    }

    return (year < 2148) ? true : false;
}

std::string ghost_name[9] = 
{
    "Tanveer Ahsan",
    "Shahriar Manzoor",
    "Adrian Kugel",
    "Anton Maydell",
    "Derek Kisman",
    "Rezaul Alam Chowdhury",
    "Jimmy Mardell",
    "Monirul Hasan",
    "K. M. Iftekhar",
};

int ghost_period[8] = { 2, 5, 7, 11, 15, 20, 28, 36 };
int base_remainder[8] = {};

inline void InitBaseRemainder()
{
    for (int i = 0; i < 8; i++)
    {
        base_remainder[i] = 2148 % ghost_period[i];
    }
}

int main(int argc, char* argv[])
{
    InitBaseRemainder();

    int case_id = 0;
    std::string number;
    while (std::cin >> number && (number != "0"))
    {
        if (case_id)
        {
            putchar('\n');
        }
        puts(number.c_str());

        // All the ghost first came at the year 2148.
        // So no ghost will come before the year 2148 even leap years.
        if (IsLessThanBaseYear(number))
        {
            puts("No ghost will come in this year");
            case_id++;
            continue;
        }

        bool found = false;
        for (int i = 0; i < 8; i++)
        {
            if (BigIntegerMod(number, ghost_period[i]) == base_remainder[i])
            {
                printf("Ghost of %s!!!\n", ghost_name[i].c_str());
                found = true;
            }
        }

        if ((BigIntegerMod(number, 400) == 0) || 
            (BigIntegerMod(number, 100) != 0 && BigIntegerMod(number, 4) == 0))
        {
            puts("Ghost of K. M. Iftekhar!!!");
            found = true;
        }
        if (!found)
        {
            puts("No ghost will come in this year");
        }

        case_id++;
    }
    return 0;
}