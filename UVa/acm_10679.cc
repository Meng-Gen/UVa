#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

char S[100001]; // the text to be searched
char W[1001]; // the word sought
int T[100001] = {};

int S_length;
int W_length;

int kmp_search()
{
    int m = 0;
    int i = 0;

    while (m+i < S_length)
    {
        if (W[i] == S[m + i])
        {
            if (i == W_length - 1)
            {
                return m;
            }
            i++;
        }
        else
        {
            m = m + i - T[i];
            if (T[i] > -1)
            {
                i = T[i];
            }
            else
            {
                i = 0;
            }
        }   
    }

    return S_length;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        std::cin.getline(S, 100001);
        S_length = strlen(S);

        int num_query;
        std::cin >> num_query;
        getchar();
        for (int query_id = 0; query_id < num_query; query_id++)
        {
            std::cin.getline(W, 1001);
            W_length = strlen(W);
            memset(T, -1, 100001);
            if (kmp_search() != S_length)
            {
                printf("y\n");
            }
            else
            {
                printf("n\n");
            }
        }
    }
    return 0;
}