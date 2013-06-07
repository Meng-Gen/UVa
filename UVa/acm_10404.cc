#include <iostream>
#include <stdio.h>

bool stones[1000002] = {};
int moves[12] = {};

int main(int argc, char* argv[]) 
{
    int num_stones;
    int num_moves;
    int move;
    while (std::cin >> num_stones >> num_moves)
    {
        for (int j = 0; j < num_moves; j++)
        {
            std::cin >> moves[j];
        }

        stones[0] = true;
        for (int i = 1; i <= num_stones; i++)
        {
            stones[i] = false;
            for (int j = 0; j < num_moves; j++)
            {
                if (i > moves[j])
                {
                    if (!stones[i - moves[j]])
                    {
                        stones[i] = true;
                        break;
                    }
                }
                else if (i == moves[j])
                {
                    stones[i] = true;
                    break;
                }
            }
        }
        
        if (stones[num_stones])
        {
            puts("Stan wins");
        }
        else
        {
            puts("Ollie wins");
        }
    }
    return 0;
}