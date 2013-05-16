#include <iostream>
#include <stack>
#include <stdio.h>

int train[1001];

int main(int argc, char* argv[])
{
    int N;
    int dataset_id = 1;
    while (1)
    {
        std::cin >> N;
        if (N == 0)
        {
            break;
        }

        int query_id = 1;
        while (1)
        {
            std::cin >> train[0];
            if (train[0] == 0)
            {
                dataset_id++;
                break;
            }
            for (int i = 1; i < N; i++)
            {
                std::cin >> train[i];
            }

            std::stack<int> station_stack;
            int next_waiting_train = 1;
            bool is_possible = true;
            for (int i = 0; i < N; i++)
            {
                if (station_stack.empty() || (station_stack.top() != train[i]))
                {
                    for (int j = next_waiting_train; j <= train[i]; j++)
                    {
                        station_stack.push(j);
                    }
                    next_waiting_train = train[i] + 1;
                }
                if ((!station_stack.empty()) && station_stack.top() == train[i])
                {
                    station_stack.pop();
                }
                else
                {
                    is_possible = false;
                    break;
                }
            }

            if (dataset_id > 1 && query_id == 1)
            {
                printf("\n");
            }

            if (is_possible)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }

            query_id++;
        }
    }

    return 0;
}