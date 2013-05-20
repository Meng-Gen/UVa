#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

bool compare(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return lhs.size() < rhs.size();
    }
    return lhs.compare(rhs) < 0;
}

int main(int argc, char* argv[])
{
    std::string code;
    std::vector<std::string> code_set;

    int set_id = 1;
    while (std::cin >> code)
    {
        if (code == "9") 
        {
            sort(code_set.begin(), code_set.end(), compare);

            bool is_decodable = true;
            for (int i = 0; i != code_set.size(); i++)
            {
                for (int j = i+1; j != code_set.size(); j++)
                {
                    if (code_set[j].substr(0, code_set[i].size()) == code_set[i])
                    {
                        is_decodable = false;
                        break;
                    }
                }
                if (!is_decodable)
                {
                    break;
                }
            }

            if (is_decodable)
            {
                printf("Set %d is immediately decodable\n", set_id);
            }
            else
            {
                printf("Set %d is not immediately decodable\n", set_id);
            }
            code_set.clear();
            set_id++;
        }
        else 
        {
            code_set.push_back(code);
        }
    }

    return 0;
}