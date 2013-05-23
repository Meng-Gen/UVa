#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// Euclidean Algorithm
int gcd(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int main(int argc, char* argv[])
{
    int num_testcases; 
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        std::string buffer;
        getline(std::cin, buffer);

        std::stringstream buffer_stream(buffer);
        std::istream_iterator<int> it(buffer_stream);
        std::istream_iterator<int> end;
        std::vector<int> num(it, end);

        unsigned int length = num.size();
        int rv = 1;
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = i + 1; j < length; j++)
            {
                rv = maximum(rv, gcd(num[i], num[j]));
            }
        }
        std::cout << rv << std::endl;
    }
    return 0;
}