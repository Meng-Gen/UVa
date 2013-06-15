#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>

struct Query {
    int query_id_;
    int period_;
    int next_time_;

    Query(int query_id, int period) 
        : query_id_(query_id), period_(period), next_time_(period)
    { }

    void SetNextTime() {
        next_time_ += period_;
    }

    void PrintQueryId() const {
        printf("%d\n", query_id_);
    }

    bool operator < (const Query& q) const {
        return next_time_ > q.next_time_ ||
            (next_time_ == q.next_time_ && query_id_ > q.query_id_);
    }
};

int main(int argc, char* argv[])
{
    std::string cmd;
    int query_id, period;
    std::priority_queue< Query > query_queue;
    while (std::cin >> cmd && cmd.compare("#") != 0)
    {
        std::cin >> query_id >> period;
        query_queue.push(Query(query_id, period));
    }
    
    int K;
    std::cin >> K;
    while (K--)
    {
        Query query = query_queue.top();
        query_queue.pop();
        query.PrintQueryId();
        query.SetNextTime();
        query_queue.push(query);
    }

    return 0;
}