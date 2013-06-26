#include <iostream>
#include <stdio.h>

struct Time 
{
    int hour;
    int minute;

    int GetDiffMinutes(const Time& goal)
    {
        if (hour < goal.hour || (hour == goal.hour && minute <= goal.minute))
        {
            return (goal.hour - hour) * 60 + (goal.minute - minute);
        }

        // begin -> 00:00 (or 24:00) -> goal
        return (24 - hour) * 60 - minute + goal.hour * 60 + goal.minute;
    }
};

int main(int argc, char* argv[])
{
    Time curr, bus;
    char dummy;

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int num_buses;
        std::cin >> num_buses;
        std::cin >> curr.hour >> dummy >> curr.minute;

        int travelling_time;
        int min_time = 1 << 30;
        for (int i = 0; i < num_buses; i++)
        {
            std::cin >> bus.hour >> dummy >> bus.minute >> travelling_time;
            int elasped_time = curr.GetDiffMinutes(bus) + travelling_time;
            if (elasped_time < min_time) 
            {
                min_time = elasped_time;
            }
        }
        printf("Case %d: %d\n", case_id, min_time);
    }
    return 0;
}