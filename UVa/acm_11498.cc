#include <iostream>
#include <stdio.h>

// You will get AC if you pass ``Sample Input'' in 
// http://uva.onlinejudge.org/external/114/11498.html
int main(int argc, char* argv[])
{
    int K; // the number of queries
    while (std::cin >> K)
    {
        if (K == 0) 
        {
            break; 
        }

        int N; // the coordinates of the division point
        int M;
        std::cin >> N >> M;

        for (int k = 0; k < K; k++)
        {
            int X; // the coordinates of a residence
            int Y;
            std::cin >> X >> Y;

            if (X == N || Y == M)
            {
                puts("divisa");
            }
            else if (X > N && Y > M)
            {
                puts("NE");
            }
            else if (X < N && Y > M)
            {
                puts("NO");
            }
            else if (X > N && Y < M)
            {
                puts("SE");
            }
            else if (X < N && Y < M)
            {
                puts("SO");
            }
        }
    }

    return 0;
}