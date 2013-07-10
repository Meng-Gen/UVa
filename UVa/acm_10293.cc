#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>

std::string buffer;
int buffer_size;
std::map<int, int> frequency;

int main(int argc, char* argv[])
{
    int len = 0;
    char c;
    while (getline(std::cin, buffer))
    {
        if (buffer == "#")
        {
            std::vector< std::pair<int, int> > sorted;
            for (std::map<int, int>::iterator it = frequency.begin();
                it != frequency.end(); it++)
            {
                sorted.push_back(std::make_pair(it->first, it->second));
            }
            sort(sorted.begin(), sorted.end());

            for (int i = 0; i < sorted.size(); i++)
            {
                if (sorted[i].first)
                {
                    printf("%d %d\n", sorted[i].first, sorted[i].second);
                }
            }
            putchar('\n');

            frequency.clear();
            continue;
        }

        buffer_size = buffer.size();
        for (int i = 0; i < buffer_size; i++)
        {
            c = buffer[i];
            if (c == ' ' || c == '?' || c == '!' || c == ',' || c == '.')
            {
                if (len)
                {
                    frequency[len]++;
                }
                len = 0;
            }
            else if (c != '\'' && c != '-')
            {
                len++;
            }
            
            if (i == buffer_size - 1 && c != '-' && len)
            {
                if (len)
                {
                    frequency[len]++;
                }
                len = 0;
            }
        }
    }

    return 0;
}