#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

#define EARTH_RADIUS 6440.0
#define PI acos(-1.0)

int main(int argc, char* argv[])
{
    double s; // the distance of the satellite from the surface of the earth
    double a; // the angle that the satellites make with the center of earth
    std::string angle_measurement;
    while (std::cin >> s >> a >> angle_measurement)
    {
        double r = EARTH_RADIUS + s;
        double theta = a;
        if (angle_measurement.compare("min") == 0)
        {
            // 1 degree = 60 minutes
            theta /= 60.0;
        }

        // Otherwise you will get WA.
        if (theta > 180.0)
        {
            theta = 360.0 - theta;
        }
        theta = theta / 180.0 * PI;

        double arc_distance = theta * r;
        double chord_distance = 2 * r * sin(theta / 2.0);
        printf("%.6lf %.6lf\n", arc_distance, chord_distance);
    }

    return 0;
}