#include <iostream>
#include <queue>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int N;
    while (std::cin >> N && N)
    {
        std::priority_queue<long long, 
            std::vector<long long>, 
            std::greater<long long> > numbers;
        
        long long curr_number;
        for (int i = 0; i < N; i++)
        {
            std::cin >> curr_number;
            numbers.push(curr_number);
        }

        long long cost = 0;
        long long sum;
        while (numbers.size() > 2)
        {
            sum = numbers.top();
            numbers.pop();
            sum += numbers.top();
            numbers.pop();
            cost += sum;
            numbers.push(sum);
        }
        sum = numbers.top();
        numbers.pop();
        sum += numbers.top();
        numbers.pop();
        cost += sum;
            
        std::cout << cost << std::endl;
    }
    
    return 0;
}