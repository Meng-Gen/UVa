#include <iostream>
#include <vector>
#include <stdio.h>

inline double minimum(double a, double b)
{
    return (a < b) ? a : b;
}

inline double maximum(double a, double b)
{
    return (a > b) ? a : b;
}

struct Point 
{
    double x;
    double y;

    Point() : x(0.0), y(0.0) { }
    Point(double new_x, double new_y) : x(new_x), y(new_y) { }
};

double Direction(const Point& pi, const Point& pj, const Point& pk)
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
    double d1 = Direction(p3, p4, p1);
    double d2 = Direction(p3, p4, p2);
    double d3 = Direction(p1, p2, p3);
    double d4 = Direction(p1, p2, p4);

    if (((d1 > 0.0 && d2 < 0.0) || (d1 < 0.0 && d2 > 0.0)) &&
        ((d3 > 0.0 && d4 < 0.0) || (d3 < 0.0 && d4 > 0.0)))
    {
        return true;
    }
    else if ((d1 == 0.0) && OnSegment(p3, p4, p1))
    {
        return true;
    }
    else if ((d2 == 0.0) && OnSegment(p3, p4, p2))
    {
        return true;
    }
    else if ((d3 == 0.0) && OnSegment(p1, p2, p3))
    {
        return true;
    }
    else if ((d4 == 0.0) && OnSegment(p1, p2, p4))
    {
        return true;
    }
    return false;
}

// -----------------------------------------------------------------------------

struct Segment
{
    Point start;
    Point end;
};

bool SegmentsIntersect(const Segment& s1, const Segment& s2)
{
    return SegmentsIntersect(s1.start, s1.end, s2.start, s2.end);
}

// -----------------------------------------------------------------------------

Segment sticks[100002];

int main(int argc, char* argv[])
{
    int num_sticks;
    while (std::cin >> num_sticks && num_sticks)
    {
        for (int i = 0; i < num_sticks; i++)
        {
            std::cin >> sticks[i].start.x >> sticks[i].start.y >> 
                sticks[i].end.x >> sticks[i].end.y;
        }

        std::vector<int> top_sticks;
        for (int i = 0; i < num_sticks; i++)
        {
            bool is_isolated = true;
            for (int j = i+1; j < num_sticks; j++)
            {
                if (SegmentsIntersect(sticks[i], sticks[j]))
                {
                    is_isolated = false;
                    break;
                }
            }

            if (is_isolated)
            {
                // 1-based
                top_sticks.push_back(i + 1);
            }
        }
        
        printf("Top sticks: ");
        int top_sticks_count = top_sticks.size();
        for (int i = 0; i < top_sticks_count; i++)
        {
            printf("%d", top_sticks[i]);
            if (i != top_sticks_count - 1)
            {
                printf(", ");
            }
            else
            {
                printf(".\n");
            }
        }
    }

    return 0;
}