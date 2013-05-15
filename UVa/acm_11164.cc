#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    double a;
    double b;
    double c;

    int set_id = 1;
    while (std::cin >> a >> b >> c)
    {
        if (a == -1.0)
        {
            break;
        }

        double d = a*c*(a + b + b + c)/(b*b - a*c);
        printf("Set %d:\n", set_id);
        printf("%.4lf\n", d);
        set_id++;
    }
    
    return 0;
}