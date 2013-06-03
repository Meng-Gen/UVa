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
    long long x;
    while (std::cin >> x)
    {
        getchar();
        std::string buffer;
        getline(std::cin, buffer);
        Sequence c = ParseSequence(buffer);
        unsigned int n = c.size();
        
        long long valuation = 0;
        for (unsigned int j = 0; j < n - 1; j++)
        {
            valuation = x * valuation + (n - 1 - j) * c[j];
        }

        printf("%lld\n", valuation);
    }

    return 0;
}