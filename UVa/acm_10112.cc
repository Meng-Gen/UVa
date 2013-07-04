#include <algorithm>
#include <iostream>
#include <stdio.h>

int norm(int a) 
{
    return (a < 0) ? -a : a;
}

// -----------------------------------------------------------------------------

inline bool IsInRange(int value, int lower_limit, int higher_limit) 
{
    if (lower_limit > higher_limit)
    {
        int temp = lower_limit;
        lower_limit = higher_limit;
        higher_limit = temp;
    }
    return (lower_limit < value) && (value < higher_limit);
}

struct Point
{
    char label;
    int x;
    int y;

    Point() : label(0), x(0), y(0) { }
    Point(int some_x, int some_y) : label(0), x(some_x), y(some_y) { }

    bool operator < (const Point& other) const 
    {
        return label < other.label;
    }

    static int Cross(const Point& a, const Point& b, const Point& c)
    {
        // We reuse |Point| as a vector.
        Point ab(b.x - a.x, b.y - a.y);
        Point ac(c.x - a.x, c.y - a.y);
        return ab.x * ac.y - ab.y * ac.x;
    }
};

// -----------------------------------------------------------------------------

int N;
Point point[15];

bool Contains(int i, int j, int k)
{
    int cross[3];
    for (int t = 0; t < N; t++)
    {
        if (t == i || t == j || t == k)
        {
            continue;
        }

        cross[0] = Point::Cross(point[j], point[k], point[t]);
        cross[1] = Point::Cross(point[k], point[i], point[t]);
        cross[2] = Point::Cross(point[i], point[j], point[t]);
        
        int num_positive_sign = 0;
        int num_negative_sign = 0;
        for (int s = 0; s < 3; s++)
        {
            if (cross[s] > 0)
            {
                num_positive_sign++;
            }
            else if (cross[s] < 0)
            {
                num_negative_sign++;
            }
        }
        if (num_positive_sign == 3 || num_negative_sign == 3)
        {
            return true;
        }

        if (cross[0] == 0 && IsInRange(point[t].x, point[j].x, point[k].x))
        {
            return true;
        }
        if (cross[1] == 0 && IsInRange(point[t].x, point[k].x, point[i].x))
        {
            return true;
        }
        if (cross[2] == 0 && IsInRange(point[t].x, point[i].x, point[j].x))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    while (std::cin >> N && N)
    {
        for (int i = 0; i < N; i++)
        {
            std::cin >> point[i].label >> point[i].x >> point[i].y;
        }
        
        std::sort(point, point + N);
        int max_double_area = -1;
        int max_triangle_point[3] = {};
        int double_area;
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                for (int k = j+1; k < N; k++)
                {
                    if (!Contains(i, j, k))
                    {
                        double_area = 
                            norm(Point::Cross(point[i], point[j], point[k]));
                        if (double_area > max_double_area)
                        {
                            max_double_area = double_area;
                            max_triangle_point[0] = i;
                            max_triangle_point[1] = j;
                            max_triangle_point[2] = k;
                        }
                    }
                }
            }
        }

        printf("%c%c%c\n", 
            point[max_triangle_point[0]].label,
            point[max_triangle_point[1]].label,
            point[max_triangle_point[2]].label);
    }

    return 0;
}