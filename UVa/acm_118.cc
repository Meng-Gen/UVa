#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<char, int> orientation_map;
char orientation_reversed_map[4] = { 'N', 'E', 'S', 'W' };
int move[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

void InitQuery()
{
    orientation_map['N'] = 0;
    orientation_map['E'] = 1;
    orientation_map['S'] = 2;
    orientation_map['W'] = 3;
}

int main(int argc, char* argv[])
{
    InitQuery();

    int world[2];
    std::cin >> world[0] >> world[1];

    bool scent[52][52] = {}; 

    int pos[2];
    char orientation_char;
    while (std::cin >> pos[0] >> pos[1] >> orientation_char)
    {
        int orientation = orientation_map[orientation_char];
        std::string instruction;
        std::cin >> instruction;

        bool is_lost = false;
        for (std::string::iterator it = instruction.begin();
            it != instruction.end(); it++)
        {
            if (*it == 'L')
            {
                orientation += 3;
                orientation %= 4;
            }
            else if (*it == 'R')
            {
                orientation += 1;
                orientation %= 4;            
            }
            else if (*it == 'F')
            {
                pos[0] += move[orientation][0];
                pos[1] += move[orientation][1];

                if (pos[0] < 0 || pos[0] > world[0] || 
                    pos[1] < 0 || pos[1] > world[1])
                {
                    pos[0] -= move[orientation][0];
                    pos[1] -= move[orientation][1];
                    if (!scent[pos[0]][pos[1]])
                    {
                        scent[pos[0]][pos[1]] = true;
                        is_lost = true;
                        break;
                    }
                }
            }
        }
        
        printf("%d %d %c", pos[0], pos[1], 
            orientation_reversed_map[orientation]);

        if (is_lost)
        {
            printf(" LOST");
        }
        putchar('\n');
    }

    return 0;
}