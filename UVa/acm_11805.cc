#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int N, K, P;
        std::cin >> N >> K >> P;
        printf("Case %d: %d\n", case_id, (K - 1 + P) % N + 1);
    }
    
    return 0;
}