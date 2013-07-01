#include <iostream>
#include <stdio.h>

int T, N;
int duration;

int main(int argc, char* argv[]) 
{
    std::cin >> T;
    for (int case_id = 1; case_id <= T; case_id++)
    {
        int mile = 0;
        int juice = 0;
        std::cin >> N;
        for (int i = 0; i < N; i++)
        {
            std::cin >> duration;
            mile = mile + (duration / 30 + 1) * 10;
            juice = juice + (duration / 60 + 1) * 15;
        }
        if (mile < juice)
        {
            printf("Case %d: Mile %d\n", case_id, mile);
        }
        else if (mile > juice)
        {
            printf("Case %d: Juice %d\n", case_id, juice);
        }
        else
        {
            printf("Case %d: Mile Juice %d\n", case_id, mile);
        }
    }    
    return 0;
}
