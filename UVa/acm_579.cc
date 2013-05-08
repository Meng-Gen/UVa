#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::string input;
    while (std::cin >> input)
    {
        if (input.compare("0:00") == 0)
        {
            break;
        }

        int H;
        int M;
        if (input.size() == 4)
        {
            H = input[0] - '0';
            M = (input[2] - '0') * 10 + (input[3] - '0');
        }
        else 
        {
            H = (input[0] - '0') * 10 + (input[1] - '0');
            M = (input[3] - '0') * 10 + (input[4] - '0');   
        }

        // Elementary math.
        double H_degree = 30.0 * (H % 12) + 0.5 * M;
        double M_degree = 6.0 * M;

        double diff = H_degree - M_degree;
        if (diff < 0)
        {
            diff = -diff;
        }
        while (diff > 360.0)
        {
            diff -= 360.0;
        }
        if (diff > 180.0)
        {
            diff = 360.0 - diff;
        }

        printf("%.3lf\n", diff);
    }

    return 0;
}
