#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();

    std::string tracks;
    while (num_testcases--)
    {
        getline(std::cin, tracks);
        
        int male_count = 0;
        int female_count = 0;
        for (std::string::const_iterator it = tracks.begin();
            it != tracks.end(); it++)
        {
            if (*it == 'M')
            {
                male_count++;
            }
            else if (*it == 'F')
            {
                female_count++;
            }
        }

        if ((male_count + female_count == 2) || 
            (male_count != female_count))
        {
            puts("NO LOOP");
        }
        else
        {
            puts("LOOP");
        }
    }

    return 0;
}