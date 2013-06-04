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

Segment segments[102];

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        int num_segments;
        std::cin >> num_segments;
        for (int i = 0; i < num_segments; i++)
        {
            std::cin >> segments[i].start.x >> segments[i].start.y >> 
                segments[i].end.x >> segments[i].end.y;
        }

        // Lazy with T(N) = N^2.
        // We may use disjoint-set forests data structure.
        int isolated_count = 0;
        for (int i = 0; i < num_segments; i++)
        {
            bool is_isolated = true;
            for (int j = 0; j < num_segments; j++)
            {
                if ((i != j) && SegmentsIntersect(segments[i], segments[j]))
                {
                    is_isolated = false;
                    break;
                }
            }

            if (is_isolated)
            {
                isolated_count++;
            }
        }
        printf("%d\n", isolated_count);
    }

    return 0;
}