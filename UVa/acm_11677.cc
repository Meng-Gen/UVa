#include <iostream>
#include <stdio.h>

struct AlarmClock 
{
    int hour;
    int minute;

    int GetSleepMinutes(const AlarmClock& other)
    {
        if (hour < other.hour || (hour == other.hour && minute <= other.minute))
        {
            return (other.hour - hour) * 60 + (other.minute - minute);
        }

        // begin -> 00:00 (or 24:00) -> goal
        return (24 - hour) * 60 - minute + other.hour * 60 + other.minute;
    }
};

int main(int argc, char* argv[])
{
    AlarmClock begin, goal;
    while (std::cin >> begin.hour >> begin.minute >> goal.hour >> goal.minute
        && (begin.hour || begin.minute || goal.hour || goal.minute))
    {
        std::cout << begin.GetSleepMinutes(goal) << std::endl;
    }
    return 0;
}