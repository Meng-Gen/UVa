#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;

    for (int case_id = 1; case_id <= T; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }
        printf("Case %d:\n", case_id);

        int N;
        std::cin >> N;
        getchar();
        for (int n = 0; n < N; n++)
        {
            std::string line;
            getline(std::cin, line);

            bool is_space_phase = false;
            std::stringstream removed;
            for (unsigned int i = 0; i != line.size(); i++)
            {
                if (line[i] == ' ')
                {
                    if (!is_space_phase)
                    {
                        is_space_phase = true;
                        removed << line[i];
                    }
                    else 
                    {
                        continue;
                    }
                }
                else 
                {
                    is_space_phase = false;
                    removed << line[i];
                }
            }

            // Check the boundary case: a lot of space in the end of |line|.
            // It does not matter.  So we print the result directly.
            printf("%s\n", removed.str().c_str());
        }
    }

    return 0;
}