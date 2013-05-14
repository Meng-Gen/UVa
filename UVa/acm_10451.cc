#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (2.0*acos(0.0))

int main(int argc, char* argv[])
{
    int n;
    double A;
    int case_id = 1;
    while (1)
    {
        std::cin >> n >> A;
        if (n < 3)
        {
            break;
        }

        double polygon_unit_area = 0.5 * (double)n * sin(2.0 * PI / (double)n);
        double incircle_unit_area = sin((double)(n - 2)/(double)(2 * n) * PI);
        incircle_unit_area *= incircle_unit_area;
        incircle_unit_area *= PI;
        double spectators_area = (PI / polygon_unit_area - 1.0) * A;
        double officials_area = (1.0 - incircle_unit_area / polygon_unit_area) * A;

        printf("Case %d: %.5lf %.5lf\n", case_id, spectators_area, officials_area);

        case_id++;
    }

    return 0;
}