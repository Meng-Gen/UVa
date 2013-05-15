#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))

// Let r be the radius of circumscribed circle of n-regular polygon.
// The area of n-regular polygon is 1/2 nr^2 sin(2PI/n).
//                                  ^^^^^^^^^^^^^^^^^^^
// Our task is to find out r.
//
// Let R be the distance between two points A and B.
// If n is even, r is easy to get: r = R/2.
// If n is odd, we can apply sine theorem on the triangle OAB, where O is the
// center of circumscribed circle.  Angle AOB = (2PI/n) * (n-1)/2 = (n-1)PI/n.
// Angle OAB = Angle OBA = PI/(2n).  So R/sin((n-1)PI/n) = r/sin(PI/(2n)).
//
// In the implementation, we compute r^2 in terms of R^2.  
// We don't need |sqrt| function.
int main(int argc, char* argv[])
{
    int xA;
    int yA; 
    int xB; 
    int yB;
    int n;
    while (1)
    {
        std::cin >> xA >> yA >> xB >> yB >> n;
        if (xA == 0 && yA == 0 && xB == 0 && yB == 0 && n == 0)
        {
            break;
        }
        double dx = (double)(xA - xB);
        double dy = (double)(yA - yB);
        double d_square = dx*dx + dy*dy;
        double area = (double)n * sin(2*PI / (double)n) * d_square;
        if (n % 2 == 0) 
        {
            area *= 0.125;
        }
        else
        {
            double r_factor = sin(0.5 * PI / (double)n);
            r_factor /= sin(PI * (double)(n-1) / (double)n);           
            area *= 0.5 * r_factor * r_factor;
        }
        printf("%.6lf\n", area);
    }

    return 0;
}