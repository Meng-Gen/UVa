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

    static double Cross(const Point& a, const Point& b, const Point& c)
    {
        // We reuse |Point| as a vector.
        Point ab(b.x - a.x, b.y - a.y);
        Point ac(c.x - a.x, c.y - a.y);
        return ab.x * ac.y - ab.y * ac.x;
    }
};

struct Rectangle
{
    Point corners[2];

    bool Contains(const Point& point)
    {   
        return IsInRange(point.x, corners[0].x, corners[1].x)
            && IsInRange(point.y, corners[0].y, corners[1].y);
    }
};

struct Circle
{
    Point center;
    double radius;

    bool Contains(const Point& point)
    {
        double dx = center.x - point.x;
        double dy = center.y - point.y;
        return dx*dx + dy*dy < radius*radius;
    }
};

struct Triangle
{
    Point corners[3];

    bool Contains(const Point& point)
    {
        double cross[3];
        cross[0] = Point::Cross(corners[1], corners[2], point);
        cross[1] = Point::Cross(corners[2], corners[0], point);
        cross[2] = Point::Cross(corners[0], corners[1], point);
        
        int num_positive_sign = 0;
        int num_negative_sign = 0;
        for (int i = 0; i < 3; i++)
        {
            if (cross[i] > 0)
            {
                num_positive_sign++;
            }
            else if (cross[i] < 0)
            {
                num_negative_sign++;
            }
        }

        return (num_positive_sign == 3 || num_negative_sign == 3);
    }
};

int main(int argc, char* argv[])
{
    Rectangle rectangles[11];
    Circle circles[11];
    Triangle triangles[11];
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
        else if (command == 't')
        {
            std::cin >> triangles[shape_id].corners[0].x 
                >> triangles[shape_id].corners[0].y
                >> triangles[shape_id].corners[1].x 
                >> triangles[shape_id].corners[1].y
                >> triangles[shape_id].corners[2].x 
                >> triangles[shape_id].corners[2].y;
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
            if (shape_types[i] == 'r' && rectangles[i].Contains(point))
            {
                is_contained = true;
                printf("Point %d is contained in figure %d\n", point_id, i + 1);
            }
            else if (shape_types[i] == 'c' && circles[i].Contains(point))
            {
                is_contained = true;
                printf("Point %d is contained in figure %d\n", point_id, i + 1);
            }
            else if (shape_types[i] == 't' && triangles[i].Contains(point))
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