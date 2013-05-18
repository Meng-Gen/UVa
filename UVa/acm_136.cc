#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

struct Compare  
{  
    bool operator()(const long long& a, const long long& b)  
    {  
        return a > b;  
    }  
};  

struct UglyNumberBuilder
{
    std::priority_queue< long long, std::vector<long long>, Compare > ugly_queue;

    long long Build(int nth)
    {
        long long rv = 1;
        BuildNextUglyNumber(rv);
        for (int i = 1; i < nth; i++)
        {
            rv = ugly_queue.top();
            do 
            {   
                ugly_queue.pop();
            }
            while (ugly_queue.top() == rv);
            BuildNextUglyNumber(rv);
        }

        return rv;
    }   

    void BuildNextUglyNumber(long long a)
    {
        ugly_queue.push(2 * a);
        ugly_queue.push(3 * a);
        ugly_queue.push(5 * a);
    }
};

// Print '\n' otherwise you will get WA.
int main(int argc, char* argv[])
{
    // Time: 0.016
    UglyNumberBuilder builder;
    printf("The 1500'th ugly number is %lld.\n", builder.Build(1500));

    // Time: 0.009
    // printf("The 1500'th ugly number is 859963392.\n");
    return 0;
}