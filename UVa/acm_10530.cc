#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    bool is_ollie_turn = true;
    int guess;
    bool solution_space[11];
    for (int i = 0; i < 11; i++)
    {
        solution_space[i] = true;
    }

    while (1)
    {
        if (is_ollie_turn)
        {
            std::cin >> guess;
            if (guess == 0)
            {
                break;
            }
            is_ollie_turn = false;
        }
        else
        {
            std::string response[2];
            std::cin >> response[0] >> response[1];
            if (response[0].compare("right") == 0)
            {
                if (solution_space[guess])
                {
                    printf("Stan may be honest\n");
                }
                else
                {
                    printf("Stan is dishonest\n");
                }
                for (int i = 0; i < 11; i++)
                {
                    solution_space[i] = true;
                }
            }
            else if (response[1].compare("high") == 0)
            {
                for (int i = guess; i <= 10; i++)
                {
                    solution_space[i] = false;
                }
            }
            else if (response[1].compare("low") == 0)
            {
                for (int i = 1; i <= guess; i++)
                {
                    solution_space[i] = false;
                }
            }

            is_ollie_turn = true;
        }
    }
    return 0;
}