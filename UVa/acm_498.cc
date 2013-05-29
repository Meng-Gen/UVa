#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

typedef std::vector<long long> Sequence;
typedef std::vector<long long>::iterator SequenceIterator;

Sequence ParseSequence(const std::string& buffer) 
{
    std::stringstream buffer_stream(buffer);
    std::istream_iterator<long long> it(buffer_stream);
    std::istream_iterator<long long> end;
    return Sequence(it, end);
}

int main(int argc, char* argv[])
{
    std::string buffer;
    while (getline(std::cin, buffer))
    {
        Sequence c = ParseSequence(buffer);
        unsigned int n = c.size();

        getline(std::cin, buffer);
        Sequence x = ParseSequence(buffer);
        unsigned int m = x.size();

        Sequence valuation;
        for (unsigned int i = 0; i < m; i++)
        {
            valuation.push_back(0);
            for (unsigned int j = 0; j < n; j++)
            {
                valuation[i] *= x[i];
                valuation[i] += c[j];
            }
        }

        for (unsigned int i = 0; i < m; i++)
        {
            printf("%lld", valuation[i]);
            if (i != m-1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }

    return 0;
}