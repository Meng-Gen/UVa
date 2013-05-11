//  By problem, 
//      You may assume that input is given in such that the corners will always 
//      be in integer coordinates.
//
//  So, we might find a minimum flag of integer coordinates.
//      Input: 
//      4
//      Output:
//      -9 6
//      11 6
//      11 -6
//      -9 -6
//
//  Then the rest is easy.
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int T; // number of test cases
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int R; // the radius of the circle
        std::cin >> R;

        int factor = R / 4;
        printf("Case %d:\n", t);
        printf("%d %d\n", -9 * factor, 6 * factor);
        printf("%d %d\n", 11 * factor, 6 * factor);
        printf("%d %d\n", 11 * factor, -6 * factor);
        printf("%d %d\n", -9 * factor, -6 * factor);
    }

    return 0;
}