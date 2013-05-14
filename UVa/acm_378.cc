// Reference: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=geometry2

#include <iostream>
#include <math.h>
#include <stdio.h>

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

    static double cross(const Point& a, const Point& b, const Point& c)
    {
        // We reuse |Point| as a vector.
        Point ab(b.x - a.x, b.y - a.y);
        Point ac(c.x - a.x, c.y - a.y);
        return ab.x * ac.y - ab.y * ac.x;
    }
};

struct Line
{
    Point begin;
    Point end;

    // Line equation: Ax + By = C
    double A;
    double B;
    double C;

    Line() 
    { 
        A = 0.0; 
        B = 0.0; 
        C = 0.0; 
    }

    Line(double x1, double y1, double x2, double y2)
    {
        begin.x = x1;
        begin.y = y1;
        end.x = x2;
        end.y = y2;
        A = y2 - y1;
        B = x1 - x2;
        C = A * x1 + B * y1;
    }
};

struct LineIntersectionQuery
{
    enum Status
    {
        UNKNOWN,
        NONE, 
        LINE,
        POINT,
    };

    LineIntersectionQuery(const Line& one, const Line& another)
    {
        line[0] = one;
        line[1] = another;
        status_ = UNKNOWN;
    }
    
    Status status() { return status_; }
    Point point() { return point_; }

    void exec()
    {
        double det = line[0].A * line[1].B - line[1].A * line[0].B;
        if (det == 0.0)
        {
            double area = Point::cross(line[0].begin, line[0].end, line[1].begin);
            if (area == 0.0)
            {
                status_ = LINE;
            }
            else
            {
                status_ = NONE;
            }
        }   
        else
        {
            status_ = POINT;
            point_.x = (line[1].B * line[0].C - line[0].B * line[1].C) / det;
            point_.y = (line[0].A * line[1].C - line[1].A * line[0].C) / det;
        }
    }

    void print_result()
    {
        switch (status_)
        {
        case NONE:
            printf("NONE\n");
            break;
        case LINE:
            printf("LINE\n");
            break;
        case POINT:
            printf("POINT %.2lf %.2lf\n", point_.x, point_.y);
            break;
        default:
            break;
        }
    }

    Line line[2];
    Status status_;
    Point point_;
};

int main(int argc, char* argv[])
{
    int N; // describing how many pairs of lines are represented
    std::cin >> N;

    printf("INTERSECTING LINES OUTPUT\n");

    double c[4];
    for (int n = 0; n < N; n++)
    {
        std::cin >> c[0] >> c[1] >> c[2] >> c[3];
        Line one(c[0], c[1], c[2], c[3]);

        std::cin >> c[0] >> c[1] >> c[2] >> c[3];
        Line another(c[0], c[1], c[2], c[3]);

        LineIntersectionQuery query(one, another);
        query.exec();
        query.print_result();
    }

    printf("END OF OUTPUT\n");

    return 0;
}