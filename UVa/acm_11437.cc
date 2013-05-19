// [PQR] = [ABC] / 7
// ^^^^^^^^^^^^^^^^^
// Draw a line L passing point F and paralleling BC.  
// Let point G be the intersection point of L and AD.
//
// (1) In triangle ABD, FG = BD / 3.
// (2) Point D divides BC into ration 1 : 2 respectively.  BD = CD / 2.
// By (1)(2), FG = CD / 6
// (3) In triangle FGR and CDR, FG = CD / 6 <=> FR = CR / 6.
// So, CR / CF = 6/7.
// (4) In trianlge ACF and ACR, [ACR] = 6/7 * [ACF]. 
// Note that [ACF] = [ABC] / 3.  Therefore, [ACR] = 2/7 * [ABC]
//                                          ^^^^^^^^^^^^^^^^^^^
// Similarly, [BCQ] = [ABP] = 2/7 * [ABC].
// So [PQR] = [ABC] - [ABP] - [BCQ] - [ACR] = 1/7 * [ABC].
//    ^^^^^                                 ^^^^^^^^^^^^^

#include <iostream>
#include <math.h>
#include <stdio.h>

inline double det 
(
    double a, double b, double c,
    double d, double e, double f,
    double g, double h, double i
) 
{
    return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
}

struct Point 
{
    double x;
    double y;
};

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N; // denotes how many sets of inputs are there
    for (int i = 0; i < N; i++)
    {
        Point p[3];
        std::cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;

        double area = 0.5 *
            det(p[0].x, p[1].x, p[2].x, p[0].y, p[1].y, p[2].y, 1, 1, 1);
        area = fabs(area) / 7.0;
        std::cout << (int)(area + 0.5) << std::endl;
    }

    return 0;
}