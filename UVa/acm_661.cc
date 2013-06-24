#include <iostream>
#include <stdio.h>

int n, m, c;
bool on[22] = {};
int consumption[22] = {};

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main(int argc, char* argv[]) 
{
    int sequence_id = 1;
    while (std::cin >> n >> m >> c && (n || m || c))
    {
        for (int device_id = 1; device_id <= n; device_id++)
        {
            on[device_id] = false;
            std::cin >> consumption[device_id];
        }

        int curr_consumption = 0;
        int max_consumption = 0;
        int curr_device = 0;
        for (int op_id = 1; op_id <= m; op_id++)
        {
            std::cin >> curr_device;
            if (on[curr_device])
            {
                curr_consumption -= consumption[curr_device];
                on[curr_device] = false;
            }
            else
            {
                curr_consumption += consumption[curr_device];
                max_consumption = maximum(max_consumption, curr_consumption);
                on[curr_device] = true;
            }
        }

        printf("Sequence %d\n", sequence_id);
        sequence_id++;
        if (max_consumption > c)
        {
            puts("Fuse was blown.\n");
        }
        else
        {
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %d amperes.\n\n", 
                max_consumption);
        }
    }
    return 0;
}