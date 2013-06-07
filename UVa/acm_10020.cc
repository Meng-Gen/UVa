#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

struct Segment
{
    int L;
    int R;

    bool IsTerminated() const 
    {
        return L == 0 && R == 0;
    }
};

bool SegmentCompare(const Segment& a, const Segment& b)
{
    return a.R > b.R;
}

Segment segments[100001];
int num_segments = 0;

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }
        
        int M;
        std::cin >> M;

        num_segments = 0;
        while (1) 
        {
            std::cin >> segments[num_segments].L >> segments[num_segments].R;
            if (segments[num_segments].IsTerminated())
            {
                break;
            }
            num_segments++;
        }

        std::sort(segments, segments + num_segments, SegmentCompare);

        std::vector<Segment> covering;
        int right_most = 0;
        bool has_covering = true;
        while (right_most < M)
        {
            bool is_found = false;
            for (int i = 0; i < num_segments; i++)
            {
                if (segments[i].L <= right_most && segments[i].R > right_most)
                {
                    is_found = true;
                    covering.push_back(segments[i]);
                    right_most = segments[i].R;
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
            puts("0");
        }
        else
        {
            int num_covering = covering.size();
            printf("%d\n", num_covering);
            for (int i = 0; i < num_covering; i++)
            {
                printf("%d %d\n", covering[i].L, covering[i].R);
            }
        }
    }
    return 0;
}