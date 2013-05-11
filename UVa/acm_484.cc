#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::map<int, int> number_occurences;
    std::vector<int> number_debut_list;
    int curr_num;
    while (std::cin >> curr_num)
    {
        if (number_occurences.find(curr_num) == number_occurences.end())
        {
            number_debut_list.push_back(curr_num);
            number_occurences[curr_num] = 0;
        }
        number_occurences[curr_num]++;
    }

    for (unsigned int i = 0; i < number_debut_list.size(); i++)
    {
        int num = number_debut_list[i];
        std::cout << num << " " << number_occurences[num] << std::endl;
    }

    return 0;
}