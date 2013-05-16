#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::string one("one");
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string word;
        std::cin >> word;
        if (word.size() == 5)
        {
            std::cout << "3" << std::endl;
        }
        else 
        {
            int matching_one_count = 0;
            for (int j = 0; j < 3; j++)
            {
                if (word[j] == one[j])
                {
                    matching_one_count++;
                }
            }
            if (matching_one_count >= 2)
            {
                std::cout << "1" << std::endl;
            }
            else
            {
                std::cout << "2" << std::endl;
            }
        }
    }

    return 0;
}
