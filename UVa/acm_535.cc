#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <stdio.h>

#define PI (3.141592653589793)

template <class T> 
void ToString(T& value, const std::string& buffer) 
{
    std::stringstream value_builder(buffer);
    value_builder >> value;
}

struct Location
{
    double latitude_;
    double longitude_;

    Location() : latitude_(0.0), longitude_(0.0) { }
    Location(double latitude, double longitude) 
        : latitude_(latitude), longitude_(longitude) { }
};

std::map<std::string, Location> city_location;

void ScanCityList()
{
    std::string buffer;
    while (1) 
    {
        getline(std::cin, buffer);
        if (buffer.compare("#") == 0)
        {
            break;
        }
        unsigned int first_space = buffer.find(' ');
        unsigned int next_space = buffer.find(' ', first_space + 1);       
        std::string name = buffer.substr(0, first_space);
        Location location;
        ToString(location.latitude_, 
            buffer.substr(first_space + 1, next_space - first_space + 1));
        ToString(location.longitude_, buffer.substr(next_space + 1));

        city_location[name] = location;
    }
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
int Distance(const std::string& s, const std::string& f)
{
    double R = 6378.0;
    double delta_longitude = city_location[s].longitude_
        - city_location[f].longitude_;
    double central_angle = 
        sin(PI * city_location[s].latitude_ / 180.0)
        * sin(PI * city_location[f].latitude_ / 180.0)
        + cos(PI * city_location[s].latitude_ / 180.0)
        * cos(PI * city_location[f].latitude_ / 180.0)
        * cos(PI * delta_longitude / 180.0);
    central_angle = acos(central_angle);
    return (int)(R * central_angle + 0.5);
}

int main(int argc, char* argv[])
{
    ScanCityList();

    while (1) 
    {
        std::string buffer;
        getline(std::cin, buffer);
        if (buffer.compare("# #") == 0)
        {
            break;
        }

        unsigned int space = buffer.find(' ');
        std::string s = buffer.substr(0, space);
        std::string f = buffer.substr(space + 1);

        printf("%s - %s\n", s.c_str(), f.c_str());
        
        if ((city_location.find(s) == city_location.end())
            || (city_location.find(f) == city_location.end()))
        {
            puts("Unknown");
        }
        else if (s.compare(f) == 0)
        {
            puts("0 km");
        }
        else
        {
            printf("%d km\n", Distance(s, f));
        }
    }

    return 0;
}