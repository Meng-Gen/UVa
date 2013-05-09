//  Greedy.
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

//  1+2*3*4+5 => (1+2)*3*(4+5)
//  4*18+14+7*10 => 4*(18+14+7)*10
//  3+11+4*1*13*12*8+3*3+8 => (3+11+4)*1*13*12*(8+3)*(3+8)
//
//  So, we apply greedy algorithms.
long long get_maximum(const std::string& expression)
{
    std::stack<long long> operand_stack;  
    char op = 0;
    for (unsigned int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '*')
        {
            op = '*';
        }
        else if (expression[i] == '+')
        {
            op = '+';
        }
        else 
        {
            long long num = expression[i] - '0';
            if (i < expression.size() - 1 && 
                expression[i+1] != '*' && 
                expression[i+1] != '+')
            {
                num *= 10;
                num += (expression[i+1] - '0');
                i++;
            }            

            if (op == '+')
            {
                long long top = operand_stack.top();
                operand_stack.pop();
                num += top;
            }

            operand_stack.push(num);
        }
    }

    long long product = 1LL;
    while (!operand_stack.empty())
    {
        long long top = operand_stack.top();
        operand_stack.pop();
        product *= top;
    }

    return product;
}

//  As usual.  Apply greedy algorithm again.
//  The code is duplicated to |get_maximum|.
long long get_minimum(const std::string& expression)
{
    std::stack<long long> operand_stack;  
    char op = 0;
    for (unsigned int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '*')
        {
            op = '*';
        }
        else if (expression[i] == '+')
        {
            op = '+';
        }
        else 
        {
            long long num = expression[i] - '0';
            if (i < expression.size() - 1 && 
                expression[i+1] != '*' && 
                expression[i+1] != '+')
            {
                num *= 10;
                num += (expression[i+1] - '0');
                i++;
            }            

            if (op == '*')
            {
                long long top = operand_stack.top();
                operand_stack.pop();
                num *= top;
            }

            operand_stack.push(num);
        }
    }

    long long sum = 0LL;
    while (!operand_stack.empty())
    {
        long long top = operand_stack.top();
        operand_stack.pop();
        sum += top;
    }

    return sum;
}

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        std::string expression;
        std::cin >> expression;

        long long maximum = get_maximum(expression);
        long long minimum = get_minimum(expression);
        printf("The maximum and minimum are %lld and %lld.\n", maximum, minimum);
    }

    return 0;
}