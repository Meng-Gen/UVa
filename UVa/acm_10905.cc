#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

bool CompareDelegate(const std::string& a, const std::string& b)
{
    return (a + b) > (b + a);
}

std::vector<std::string> set;
std::string number;

int main(int argc, char* argv[])
{
    int N;
    while (std::cin >> N && N)
    {
        set.clear();
        for (int i = 0; i < N; i++)
        {
            std::cin >> number;
            set.push_back(number);
        }
        sort(set.begin(), set.end(), CompareDelegate);
        
        for (int i = 0; i < N; i++)
        {
            std::cout << set[i];
        }
        std::cout << std::endl;
    }
    return 0;
}