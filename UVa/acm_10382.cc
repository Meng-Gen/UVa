#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

#define MAGIC_EPSILON (1e-7)

struct Interval
{
    double L;
    double R;
};

Interval sprinklers[10001];

bool IntervalCompare(const Interval& a, const Interval& b)
{
    return a.R > b.R;
}

int main(int argc, char* argv[]) 
{
    int N;
    double L;
    double W;
    long long position;
    long long radius;

    while (std::cin >> N >> L >> W)
    {
        int num_good_sprinklers = 0;
        for (int i = 0; i < N; i++)
        {
            std::cin >> position >> radius;

            if (W > radius * 2.0 + MAGIC_EPSILON)
            {
                continue;
            }
            double d = sqrt((double)(radius * radius) - W * W / 4.0);
            sprinklers[num_good_sprinklers].L = position - d;
            sprinklers[num_good_sprinklers].R = position + d;
            num_good_sprinklers++;
        }
        
        std::sort(sprinklers, sprinklers + num_good_sprinklers, 
            IntervalCompare);

        std::vector<Interval> covering;
        double right_most = 0.0;
        bool has_covering = true;
        while (right_most + MAGIC_EPSILON < L)
        {
            bool is_found = false;
            for (int i = 0; i < num_good_sprinklers; i++)
            {
                if (sprinklers[i].L <= right_most && 
                    sprinklers[i].R > right_most)
                {
                    is_found = true;
                    covering.push_back(sprinklers[i]);
                    right_most = sprinklers[i].R;
                    break;
                }
            }
            if (!is_found)
            {
                has_covering = false;
                break;
            }
        }
        
        if (!has_covering)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n", covering.size());
        }
    }
    return 0;
}