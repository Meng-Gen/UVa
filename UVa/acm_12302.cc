// https://en.wikipedia.org/wiki/Nine-point_circle

#include <iostream>
#include <math.h>
#include <stdio.h>

inline double Det
(
    double a, double b, double c,
    double d, double e, double f,
    double g, double h, double i
)
{
    return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
}

int main(int argc, char* argv[])
{
    while (1)
    {
        int x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1 && x3 == -1 && y3 == -1)
        {
            break;
        }

        double x[3];
        double y[3];
        x[0] = (double)(x1 + x2) * 0.5;
        x[1] = (double)(x2 + x3) * 0.5;
        x[2] = (double)(x3 + x1) * 0.5;
        y[0] = (double)(y1 + y2) * 0.5;
        y[1] = (double)(y2 + y3) * 0.5;
        y[2] = (double)(y3 + y1) * 0.5;

        double cross = Det(x[0], y[0], 1, x[1], y[1], 1, x[2], y[2], 1);
        double h = Det(
            x[0] * x[0] + y[0] * y[0], y[0], 1,
            x[1] * x[1] + y[1] * y[1], y[1], 1,
            x[2] * x[2] + y[2] * y[2], y[2], 1
        ) / (2.0 * cross);
        double k = Det(
            x[0], x[0] * x[0] + y[0] * y[0], 1,
            x[1], x[1] * x[1] + y[1] * y[1], 1,
            x[2], x[2] * x[2] + y[2] * y[2], 1
        ) / (2.0 * cross);
        double r = sqrt((x[0] - h) * (x[0] - h) + (y[0] - k) * (y[0] - k));

        printf("%.6lf %.6lf %.6lf\n", h, k, r);
    }
    return 0;
}
