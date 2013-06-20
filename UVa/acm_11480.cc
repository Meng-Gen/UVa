#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int case_id = 1;
    long long N;
    while (std::cin >> N && N)
    {
        // # solution of x + y + z = N where 0 < x, y, z
        // is equal to # solution of x + y + z = N-3 where 0 <= x, y, z.
        long long ways = (N-1) * (N-2) / 2;

        // # solution of x = y or y = z or z = y.
        ways -= ((N-3)/2 + 1) * 3; 

        // # solution of x = y = z is 1 if N % 3 == 0
        //                            0 if N % 3 <> 0
        if (N % 3 == 0)
        {
            ways += 2;
        }

        // # solution of x < y < z or x < z < y or ...
        // There are 3! = 6 symmetric solutions in this case.  
        // So we divide 6 at the last step.
        ways /= 6;
        printf("Case %d: %lld\n", case_id, ways);
        case_id++;
    }
    return 0;
}