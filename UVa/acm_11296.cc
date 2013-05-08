#include <iostream>

//  x + 2y + 2z = n.
//
//  Move x to the right hand side: 2y + 2z = n - x.
//  Therefore, the origin problem is equivalent to asking the # of solution of
//  the equation 2y + 2z = k where k = 0 ... n.
//  
//  When k is odd, it is impossible to solve 2y + 2z = k 
//  because the left hand side is even.
//  When k = 0, # of solution of 2y + 2z = 0 <=> y + z = 0 is 1 = k/2 + 1.
//  When k = 2, # of solution of 2y + 2z = 2 <=> y + z = 1 is 2 = k/2 + 1.
//  When k = 4, # of solution of 2y + 2z = 4 <=> y + z = 2 is 3 = k/2 + 1.
//  When k = 6, # of solution of 2y + 2z = 6 <=> y + z = 3 is 4 = k/2 + 1.
//  In general, when k is even, # of solution of 2y + 2z = k is k/2 + 1.
// 
//  Sum them up: 
//      If n is even, # of solution is \sum_{k = 0}^{n/2}(k + 1).
//      If n is odd, # of solution is \sum_{k = 0}^{m/2}(k + 1) where m = n-1.
//
//  In C++ implementation, we can take n/2 as an integer datatype to combine
//  two cases into unique formula.
int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n)
    {
        long long half_n = n/2;
        long long rv = (half_n * (half_n + 1))/2 + half_n + 1;
        std::cout << rv << std::endl;
    }
    return 0;
}