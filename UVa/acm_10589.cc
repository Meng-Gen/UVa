#include <iostream>
#include <stdio.h>

struct Point
{
    double x;
    double y;

    Point() 
    {
        x = 0.0;
        y = 0.0;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double NormSquare(const Point& a)
    {
        double dx = a.x - this->x;
        double dy = a.y - this->y;
        return dx*dx + dy*dy;
    }
};

int main(int argc, char* argv[])
{
    int N;
    while (1)
    {
        std::cin >> N;
        if (N == 0)
        {
            break;
        }

        int a;
        std::cin >> a;

        Point A(0.0, 0.0);
        Point B((double)a, 0.0);
        Point C((double)a, (double)a);
        Point D(0.0, (double)a);

        double a_square = (double)(a*a);

        int M = 0;
        for (int n = 0; n < N; n++)
        {
            Point point;
            std::cin >> point.x >> point.y;
            if (point.NormSquare(A) <= a_square 
                && point.NormSquare(B) <= a_square
                && point.NormSquare(C) <= a_square
                && point.NormSquare(D) <= a_square)
            {
                M++;
            }
        }
        double area = (double)M / (double)N * a_square;
        printf("%.5lf\n", area);
    }
    
    return 0;
}