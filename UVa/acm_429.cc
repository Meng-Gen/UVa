#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

#define INFINITY_WEIGHT (999)

int T[205][205] = {};

inline int minimum(int a, int b) 
{
    return (a < b) ? a : b;
}

bool HasTransformation(const std::string& a, const std::string& b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    int diff_count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            diff_count++;
        }
    }
    return (diff_count == 1);
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        std::map<std::string, int> word_map;
        std::map<int, std::string> word_id_map;
        std::string word;
        int dictionary_size = 0;
        while (std::cin >> word && word.compare("*"))
        {
            word_map[word] = dictionary_size;
            word_id_map[dictionary_size] = word;
            dictionary_size++;
        }

        // Initialize.
        for (int i = 0; i < dictionary_size; i++)
        {
            for (int j = 0; j < dictionary_size; j++)
            {
                if (i != j)
                {
                    T[i][j] = INFINITY_WEIGHT;
                }
            }
        }

        for (int i = 0; i < dictionary_size; i++)
        {
            for (int j = i+1; j < dictionary_size; j++)
            {
                if (HasTransformation(word_id_map[i], word_id_map[j]))
                {
                    T[i][j] = 1;
                    T[j][i] = 1;
                }
            }
        }

        // Floyd-Warshall algorithm.
        // The graph is quite small (|V| = 200), and thus constructing 
        // all shortest paths for O(1) query is good for this problem.
        for (int k = 0; k < dictionary_size; k++)
        {
            for (int i = 0; i < dictionary_size; i++)
            {
                for (int j = 0; j < dictionary_size; j++)
                {
                    T[i][j] = minimum(T[i][j], T[i][k] + T[k][j]);
                }
            }
        }

        // Query.
        getchar();
        std::string query;
        while (getline(std::cin, query) && query.size())
        {
            unsigned int found = query.find_first_of(" ");
            std::string word[2] = {
                query.substr(0, found), query.substr(found + 1)
            };
            printf("%s %d\n", 
                query.c_str(), 
                T[word_map[word[0]]][word_map[word[1]]]);
        }
    }

    return 0;
}