#include <iostream>
#include <math.h>
#include <stdio.h>

struct Point 
{
    int x_;
    int y_;

    Point() : x_(0), y_(0) { }

    static double distance(const Point& a, const Point&b)
    {
        int dx = a.x_ - b.x_;
        int dy = a.y_ - b.y_;
        return sqrt((double)(dx*dx + dy*dy));
    }

    static int distance2(const Point& a, const Point&b)
    {
        int dx = a.x_ - b.x_;
        int dy = a.y_ - b.y_;
        return dx*dx + dy*dy;
    }
};

double maximum(double a, double b)
{
    return (a > b) ? a : b;
}

Point V[101];
int N;

double good_circumscribed_circle_radius(int i, int j, int k)
{
    int a2 = Point::distance2(V[j], V[k]);
    int b2 = Point::distance2(V[k], V[i]);
    int c2 = Point::distance2(V[i], V[j]);
    if ((a2 > b2 + c2) || (b2 > c2 + a2) || (c2 > a2 + b2))
    {
        return 0.0;
    }

    double a = sqrt((double)a2);
    double b = sqrt((double)b2);
    double c = sqrt((double)c2);
    double p = (a+b+c)*0.5;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    return a*b*c / area / 4.0;
}

int main(int argc, char* argv[])
{
    while (std::cin >> N && N)
    {
        // Read input
        for (int i = 0; i < N; i++)
        {
            std::cin >> V[i].x_ >> V[i].y_;
        }
        double radius;
        std::cin >> radius;

        // Fit any segments
        double max_covering_radius = 0.0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                double d = Point::distance(V[i], V[j]) * 0.5;
                max_covering_radius = maximum(max_covering_radius, d);
            }
        }

        // Fit any acute or right triangle
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                for (int k = j+1; k < N; k++)
                {
                    double r = good_circumscribed_circle_radius(i, j, k);
                    max_covering_radius = maximum(max_covering_radius, r);
                }
            }
        } 

        // Output here
        if (radius >= max_covering_radius)
        {
            puts("The polygon can be packed in the circle.");
        }
        else
        {
            puts("There is no way of packing that polygon.");
        }
    }

    return 0;
}