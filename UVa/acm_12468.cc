#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a, b;
    while (std::cin >> a >> b)
    {
        if (a == -1 && b == -1)
        {
            break;
        }

        int diff = a - b;
        if (diff < 0)
        {
            diff = -diff;
        }
        if (diff > 50)
        {
            diff = 100 - diff;
        }
        std::cout << diff << std::endl;
    }

    return 0;
}
