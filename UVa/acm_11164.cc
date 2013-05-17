// Connect the line segment AX and quadrilateral AEXF is divided into
// two pieces: triangle AEX and triangle AFX.
// 
// Let x = [AEX], area of triangle AEX; y = [AFX], area of triangle AFX.
// 
// (1) On the line segment BE:
// [ABX] : [AEX] = BX : EX = [CBX] : [CEX]
// <=> (a+y) : x = b : c <=> bx = c(a+y).
//
// (2) On the line segment CF:
// [AFX] : [ACX] = FX : CX = [BFX] : [BCX]
// <=> y : (c+x) = a : b <=> by = a(c+x).
//
// By (1)(2), solve x and y in terms of a, b, c.  
// The result will be x+y = ac(a+2b+c)/(b^2 - ac) if b^2 - ac > 0.  
//
// Note that a and c are symmetric.  So if we exchange a and c, 
// the result will not be changed (sanity check).

#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    double a;
    double b;
    double c;

    int set_id = 1;
    while (std::cin >> a >> b >> c)
    {
        if (a == -1.0)
        {
            break;
        }

        printf("Set %d:\n", set_id);
        if (b*b <= a*c)
        {
            printf("Poor King!\n");
        }
        else
        {
            double d = a*c*(a + 2*b + c)/(b*b - a*c);
            printf("%.4lf\n", d);
        }
        set_id++;
    }
    
    return 0;
}