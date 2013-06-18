#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

template <class T>
inline std::string to_string(const T& t) {
    std::stringstream builder;
    builder << t;
    return builder.str();
}

template <class T>
inline T to_type(const std::string& s) {
    std::stringstream builder(s);
    T t;
    builder >> t;
    return t;
}

// Time: 0.018(s)
int kaprekar_numbers[19] = 
{
    9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 
    4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962
};

// Time: 0.655(s)
inline void InitKaprekarNumbers()
{    
    int curr_pos = 0;
    long long part[2];
    std::string square_literal;
    for (int i = 4; i < 40001; i++)
    {
        bool found = false;

        square_literal = to_string<long long>(i*i);
        for (int j = 1; j < square_literal.size(); j++)
        {
            part[0] = to_type<long long>(square_literal.substr(0, j));
            part[1] = to_type<long long>(square_literal.substr(j));
            if (part[0] && part[1] && i == part[0] + part[1])
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            kaprekar_numbers[curr_pos] = i;
            curr_pos++;
        }
    }
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    int lower_bound, upper_bound;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> lower_bound >> upper_bound;

        if (case_id > 1)
        {
            putchar('\n');
        }
        printf("case #%d\n", case_id);

        bool found = false;
        for (int i = 0; i < 19; i++)
        {
            if (kaprekar_numbers[i] > upper_bound)
            {
                break;
            }
            if (kaprekar_numbers[i] >= lower_bound)
            {
                found = true;
                printf("%d\n", kaprekar_numbers[i]);
            }
        }

        if (!found)
        {
            puts("no kaprekar numbers");
        }
    }
    return 0;
}