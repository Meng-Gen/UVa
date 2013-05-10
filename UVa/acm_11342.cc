#include <iostream>
#include <stdio.h>

int query[50001][3] = {};
bool visited[50001] = {};

int main(int argc, char* argv[])
{
    for (int a = 0; a*a <= 50000; a++)
    {
        for (int b = 0; b*b <= 50000; b++)
        {
            for (int c = 0; c*c <= 50000; c++)
            {
                int three_square = a*a + b*b + c*c;
                if (three_square > 50000)
                {
                    break;
                }
                if (!visited[three_square])
                {
                    visited[three_square] = true;
                    query[three_square][0] = a;
                    query[three_square][1] = b;
                    query[three_square][2] = c;
                }
            }
        }
    }

    int N;
    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        int K;
        std::cin >> K;
        
        if (!visited[K])
        {
            printf("-1\n");   
        }
        else 
        {
            printf("%d %d %d\n", query[K][0], query[K][1], query[K][2]);
        }
    }
    return 0;
}