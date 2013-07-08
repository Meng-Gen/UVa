#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_cows, num_cars, num_show;
    int num_doors, num_left;
    while (std::cin >> num_cows >> num_cars >> num_show)
    {
        num_doors = num_cows + num_cars;
        num_left = num_cows + num_cars - num_show - 1;
        double p1 = (double)num_cars/(double)(num_doors)
            * (double)(num_cars - 1)/(double)(num_left);
        double p2 = (double)num_cows/(double)(num_doors)
            * (double)(num_cars)/(double)(num_left);
        printf("%.5lf\n", p1 + p2);
    }

    return 0;
}