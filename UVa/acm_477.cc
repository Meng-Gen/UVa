#include <iostream>
#include <vector>
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

    bool IsIn(const Point& point)
    {   
        return IsInRange(point.x, corners[0].x, corners[1].x)
            && IsInRange(point.y, corners[0].y, corners[1].y);
    }
};

struct Circle
{
    Point center;
    double radius;

    bool IsIn(const Point& point)
    {
        double dx = center.x - point.x;
        double dy = center.y - point.y;
        return dx*dx + dy*dy < radius*radius;
    }
};

int main(int argc, char* argv[])
{
    // Maybe we can design a base class |Shape| with a pure virual function 
    // virual bool IsIn(const Point& point) = 0;
    Rectangle rectangles[11];
    Circle circles[11];
    char shape_types[11];

    int shape_id = 0;
    char command;
    while (1)
    {
        std::cin >> command;
        if (command == 'r')
        {
            std::cin >> rectangles[shape_id].corners[0].x
                >> rectangles[shape_id].corners[0].y
                >> rectangles[shape_id].corners[1].x
                >> rectangles[shape_id].corners[1].y;
            shape_types[shape_id] = command;
            shape_id++;
        }
        else if (command == 'c')
        {
            std::cin >> circles[shape_id].center.x 
                >> circles[shape_id].center.y
                >> circles[shape_id].radius;
            shape_types[shape_id] = command;
            shape_id++;
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
        for (int i = 0; i < shape_id; i++)
        {
            if (shape_types[i] == 'r' && rectangles[i].IsIn(point))
            {
                is_contained = true;
                printf("Point %d is contained in figure %d\n", point_id, i + 1);
            }
            else if (shape_types[i] == 'c' && circles[i].IsIn(point))
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