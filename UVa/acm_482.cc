#include <iterator>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

std::vector<int> GetPermutationArray(const std::string& buffer)
{
    std::stringstream builder(buffer);
    std::istream_iterator<int> it(builder);
    std::istream_iterator<int> end;
    return std::vector<int>(it, end);
}

std::vector<std::string> GetNumberList(const std::string& buffer)
{
    std::stringstream builder(buffer);
    std::istream_iterator<std::string> it(builder);
    std::istream_iterator<std::string> end;
    return std::vector<std::string>(it, end);
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();

    std::string buffer;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }
        getline(std::cin, buffer);
        getline(std::cin, buffer);
        std::vector<int> permutation_array = GetPermutationArray(buffer);

        std::map<int, int> inverse_permutation_array;
        int length = permutation_array.size();
        for (int i = 0; i < length; i++)
        {
            inverse_permutation_array[permutation_array[i] - 1] = i;
        }

        getline(std::cin, buffer);
        std::vector<std::string> number_list = GetNumberList(buffer);
        for (int i = 0; i < length; i++)
        {
            printf("%s\n", number_list[inverse_permutation_array[i]].c_str());
        }
    }
    return 0;
}