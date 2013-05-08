// Problem Solving Paradigms :: Complete Search :: 
// Recursive Backtracking (The Easier Ones)
//
// However, I think backtracking is hard.
#include <iostream>
#include <stdio.h>

// 0 < n <= 16.
// The maximum sum of numbers in two adjacent circles is 15+16 = 31.
// So we create a small prime table for 0 to 31.
bool is_prime[32];

void init_prime_table()
{
    bool is_prime_visited[32];
    for (int i = 0; i < 32; i++)
    {
        is_prime[i] = false;
        is_prime_visited[i] = false;
    }
    for (int i = 2; i < 32; i++)
    {
        if (!is_prime_visited[i])
        {
            is_prime[i] = true;
            for (int j = 1; i*j < 32; j++)
            {
                is_prime_visited[i*j] = true;
            }
        }
    }
}

// Backtracking problem data structure and algorithm.
int N;
bool is_used[18];
int solution_vector[18];

bool is_prime_ring(int dimension)
{
    if (dimension == 1)
    {
        return true;
    }
    else if (dimension == N)
    {
        for (int i = 0; i < N; i++)
        {
            int sum = solution_vector[i] + solution_vector[(i+1)%N];
            if (!is_prime[sum])
            {
                return false;
            }
        }
    }
    else 
    {
        for (int i = 0; i < dimension - 1; i++)
        {
            int sum = solution_vector[i] + solution_vector[i+1];
            if (!is_prime[sum])
            {
                return false;
            }
        }
    }
    return true;
}

void backtrack(int dimension)
{
    if (!is_prime_ring(dimension))
    {
        return;
    }

    if (dimension == N)
    {
        // Print solution.
        for (int i = 0; i < N; i++)
        {
            printf("%d", solution_vector[i]);
            if (i != (N-1))
            {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }

    for (int i = 2; i <= N; i++)
    {
        if (!is_used[i])
        {
            solution_vector[dimension] = i;
            is_used[i] = true;
            backtrack(dimension + 1);
            is_used[i] = false;
        }
    }
}

int main(int argc, char* argv[])
{
    init_prime_table();

    int case_id = 1;
    while (std::cin >> N) 
    {
        if (case_id > 1)
        {
            printf("\n");
        }
        printf("Case %d:\n", case_id);

        for (int i = 0; i < 18; i++)
        {
            is_used[i] = false;
            solution_vector[i] = 0;
        }

        solution_vector[0] = 1;
        is_used[1] = true;
        backtrack(1);

        case_id++;
    }
    return 0;
}
