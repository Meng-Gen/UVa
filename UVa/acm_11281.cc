#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

double hole_diameter[101] = {};

struct Triangle
{
    double a;
    double b;
    double c;

    double GetCoveringCircleDiameter()
    {
        // If obtuse, returns the longest side of the triangle.  
        if (a*a > b*b + c*c)
        {
            return a;
        }
        else if (b*b > c*c + a*a)
        {
            return b;
        }
        else if (c*c > a*a + b*b)
        {
            return c;
        }

        // Otherwise returns the diameter of the circumscribed circle.
        double p = (a+b+c)*0.5;
        double area = sqrt(p*(p-a)*(p-b)*(p-c));
        double R = a*b*c / area / 4.0;
        return 2 * R;
    }
};

int main(int argc, char* argv[])
{
    int M; // the number of holes
    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        std::cin >> hole_diameter[i];
    }

    int N; // the number of pegs
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        Triangle t;
        std::cin >> t.a >> t.b >> t.c;

        double triangle_diameter = t.GetCoveringCircleDiameter();

        std::vector<int> fit_holes;
        for (int j = 0; j < M; j++)
        {
            if (triangle_diameter <= hole_diameter[j])
            {
                fit_holes.push_back(j);
            }
        }
        
        unsigned int fit_holes_size = fit_holes.size();
        if (fit_holes_size == 0)
        {
            printf("Peg %c will not fit into any holes\n", i + 'A');
        }
        else
        {
            printf("Peg %c will fit into hole(s): ", i + 'A');
            for (unsigned int j = 0; j < fit_holes_size; j++)
            {
                printf("%d", fit_holes[j] + 1);
                if (j != fit_holes_size - 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
        }
    }
    
    return 0;
}