#include <iostream>
#include <stdio.h>

int grade[1001];

int main(int argc, char* argv[])
{
    int C; // the number of test cases
    std::cin >> C;

    for (int c = 0; c < C; c++)
    {
        int N; // the number of people in the class
        std::cin >> N;
     
        int sum = 0;
        for (int n = 0; n < N; n++)
        {
            std::cin >> grade[n];
            sum += grade[n];
        }

        double average = (double)sum / (double)N;

        int above_average_count = 0;
        for (int n = 0; n < N; n++)
        {
            if (grade[n] > average)
            {
                above_average_count++;
            }
        }

        double above_average_percentage = 100.0 * 
            (double)above_average_count / (double)N;

        printf("%.3lf%%\n", above_average_percentage);
    }

    return 0;
}