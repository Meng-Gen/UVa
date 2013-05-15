#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))

int main(int argc, char* argv[])
{
    double l; 
    double w;
    double h;
    double theta; 

    while (std::cin >> l >> w >> h >> theta)
    {
        double theta_angle = theta * PI / 180.0;
        double critical_angle = atan(h/l);
        double V = 0.0;
        if (theta_angle < critical_angle)
        {
            V = l * h * w - 0.5 * l * l * tan(theta_angle) * w;
        }
        else 
        {
            V = 0.5 * h * h / tan(theta_angle) * w;
        }
        
        printf("%.3lf mL\n", V);
    }   
    return 0;
}