#include <iostream>
#include <stdio.h>

inline int Norm(int a)
{
    return (a < 0) ? -a : a;
}

// Euclidean Algorithm
int GetGCD(int a, int b) {
    while (b) {
        int t = b;
        b = a % t;
        a = t;
    }
    return a;
}

// -----------------------------------------------------------------------------

struct Point
{
    int x;
    int y;

    bool IsLatticePoint() const
    {
        return (x % 10 == 0) && (y % 10 == 0);
    }
};

Point p[2];

void ReadPoints()
{
    int integer_part;
    int decimal_part;
    char decimal_point;

    for (int i = 0; i < 2; i++)
    {
        std::cin >> integer_part >> decimal_point >> decimal_part;
        p[i].x = integer_part * 10 + decimal_part;
        
        std::cin >> integer_part >> decimal_point >> decimal_part;
        p[i].y = integer_part * 10 + decimal_part;
    }
}

// x = x_1 + (x_2 - x_1) t
// y = y_1 + (y_2 - y_1) t 
int NumLatticePoints()
{
    int num = 0;
    Point solution;
    int dx = p[1].x - p[0].x;
    int dy = p[1].y - p[0].y;
    int gcd = GetGCD(Norm(dx), Norm(dy));

    for (int i = 0; i <= gcd; i++)
    {
        solution.x = p[0].x + dx / gcd * i;
        solution.y = p[0].y + dy / gcd * i;
        if (solution.IsLatticePoint())
        {
            num++;
        }
    }
    return num;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        ReadPoints();
        printf("%d\n", NumLatticePoints());
    }
    return 0;
}