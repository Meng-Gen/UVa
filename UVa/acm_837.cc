#include <algorithm>
#include <iostream>
#include <stdio.h>

struct Point 
{
    double x;
    double y;
};

struct Segment
{
    Point point[2];
    double transparency;

    void Normalize()
    {
        if (point[0].x > point[1].x)
        {
            double temp = point[0].x;
            point[0].x = point[1].x;
            point[1].x = temp;
        }
    }
};

Segment segments[100];
double end_points[200];
double x[200];

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }
        
        int num_segments;
        std::cin >> num_segments;

        // Deal with special case
        if (num_segments == 0)
        {
            puts("1");
            puts("-inf +inf 1.000");
            continue;
        }

        // Read segments
        for (int i = 0; i < num_segments; i++)
        {
            std::cin >> segments[i].point[0].x >> segments[i].point[0].y
                >> segments[i].point[1].x >> segments[i].point[1].y
                >> segments[i].transparency;
            end_points[i*2] = segments[i].point[0].x;
            end_points[i*2+1] = segments[i].point[1].x;
            segments[i].Normalize();
        }

        // Sort and remove duplicated end-points.
        std::sort(end_points, end_points + num_segments*2);
        int curr_pos = 0;
        x[0] = end_points[0];
        for (int i = 1; i < num_segments*2; i++)
        {
            if (end_points[i] != x[curr_pos])
            {
                curr_pos++;
                x[curr_pos] = end_points[i];
            }
        }

        // Output
        printf("%d\n", curr_pos + 2);
        printf("-inf %.3lf 1.000\n", x[0]);
        for (int i = 0; i < curr_pos; i++)
        {
            double total_transparency = 1.0;
            for (int j = 0; j < num_segments; j++)
            {
                if (segments[j].point[0].x <= x[i] &&
                    x[i+1] <= segments[j].point[1].x)
                {
                    total_transparency *= segments[j].transparency;
                }
            }
            printf("%.3lf %.3lf %.3lf\n", x[i], x[i+1], total_transparency);
        }
        printf("%.3lf +inf 1.000\n", x[curr_pos]);
    }

    return 0;
}