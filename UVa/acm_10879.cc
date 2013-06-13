#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        long long K;
        std::cin >> K;

        long long solution[2][2] = {};
        int solution_count = 0;
        while (solution_count != 2)
        {
            for (long long i = 2; i * i <= K; i++)
            {
                if (K % i == 0)
                {
                    solution[solution_count][0] = i;
                    solution[solution_count][1] = K / i;
                    solution_count++;
                }
                if (solution_count == 2)
                {
                    break;
                }
            }
        }

        printf("Case #%d: %lld = %lld * %lld = %lld * %lld\n", 
            case_id, K, 
            solution[0][0], solution[0][1],
            solution[1][0], solution[1][1]);
    }

    return 0;
}