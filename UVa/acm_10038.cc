#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

inline int get_absolute_value(int num)
{
    return (num < 0) ? -num : num;
}

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n) 
    {
        bool is_first_num = true;
        int prev_num = 0;
        int curr_num = 0;
        std::vector<int> diff_set;
        for (int i = 0; i < n; i++)
        {
            std::cin >> curr_num;
            if (is_first_num)
            {
                is_first_num = false;
            }
            else
            {
                int diff = get_absolute_value(curr_num - prev_num);
                diff_set.push_back(diff);
            }
            prev_num = curr_num;
        }

        std::sort(diff_set.begin(), diff_set.end());

        // After we sort |diff_set|, it should be 1, 2, ..., n-1 when the 
        // sequence is jolly.  T(n) = O(n log(n)).
        bool is_jolly = true;
        for (int i = 0; i < n-1; i++)
        {
            if (diff_set[i] != (i+1))
            {
                is_jolly = false;
                break;
            }
        }

        if (is_jolly)
        {
            std::cout << "Jolly" << std::endl;
        }
        else
        {
            std::cout << "Not jolly" << std::endl;
        }
    }
    return 0;
}
