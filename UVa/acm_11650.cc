#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        int hours;
        int minutes;
        char colon;
        std::cin >> hours >> colon >> minutes;

        int mirrored_hours = 0;
        int mirrored_minutes = 0;
        if (minutes == 0)
        {
            mirrored_hours = 12 - hours;
            if (mirrored_hours == 0)
            {
                mirrored_hours = 12;
            }
        }
        else 
        {
            mirrored_hours = 11 - hours;
            if (mirrored_hours <= 0)
            {
                mirrored_hours += 12;
            }
            mirrored_minutes = 60 - minutes;
        }

        printf("%02d:%02d\n", mirrored_hours, mirrored_minutes);
   }

    return 0;
}