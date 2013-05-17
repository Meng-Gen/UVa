#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char decoder[] = "OIZEASGTBP";

    int T;
    std::cin >> T;
    getchar();

    char buffer[101];
    for (int t = 0; t < T; t++)
    {
        if (t > 0)
        {
            putchar('\n');
        }

        while (std::cin.getline(buffer, 101))
        {
            int length = 0;
            for (; buffer[length]; length++)
            {
            }

            if (length == 0)
            {
                break;
            }
            
            for (int i = 0; i < length; i++)
            {
                if (buffer[i] >= '0' && buffer[i] <= '9')
                {
                    putchar(decoder[buffer[i] - '0']);
                }
                else
                {
                    putchar(buffer[i]);
                }
            }
            putchar('\n');
        }
    }

    return 0;
}
