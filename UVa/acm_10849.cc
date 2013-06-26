#include <iostream>
#include <stdio.h>

inline int norm(int a) 
{
    return (a < 0) ? -a : a;
}

struct Position 
{
    int x, y;

    Position() : x(0), y(0) { }
    Position(int init_x, int init_y) : x(init_x), y(init_y) { }

    int Parity() const 
    {
        return (x + y) % 2;
    }

    bool Equals(const Position& other)
    {
        return x == other.x && y == other.y;
    }
};

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_query;
    int board_size;
    Position start, goal;

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> num_query >> board_size;
        for (int query_id = 0; query_id < num_query; query_id++)
        {
            std::cin >> start.x >> start.y >> goal.x >> goal.y;
            
            if (start.Parity() != goal.Parity())
            {
                puts("no move");
            }
            else if (start.Equals(goal))
            {
                puts("0");
            }
            else if (norm(goal.x - start.x) == norm(goal.y - start.y))
            {
                puts("1");
            }
            else
            {
                puts("2");
            }
        }
    }

    return 0;
}