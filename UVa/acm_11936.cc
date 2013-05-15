#include <iostream>
#include <stdio.h>

struct Triangle
{
    int a;
    int b;
    int c;

    bool IsValid()
    {
        if (a <= 0 || b <= 0 || c <= 0)
        {
            return false;
        }
        return ((a + b > c) && (b + c > a) && (c + a > b));
    }
};

int main(int argc, char* argv[])
{
    int N; // the number of test cases
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        Triangle t;
        std::cin >> t.a >> t.b >> t.c;

        if (t.IsValid())
        {
            printf("OK\n");
        }
        else
        {
            printf("Wrong!!\n");
        }
    }   
    return 0;
}