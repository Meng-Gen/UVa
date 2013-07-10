#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

std::vector<std::string> Tokenize(const std::string& buffer) {
    std::stringstream tokenizer(buffer);
    std::istream_iterator<std::string> it(tokenizer);
    std::istream_iterator<std::string> end;
    return std::vector<std::string>(it, end);
}

// -----------------------------------------------------------------------------

std::string SortWord(const std::string& word) 
{
    std::string sorted = word;
    std::transform(sorted.begin(), sorted.end(), sorted.begin(), ::tolower);
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

int main(int argc, char* argv[])
{
    std::map<std::string, int> freq;
    std::map<std::string, std::string> dict;

    std::string buffer;
    while (getline(std::cin, buffer) && (buffer != "#"))
    {
        std::vector<std::string> words(Tokenize(buffer));

        for (std::vector<std::string>::iterator it = words.begin();
            it != words.end(); it++)
        {
            std::string sorted = SortWord(*it);
            dict[sorted] = *it;
            freq[sorted]++;
        }
    }

    std::vector<std::string> ananagrams;
    for (std::map<std::string, int>::iterator it = freq.begin();
        it != freq.end(); it++)
    {
        if (it->second == 1)
        {
            ananagrams.push_back(dict[it->first]);
        }
    }
    std::sort(ananagrams.begin(), ananagrams.end());
    for (std::vector<std::string>::iterator it = ananagrams.begin();
        it != ananagrams.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}