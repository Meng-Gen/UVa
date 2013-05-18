#include <iostream>
#include <stdio.h>

struct Point 
{
    int x;
    int y;

    Point ()
    {
        x = 0;
        y = 0;
    }

    // Distance from the origin (0, 0)
    inline int Distance()
    {
        return ((x + y) * (x + y + 1)) / 2 + x;
    }
};

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        Point point[2];
        std::cin >> point[0].x >> point[0].y >> point[1].x >> point[1].y;        
        printf("Case %d: %d\n", i, point[1].Distance() - point[0].Distance());
    }

    return 0;
}