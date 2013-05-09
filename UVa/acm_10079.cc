#include <iostream>
#include <stdio.h>

// If a cut intersects k lines and then creates exactly k different 
// intersection points, the # pieces of pizza will increase (k+1) pieces.
// So, the answer is N(N+1)/2 + 1.
//
// But in the real life, N cuts creates 2N pieces and then everyone feels
// happy for eating pizza :-) 
int main(int argc, char* argv[])
{
    long long N;

    while (1)
    {
        std::cin >> N;
        if (N < 0)
        {
            break;
        }
        std::cout << N*(N+1)/2 + 1 << std::endl;
    }

    return 0;
}