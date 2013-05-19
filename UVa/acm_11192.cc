#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n && n)
    {
        std::string word;
        std::cin >> word;

        int group_size = word.size() / n;
        std::string::iterator it;
        for (it = word.begin(); it != word.end(); it += group_size)
        {
            reverse(it, it + group_size);
        }
        std::cout << word << std::endl;
    }

    return 0;
}