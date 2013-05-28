#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[])
{
    bool is_first_dataset = true;
    int num_people;
    while (std::cin >> num_people)
    {
        if (!is_first_dataset)
        {
            putchar('\n');
        }
        else 
        {
            is_first_dataset = false;
        }

        std::vector<std::string> people_name;
        std::map<std::string, int> revenue;
        for (int i = 0; i < num_people; i++)
        {
            std::string name;
            std::cin >> name;
            people_name.push_back(name);
        }
        for (int i = 0; i < num_people; i++)
        {
            std::string person;
            std::cin >> person;

            int money;
            std::cin >> money;
            
            int to_whom_count;
            std::cin >> to_whom_count;
            if (to_whom_count == 0) 
            {
                continue;
            }
            revenue[person] -= (money/to_whom_count * to_whom_count);

            std::string to_whom;
            for (int j = 0; j < to_whom_count; j++)
            {
                std::cin >> to_whom;
                revenue[to_whom] += (money/to_whom_count);
            }
        }

        for (unsigned int i = 0; i < num_people; i++)
        {
            std::string person = people_name[i];
            std::cout << person << " " << revenue[person] << std::endl;
        }
    }

    return 0;
}