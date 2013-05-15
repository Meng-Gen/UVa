#include <iostream>
#include <stdio.h>

inline bool IsInRange(double value, double lower_limit, double higher_limit) 
{
    if (lower_limit > higher_limit)
    {
        double temp = lower_limit;
        lower_limit = higher_limit;
        higher_limit = temp;
    }
    return (lower_limit < value) && (value < higher_limit);
}

struct Point
{
    double x;
    double y;
};

struct Rectangle
{
    Point corners[2];

    bool IsInRectangle(const Point& point)
    {   
        return IsInRange(point.x, corners[0].x, corners[1].x)
            && IsInRange(point.y, corners[0].y, corners[1].y);
    }
};

int main(int argc, char* argv[])
{
    Rectangle rectangles[11];
    int rectangle_id = 0;
    char command;
    while (1)
    {
        std::cin >> command;
        if (command == 'r')
        {
            std::cin >> rectangles[rectangle_id].corners[0].x
                >> rectangles[rectangle_id].corners[0].y
                >> rectangles[rectangle_id].corners[1].x
                >> rectangles[rectangle_id].corners[1].y;
            rectangle_id++;
        }
        else if (command == '*')
        {
            break;
        }
    }

    Point point;
    int point_id = 1;
    while (1)
    {
        std::cin >> point.x >> point.y;
        if (point.x == 9999.9 && point.y == 9999.9)
        {
            break;
        }

        bool is_contained = false;
        for (int i = 0; i < rectangle_id; i++)
        {
            if (rectangles[i].IsInRectangle(point))
            {
                is_contained = true;
                printf("Point %d is contained in figure %d\n", point_id, i + 1);
            }
        }
        if (!is_contained)
        {
            printf("Point %d is not contained in any figure\n", point_id);
        }

        point_id++;
    }

    return 0;
}