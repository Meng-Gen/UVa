#include <iostream>
#include <math.h>
#include <stdio.h>

// Let O be the center of the circle.  
// Let alpha be the angle OBE.  So sin(alpha) = (r-d) / r.
// Let L be the line passing O and perpendicular to line MN (base) at point F.
// Let beta be the angle BOF.  So cos(beta) = (r-h1) / r.
// So the angle BAC = alpha + beta.  The rest is easy.

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        double r, d, h1;
        std::cin >> r >> d >> h1;
        double alpha = asin((r-d)/r);
        double beta = acos((r-h1)/r);
        double h2 = cos(alpha + beta) * 2.0 * sqrt(2*r*d - d*d) + h1;

        printf("Case %d: %.4lf\n", case_id, h2);
    }

    return 0;
}