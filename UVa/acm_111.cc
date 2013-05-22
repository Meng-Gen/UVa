#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>

int n;
int c[1002][1002];

int GetLCSLength(const std::vector<int>& a, const std::vector<int>& b)
{
    memset(c, 0, sizeof(int) * 1002 * 1002);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                c[i+1][j+1] = c[i][j] + 1;
            }
            else if (c[i][j+1] >= c[i+1][j])
            {
                c[i+1][j+1] = c[i][j+1];
            }
            else
            {
                c[i+1][j+1] = c[i+1][j];
            }
        }
    }
    return c[n][n];
}

std::vector<int> Tokenize(const std::string& a)
{
    std::stringstream tokenizer(a);
    std::istream_iterator<int> it(tokenizer);
    std::istream_iterator<int> end;
    std::vector<int> ordered(it, end);
    std::vector<int> timeline(ordered);
    for (unsigned int i = 0; i != n; i++)
    {
        timeline[ordered[i] - 1] = i + 1;
    }
    return timeline;
}

// Slow (1.296(s)) but AC.
int main(int argc, char* argv[])
{
    std::cin >> n;
    getchar();

    std::string buffer;
    getline(std::cin, buffer);
    std::vector<int> answer = Tokenize(buffer);

    while (getline(std::cin, buffer))
    {
        std::vector<int> query = Tokenize(buffer);
        std::cout << GetLCSLength(answer, query) << std::endl;
    }

    return 0;
}

