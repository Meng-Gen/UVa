#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))

struct Vector2D
{
    double x;
    double y;

    Vector2D() : x(0.0), y(0.0) { }
    Vector2D(double new_x, double new_y) : x(new_x), y(new_y) { }

    double Norm()
    {
        return sqrt(x*x + y*y);
    }
};

struct Position
{
    Vector2D pos;
    double angle;

    Position() : pos(), angle(0.0) { }

    void MoveForward(double units)
    {
        pos.x += (units * cos(angle * PI / 180.0));
        pos.y += (units * sin(angle * PI / 180.0));
    }

    void MoveBackward(double units)
    {
        pos.x -= (units * cos(angle * PI / 180.0));
        pos.y -= (units * sin(angle * PI / 180.0));
    }

    void TurnLeft(double units)
    {
        angle += units;
    }

    void TurnRight(double units)
    {
        angle -= units;
    }

    double Distance()
    {
        return pos.Norm();
    }
};

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        Position turtle;
        int num_cmds;
        std::cin >> num_cmds;
        for (int cmd_id = 0; cmd_id < num_cmds; cmd_id++)
        {
            std::string cmd;
            double units;
            std::cin >> cmd >> units;

            if (cmd.compare("fd") == 0)
            {
                turtle.MoveForward(units);
            }
            else if (cmd.compare("bk") == 0)
            {
                turtle.MoveBackward(units);
            }
            else if (cmd.compare("lt") == 0)
            {
                turtle.TurnLeft(units);
            }
            else if (cmd.compare("rt") == 0)
            {
                turtle.TurnRight(units);
            }
        }

        printf("%d\n", static_cast<int>(turtle.Distance() + 0.5));
    }
    return 0;
}