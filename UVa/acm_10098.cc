#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        std::string word;
        std::cin >> word;

        sort(word.begin(), word.end());
        do
        {
            std::cout << word << std::endl;
        }
        while (std::next_permutation(word.begin(), word.end()));
        putchar('\n');
    }

    return 0;
}