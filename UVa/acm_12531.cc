#include <iostream>
#include <stdio.h>

inline int norm(int a) 
{
    return (a < 0) ? -a : a;
}

bool visited[181] = {};

void InitQueryTable()
{
    int hour_hand;
    int minute_hand;
    int diff_mark;
    for (int i = 0; i < 720; i++)
    {
        if (i % 12)
        {
            continue;
        }
        hour_hand = i / 12;
        minute_hand = i % 60;
        diff_mark = norm(hour_hand - minute_hand);
        if (diff_mark > 30)
        {
            diff_mark = 60 - diff_mark;
        }
        visited[diff_mark * 6] = true;
    }
}

int main(int argc, char* argv[]) 
{
    InitQueryTable();

    int angle;
    while (std::cin >> angle)
    {
        if (visited[angle])
        {
            puts("Y");
        }
        else
        {
            puts("N");
        }
    }
    return 0;
}
