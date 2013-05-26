#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))
#define EARTH_RADIUS (6371009.0)

struct Location
{
    double latitude_;
    double longitude_;

    Location() : latitude_(0.0), longitude_(0.0) { }
};

// Reference: http://en.wikipedia.org/wiki/Great-circle_distance
int DeltaDistance(const Location& s, const Location& f)
{
    double delta_longitude = s.longitude_ - f.longitude_;
    double cos_central_angle = 
        sin(PI * s.latitude_ / 180.0) 
        * sin(PI * f.latitude_ / 180.0)
        + cos(PI * s.latitude_ / 180.0)
        * cos(PI * f.latitude_ / 180.0)
        * cos(PI * delta_longitude / 180.0);
    double diff = EARTH_RADIUS 
        * (acos(cos_central_angle) - sqrt(2.0 - 2.0 * cos_central_angle));
    return (int)(diff + 0.5);
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        Location s;
        Location f;
        std::cin >> s.latitude_ >> s.longitude_;
        std::cin >> f.latitude_ >> f.longitude_;
        printf("%d\n", DeltaDistance(s, f));
    }
    return 0;
}