#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::map<std::string, long long> hay_points;

    int num_words, num_descriptions;
    std::cin >> num_words >> num_descriptions;
    
    std::string word;
    for (int i = 0; i < num_words; i++)
    {
        
        long long points;
        std::cin >> word >> points;
        hay_points[word] = points;
    }

    for (int i = 0; i < num_descriptions; i++)
    {
        long long total_points = 0LL;
        while (std::cin >> word && (word.compare(".") != 0))
        {
            total_points += hay_points[word];
        }
        printf("%lld\n", total_points);
    }

    return 0;
}