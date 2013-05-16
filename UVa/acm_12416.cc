#include <iostream>
#include <string>
#include <stdio.h>

inline int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(int argc, char* argv[])
{
    std::string buffer;
    while (getline(std::cin, buffer))
    {
        int max_space = 0;
        int max_space_so_far = 0;
        for (unsigned int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i] == ' ')
            {
                max_space_so_far++;
            }
            else
            {
                max_space = get_max(max_space, max_space_so_far);
                max_space_so_far = 0;
            }
        }
        max_space = get_max(max_space, max_space_so_far);
        if (max_space <= 1)
        {
            std::cout << "0" << std::endl;
            continue;
        }

        int rv = 0;
        int P = max_space;
        for (; P > 0; P >>= 1)
        {
            rv++;
        }
        if (!(max_space & (max_space - 1)))
        {
            rv--;
        }
        std::cout << rv << std::endl;
    }
    return 0;
}