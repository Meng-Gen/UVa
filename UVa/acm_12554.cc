#include <iostream>
#include <stdio.h>

char name[101][101] = {};
char song[16][9] = 
{
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "Rujia",
    "Happy", "birthday", "to", "you"
};

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> name[i];
    }

    if (n > 16)
    {
        int i = 0;

        // What if there are more than 16 people? That's easy: repeat the song 
        // until everyone has sung at least once :)
        for (; i < n; i++)
        {
            printf("%s: %s\n", name[i], song[i % 16]);
        }

        // Please, don't stop in the middle of the song.
        while ((i % 16) != 0)
        {
            printf("%s: %s\n", name[i % n], song[i % 16]);
            i++;
        }
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            printf("%s: %s\n", name[i % n], song[i]);
        }
    }
    
    return 0;
}