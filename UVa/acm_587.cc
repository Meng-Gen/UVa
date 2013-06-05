#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <math.h>
#include <stdio.h>

#define SQRT_HALF (sqrt(0.5))

struct Point
{
    double x;
    double y;

    Point() : x(0.0), y(0.0) { }

    void Add(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    double Norm()
    {
        return sqrt(x*x + y*y);
    }
};

std::map<std::string, double> dx;
std::map<std::string, double> dy;

void InitDeltaLocation()
{
    std::string directions[8] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    double delta_x[8] = 
    { 
        0.0,  SQRT_HALF,  1.0,  SQRT_HALF,  
        0.0, -SQRT_HALF, -1.0, -SQRT_HALF
    };
    double delta_y[8] = 
    { 
         1.0,  SQRT_HALF, 0.0, -SQRT_HALF, 
        -1.0, -SQRT_HALF, 0.0,  SQRT_HALF
    };

    for (int i = 0; i < 8; i++)
    {
        dx[directions[i]]= delta_x[i];
        dy[directions[i]]= delta_y[i];
    }
}

int main(int argc, char* argv[])
{
    InitDeltaLocation();

    int map_id = 1;
    std::string treasure_map;
    while (getline(std::cin, treasure_map) && treasure_map.compare("END") != 0)
    {
        Point p;

        // Ignore period (.)
        treasure_map = treasure_map.substr(0, treasure_map.size() - 1);
        int prev_pos = 0;
        int curr_pos = -1;
        do
        {
            prev_pos = curr_pos + 1;
            curr_pos = treasure_map.find(',', curr_pos + 1);
          
            int length;
            std::string direction;
            std::istringstream step(treasure_map.substr(
                prev_pos, curr_pos - prev_pos));
            step >> length >> direction;
            
            p.Add(dx[direction] * length, dy[direction] * length);
        }
        while (curr_pos != std::string::npos);

        printf("Map #%d\n", map_id);
        printf("The treasure is located at (%.3lf,%.3lf).\n", p.x, p.y);
        printf("The distance to the treasure is %.3lf.\n\n", p.Norm());

        map_id++;
    }

    return 0;
}