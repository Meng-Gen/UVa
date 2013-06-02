#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

struct Job
{
    int id_;
    int time_;
    int fine_;

    Job(int id, int time, int fine) : id_(id), time_(time), fine_(fine) { }
};

bool CompareDelegate(const Job& a, const Job& b)
{
    // Do job a then do job b, we will be fined fine_b * time_a.
    // Do job b then do job a, we will be fined fine_a * time_b.
    // Minimize the fine.
    return a.fine_ * b.time_ > b.fine_ * a.time_;
}

// ----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }
        
        int num_jobs;
        std::cin >> num_jobs;
        
        std::vector<Job> jobs;
        for (int job_id = 1; job_id <= num_jobs; job_id++)
        {
            int time;
            int fine;
            std::cin >> time >> fine;
            jobs.push_back(Job(job_id, time, fine));
        }
        // Greedy algorithm.
        std::sort(jobs.begin(), jobs.end(), CompareDelegate);

        for (int i = 0; i < num_jobs; i++)
        {
            printf("%d", jobs[i].id_);
            if (i != num_jobs - 1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }

    return 0;
}