#include <iostream>
#include <math.h>
#include <stdio.h>

// (1) v = u + at
// (2) s = (u + v)/2 * t
int main(int argc, char* argv[])
{
    int case_id = 1;
    while (1)
    {
        int command;
        std::cin >> command;
        if (command == 0)
        {
            break;        
        }

        double s;
        double t;
        double u;
        double v;
        double a;
        switch (command)
        {
        // If 1 u v t are given then print s and a
        case 1:
            std::cin >> u >> v >> t;
            s = (u + v) * t * 0.5;
            a = (v - u) / t;
            printf("Case %d: %.3lf %.3lf\n", case_id, s, a);
            break;
        // If 2 u v a are given then print s and t
        case 2:
            std::cin >> u >> v >> a;
            t = (v - u) / a;
            s = (u + v) * t * 0.5;
            printf("Case %d: %.3lf %.3lf\n", case_id, s, t);
            break;
        // If 3 u a s are given then print v and t
        case 3:
            std::cin >> u >> a >> s;
            if (a != 0.0)
            {
                t = (sqrt(u * u + 2.0 * a * s) - u)/ a;
            }
            else
            {
                t = s / u;
            }
            v = u + a * t;
            printf("Case %d: %.3lf %.3lf\n", case_id, v, t);
            break;
        // If 4 v a s are given then print u and t
        case 4:
            std::cin >> v >> a >> s;
            if (a != 0.0)
            {
                t = (v - sqrt(v * v - 2.0 * a * s))/ a;
            }
            else
            {
                t = s / v;
            }
            u = v - a * t;
            printf("Case %d: %.3lf %.3lf\n", case_id, u, t);
            break;
        // It should not be here
        default:
            break;
        }

        case_id++;
    }
    return 0;
}