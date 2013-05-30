#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[]) 
{   
    int testcase_count;
    std::cin >> testcase_count;
    getchar();
    getchar();

    puts("Lumberjacks:");

    while (testcase_count--)
    {
        std::string sequence_string;
        getline(std::cin, sequence_string);

        std::stringstream sequence_stream(sequence_string);
        std::istream_iterator<int> it(sequence_stream);
        std::istream_iterator<int> end;
        std::vector<int> sequence(it, end);

        int increasing_count = 0;
        int decreasing_count = 0;
        for (unsigned int i = 1; i < sequence.size(); i++)
        {
            int diff = sequence[i] - sequence[i-1];
            if (diff > 0)
            {
                increasing_count++;
            }
            else if (diff < 0)
            {
                decreasing_count++;
            }
        }

        if ((increasing_count > 0) && (decreasing_count > 0))
        {
            puts("Unordered");
        }
        else
        {
            puts("Ordered");
        }
    }
    return 0;
}
