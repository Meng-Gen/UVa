#include <iostream>
#include <stdio.h>

char M[10001][21];
int L[10001];
int H[10001];

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        if (t > 0)
        {
            printf("\n");
        }

        int D;
        std::cin >> D;
        for (int d = 0; d < D; d++)
        {
            std::cin >> M[d] >> L[d] >> H[d];
        }
        
        int Q;
        std::cin >> Q;
        for (int q = 0; q < Q; q++)
        {
            int P;
            std::cin >> P;

            bool is_found = false;
            int found_index = -1;
            for (int i = 0; i < D; i++)
            {
                if ((P >= L[i]) && (P <= H[i]))
                {
                    // Ambiguous and we set |is_found| to false and break 
                    // iteration. 
                    if (is_found)
                    {
                        is_found = false;
                        break;
                    }
                    is_found = true;
                    found_index = i;
                }
            }

            if (is_found)
            {
                printf("%s\n", M[found_index]);
            }
            else
            {
                printf("UNDETERMINED\n");
            }
        }
    }

    return 0;
}
