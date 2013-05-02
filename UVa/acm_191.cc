#include <iostream>
#include <math.h>
#include <stdio.h>

// WA

struct Point 
{
	int x;
	int y;

	Point()
	{ 
		x = 0;
		y = 0;
	}

	Point(const Point& another)
	{
		x = another.x;
		y = another.y;
	}

	Point(int some_x, int some_y)
	{
		x = some_x;
		y = some_y;
	}

	double length()
	{
		return sqrt((double)(x * x + y * y));
	}

	int dot(const Point& another)
	{
		return x * another.x + y * another.y;
	}

	int cross(const Point& another)
	{
		return x * another.y - y * another.x;
	}

	Point operator+ (const Point& another)
	{
		return Point(x + another.x, y + another.y);
	}

	Point operator- (const Point& another)
	{
		return Point(x - another.x, y - another.y);
	}

	bool equals(const Point& another)
	{
		return (x == another.x) && (y == another.y);
	}
};

bool is_in_interval(int start_value, int end_value, double test_value)
{
    if (start_value < end_value)
    {
        return test_value >= start_value && test_value <= end_value;
    }
    else
    {
        return test_value <= start_value && test_value >= end_value;
    }
}

bool is_in_line_segment
	(
		Point line_start,
		Point line_end,
		Point point
	)
{
	if (line_start.equals(line_end))
	{
		return line_start.equals(point);
	}
    Point line_vector = line_end - line_start;
    Point point_vector = point - line_start;
	int cross = line_vector.cross(point_vector);

    if ((point - line_end).dot(line_vector) > 0)
    {
		return point.equals(line_end);
    }
	if ((line_start - point).dot(line_vector) > 0)
    {
		return point.equals(line_start);
    }

    return (cross == 0);
}

bool are_line_segments_intersected
	(
		Point a_start,
		Point a_end,
		Point b_start,
		Point b_end
	)
{
	if (a_start.equals(a_end))
	{
		return is_in_line_segment(b_start, b_end, a_start);
	}
	if (b_start.equals(b_end))
	{
		return is_in_line_segment(a_start, a_end, b_start);
	}

    // Line A representation: ax + by = c
	int a = a_end.y - a_start.y;
    int b = a_start.x - a_end.x;
    int c = a_start.x * a_end.y - a_end.x * a_start.y;

    // Line B representation: dx + ey = f
    int d = b_end.y - b_start.y;
    int e = b_start.x - b_end.x;
    int f = b_start.x * b_end.y - b_end.x * b_start.y;

    int det = a * e - b * d;

    // Design choice: If two lines are identical, we regards that
    // two lines are not intersected.
    if (det == 0)
    {
        return false;
    }

    double x = (double)(c * e - b * f) / (double)det;
    double y = (double)(a * f - c * d) / (double)det;
    
	/*
    if (!is_in_interval(a_start.x, a_end.x, x))
    {
        return false;
    }
    if (!is_in_interval(a_start.y, a_end.y, y))
    {
        return false;
    }
	*/
    if (!is_in_interval(b_start.x, b_end.x, x))
    {
        return false;
    }
    if (!is_in_interval(b_start.y, b_end.y, y))
    {
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
	// n test cases.
    int n;
    while(std::cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
			Point line_start;
			Point line_end;
			Point rect_top_left;
			Point rect_bottom_right;
            std::cin >> 
				line_start.x >> line_start.y >> 
				line_end.x >> line_end.y >> 
				rect_top_left.x >> rect_top_left.y >> 
				rect_bottom_right.x >> rect_bottom_right.y;
			
			int rect_lower_x = rect_top_left.x;
			int rect_upper_x = rect_bottom_right.x;
			if (rect_lower_x > rect_upper_x)
			{
				int temp = rect_lower_x;
				rect_lower_x = rect_upper_x;
				rect_upper_x = temp;
			}

			int rect_lower_y = rect_top_left.y;
			int rect_upper_y = rect_bottom_right.y;
			if (rect_lower_y > rect_upper_y)
			{
				int temp = rect_lower_y;
				rect_lower_y = rect_upper_y;
				rect_upper_y = temp;
			}

			Point rect[4] = 
				{ 
					Point(rect_lower_x, rect_lower_y),
					Point(rect_upper_x, rect_lower_y),
					Point(rect_upper_x, rect_upper_y),
					Point(rect_lower_x, rect_upper_y)
				};

			bool is_intersected = false;
			for (int i = 0; i < 4; i++)
			{
				if (is_in_line_segment(rect[i], rect[(i+1)%4], line_start))
				{
					is_intersected = true;
					break;
				}
				if (is_in_line_segment(rect[i], rect[(i+1)%4], line_end))
				{
					is_intersected = true;
					break;
				}
				if (are_line_segments_intersected(line_start, line_end, rect[i], rect[(i+1)%4]))
				{
					is_intersected = true;
					break;
				}
			}
			if (is_intersected)
			{
				printf("T\n");
			}
			else
			{
				printf("F\n");
			}
        }
    }

    return 0;
}