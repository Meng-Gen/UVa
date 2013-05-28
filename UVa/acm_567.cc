#include <iostream>
#include <stdio.h>

#define INFINITY_WEIGHT (999)

inline int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int main(int argc, char* argv[])
{
    int case_id = 1;

    // Reading input is tricky.
    int num_country;
    while (std::cin >> num_country)
    {
        // Initialize.
        int gameboard[21][21] = {};
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                if (i != j)
                {
                    gameboard[i][j] = INFINITY_WEIGHT;
                }
            }
        }

        int country;
        for (int j = 0; j < num_country; j++)
        {            
            std::cin >> country;
            gameboard[1][country] = 1;
            gameboard[country][1] = 1;
        }
        for (int ith = 2; ith < 20; ith++)
        {
            std::cin >> num_country;
            for (int j = 0; j < num_country; j++)
            {
                std::cin >> country;
                gameboard[ith][country] = 1;
                gameboard[country][ith] = 1;
            }
        }

        // Floyd-Warshall algorithm.
        // The graph is quite small (|V| = 20), and thus constructing 
        // all shortest paths for O(1) query is good for this problem.
        for (int k = 1; k <= 20; k++)
        {
            for (int i = 1; i <= 20; i++)
            {
                for (int j = 1; j <= 20; j++)
                {
                    gameboard[i][j] = minimum(
                        gameboard[i][j], 
                        gameboard[i][k] + gameboard[k][j]);
                }
            }
        }

        // Query.
        printf("Test Set #%d\n", case_id);

        int num_query;
        std::cin >> num_query;
        for (int query_id = 0; query_id < num_query; query_id++)
        {
            int source;
            int destination;
            std::cin >> source >> destination;
            printf("%2d to %2d: %d\n", 
                source, 
                destination, 
                gameboard[source][destination]);
        }
        putchar('\n');

        case_id++;
    }

    return 0;
}