#include <iostream>
#include <stdio.h>

inline long long minimum(long long a, long long b)
{
    return (a < b) ? a : b;
}

inline long long maximum(long long a, long long b)
{
    return (a > b) ? a : b;
}

struct Point 
{
    long long x;
    long long y;

    Point() : x(0), y(0) { }
    Point(long long new_x, long long new_y) : x(new_x), y(new_y) { }
};

long long Direction(const Point& pi, const Point& pj, const Point& pk)
{
    Point pki(pk.x - pi.x, pk.y - pi.y);
    Point pji(pj.x - pi.x, pj.y - pi.y);
    return pki.x * pji.y - pji.x * pki.y;
}

bool OnSegment(const Point& pi, const Point& pj, const Point& pk)
{
    return (minimum(pi.x, pj.x) <= pk.x) && (pk.x <= maximum(pi.x, pj.x))
        && (minimum(pi.y, pj.y) <= pk.y) && (pk.y <= maximum(pi.y, pj.y));
}

bool SegmentsIntersect(
    const Point& p1, const Point& p2, 
    const Point& p3, const Point& p4)
{
    long long d1 = Direction(p3, p4, p1);
    long long d2 = Direction(p3, p4, p2);
    long long d3 = Direction(p1, p2, p3);
    long long d4 = Direction(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    {
        return true;
    }
    else if ((d1 == 0) && OnSegment(p3, p4, p1))
    {
        return true;
    }
    else if ((d2 == 0) && OnSegment(p3, p4, p2))
    {
        return true;
    }
    else if ((d3 == 0) && OnSegment(p1, p2, p3))
    {
        return true;
    }
    else if ((d4 == 0) && OnSegment(p1, p2, p4))
    {
        return true;
    }
    return false;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        Point start;
        Point end;
        Point left_top;
        Point right_bottom;
        std::cin >> start.x >> start.y >> end.x >> end.y >> 
            left_top.x >> left_top.y >> right_bottom.x >> right_bottom.y;
        
        Point right_top(right_bottom.x, left_top.y);
        Point left_bottom(left_top.x, right_bottom.y);

        // Rectangle = four straight lines + the area in between.
        //             ^^^^^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^^
        // I got a lot of WA because of ``the area''
        if (OnSegment(left_top, right_bottom, start) 
            || OnSegment(left_top, right_bottom, end))
        {
            puts("T");
        }
        else if (SegmentsIntersect(start, end, left_top, right_top)
            || SegmentsIntersect(start, end, right_top, right_bottom)
            || SegmentsIntersect(start, end, right_bottom, left_bottom)
            || SegmentsIntersect(start, end, left_bottom, left_top))
        {
            puts("T");
        }
        else
        {
            puts("F");
        }
    }

    return 0;
}