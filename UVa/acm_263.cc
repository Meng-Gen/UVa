#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <stdio.h>

long long n;
long long ascending_n;
long long descending_n;

void ArrangeNumber()
{
    std::stringstream builder;
    builder << n;

    std::string n_literal = builder.str();
    std::sort(n_literal.begin(), n_literal.end());

    ascending_n = 0;
    for (int i = 0; i < n_literal.size(); i++)
    {
        ascending_n *= 10;
        ascending_n += (n_literal[i] - '0');
    }

    descending_n = 0;
    for (int i = n_literal.size() - 1; i >= 0; i--)
    {
        descending_n *= 10;
        descending_n += (n_literal[i] - '0');
    }
}

int main(int argc, char* argv[])
{
    while (std::cin >> n && n)
	{
        printf("Original number was %lld\n", n);

        std::set<int> chain;
        while (1)
        {
            ArrangeNumber();
            long long curr_number = descending_n - ascending_n;
            printf("%lld - %lld = %lld\n", 
                descending_n, ascending_n, curr_number);

            // Repeat these steps unless the new number has already appeared 
            // in the chain.
            if (chain.find(curr_number) != chain.end())
            {
                break;
            }
            else
            {
                chain.insert(curr_number);
                n = curr_number;
            }
        }

        printf("Chain length %d\n\n", chain.size() + 1);
	}
	
	return 0;
}