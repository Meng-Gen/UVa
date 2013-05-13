// Check a^2 = b^2 + c^2.
#include <algorithm>
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long side[3];
    while (std::cin >> side[0] >> side[1] >> side[2])
    {
        if (side[0] == 0 && side[1] == 0 && side[2] == 0)
        {
            break;
        }

        // Overkilled.
        std::sort(side, side + 3);
        if (side[2] * side[2] == side[0] * side[0] + side[1] * side[1])
        {
            std::cout << "right" << std::endl;
        }
        else
        {
            std::cout << "wrong" << std::endl;
        }
    }

    return 0;
}