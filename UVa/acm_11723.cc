#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_streets;
    int num_integers;
    int case_id = 1;
    while (std::cin >> num_streets >> num_integers &&
        (num_streets != 0 || num_integers != 0))
    {
        int min_num_suffixes = num_streets / num_integers;
        if (num_streets % num_integers != 0)
        {
            min_num_suffixes++;
        }
        min_num_suffixes--;

        if (min_num_suffixes > 26)
        {
            printf("Case %d: impossible\n", case_id);
        }
        else
        {
            printf("Case %d: %d\n", case_id, min_num_suffixes);
        }
        case_id++;
    }
    
    return 0;
}