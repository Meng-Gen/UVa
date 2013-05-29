#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdio.h>

// The area is PI (r1+r2)^2 - PI r1^2 - PI r2^2 = 2 PI r1 r2
inline double gray_area(double r1, double r2)
{
    return 4.0 * acos(0.0) * r1 * r2;
}

// t satisfies the equation: (r1 + r2)^2 = (t/2)^2 + (r1 - r2)^2.
// So, t^2 / 4 = 4 r1 r2.  The gray area is PI t^2 / 8.
inline double gray_area(double t)
{
    return 0.25 * acos(0.0) * t * t;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    std::string buffer;
    getline(std::cin, buffer);
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        getline(std::cin, buffer);
        std::stringstream buffer_stream(buffer);
        std::istream_iterator<int> it(buffer_stream);
        std::istream_iterator<int> end;
        std::vector<int> numbers(it, end);

        if (numbers.size() == 2)
        {
            printf("%.4lf\n", gray_area(numbers[0], numbers[1]));
        }
        else
        {
            printf("%.4lf\n", gray_area(numbers[0]));
        }
    }

    return 0;
}