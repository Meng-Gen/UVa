#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int N;
    while (std::cin >> N)
    {
        int enjoy_bottles = 0;
        int curr_bottles = N;
        int empty_bottles = 0;
        while (curr_bottles > 0)
        {
            enjoy_bottles += curr_bottles;
            empty_bottles += curr_bottles;
            curr_bottles = empty_bottles / 3;
            empty_bottles %= 3;
        }

        if (empty_bottles == 2)
        {
            enjoy_bottles++;
        }
        printf("%d\n", enjoy_bottles);
    }

    return 0;
}