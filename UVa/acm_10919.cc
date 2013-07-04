#include <iostream>
#include <set>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_courses;
    int num_categories;
    int num_courses_in_category;
    int min_courses_in_category;
    int buffer;

    while (std::cin >> num_courses && num_courses)
    {
        std::cin >> num_categories;
        std::set<int> courses;
        for (int i = 0; i < num_courses; i++)
        {
            std::cin >> buffer;
            courses.insert(buffer);
        }

        bool has_met_requirements = true;
        for (int i = 0; i < num_categories; i++)
        {
            int num_selected = 0;
            std::cin >> num_courses_in_category >> min_courses_in_category;
            for (int j = 0; j < num_courses_in_category; j++)
            {
                std::cin >> buffer;
                if (courses.find(buffer) != courses.end())
                {
                    num_selected++;
                }
            }
            if (min_courses_in_category > num_selected)
            {
                has_met_requirements = false;
            }
        }

        if (has_met_requirements)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }

    return 0;
}