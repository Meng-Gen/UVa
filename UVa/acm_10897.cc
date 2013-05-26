#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))
#define EARTH_RADIUS (6371.01)

struct Location
{
    double latitude_;
    double longitude_;

    Location() : latitude_(0.0), longitude_(0.0) { }
    Location(double latitude, double longitude) 
        : latitude_(latitude), longitude_(longitude) { }
};

inline double GetDegrees
(
    double degrees, double minutes, double seconds, char direction
)
{
    double rv = degrees + minutes / 60.0 + seconds / 3600.0;
    return (direction == 'S' || direction == 'W') ? -rv : rv;
}

// Geodesics. 
// Great-circle distance.
// Reference: http://en.wikipedia.org/wiki/Great-circle_distance
//
// Hint:
// (1) Convert degree to radian for each angle.
// (2) d = R * central_angle
// (3) cos(central_angle) =   sin(lat_s) sin(lat_f) 
//                          + cos(lat_s) cos(lat_f) cos(long_s - long_f).
// (4) We can use |acos| of |math.h|.  It is ok.
double Distance(const Location& s, const Location& f)
{
    double delta_longitude = s.longitude_ - f.longitude_;
    double central_angle = 
        sin(PI * s.latitude_ / 180.0) 
        * sin(PI * f.latitude_ / 180.0)
        + cos(PI * s.latitude_ / 180.0)
        * cos(PI * f.latitude_ / 180.0)
        * cos(PI * delta_longitude / 180.0);
    central_angle = acos(central_angle);
    return EARTH_RADIUS * central_angle;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        double degrees;
        double minutes; 
        double seconds;
        char direction;

        Location location[2];
        for (int i = 0; i < 2; i++)
        {
            std::cin >> degrees >> minutes >> seconds >> direction;
            location[i].latitude_ = 
                GetDegrees(degrees, minutes, seconds, direction);
            std::cin >> degrees >> minutes >> seconds >> direction;
            location[i].longitude_ = 
                GetDegrees(degrees, minutes, seconds, direction);
        }

        printf("%.2lf\n", Distance(location[0], location[1]));
    }
    return 0;
}