#include <iostream>
#include <stdio.h>

// Hack: http://www.codecodex.com/wiki/Calculate_an_integer_square_root
long long IntSqrt(long long remainder)  
{  
    long long place = (long long)1 << (sizeof(long long) * 8 - 2);
    while (place > remainder) 
    {
        place /= 4;
    }
    long long root = 0;  
    while (place)  
    {  
        if (remainder >= root + place)  
        {  
            remainder -= root + place;  
            root += place * 2;  
        }  
        root /= 2;  
        place /= 4;  
    }  
    return root;  
}  

// http://oeis.org/A000328
// a(n) = 1 + 4*Sum_{ k = 0 .. [sqrt(n)] } [ sqrt(n-k^2) ].
long long D(long long r)
{
    long long sum = 0;
    for (long long k = 0; k <= r; k++)
    {
        sum += IntSqrt(r*r - k*k);
    }
    return 1 + 4 * sum;
}

int main(int argc, char* argv[]) 
{
    long long r;
    while (std::cin >> r)
    {
        printf("%lld\n", r);
        printf("%lld\n", D(r));
    }
    return 0;
}
