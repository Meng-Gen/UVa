#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int n;
    int case_id = 1;
    while (std::cin >> n && n)
    {
        int giving_count = 0;
        int given_count = 0;
        int event_id;
        for (int i = 0; i < n; i++)
        {
            std::cin >> event_id;
            if (event_id) 
            {
                giving_count++;
            }
            else
            {
                given_count++;
            }
        }
        printf("Case %d: %d\n", case_id, giving_count - given_count); 

        case_id++;
    }
    return 0;
}