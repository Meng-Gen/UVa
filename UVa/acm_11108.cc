#include <bitset>
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

std::string formula;

bool K[2][2] = { { 0, 0 }, { 0, 1 } };
bool A[2][2] = { { 0, 1 }, { 1, 1 } };
bool C[2][2] = { { 1, 1 }, { 0, 1 } };
bool E[2][2] = { { 1, 0 }, { 0, 1 } };

std::stack<char> formula_stack;

bool IsTautology()
{
    int true_count = 0;
    int len = formula.size();
    for (unsigned int i = 0; i < 32; i++)
    {
        std::bitset<5> value_map(i);
        std::stack<bool> operand_stack;
        char c;
        for (int j = len-1; j >= 0; j--)
        {
            c = formula[j];
            if (c >= 'p' && c <= 's')
            {
                operand_stack.push(value_map[c - 'p']);
            }
            else if (c == 'N')
            {
                bool w = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(!w);
            }
            else if (c == 'K')
            {
                bool w = operand_stack.top();
                operand_stack.pop();
                bool x = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(K[w][x]);
            }
            else if (c == 'A')
            {
                bool w = operand_stack.top();
                operand_stack.pop();
                bool x = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(A[w][x]);
            }
            else if (c == 'C')
            {
                bool w = operand_stack.top();
                operand_stack.pop();
                bool x = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(C[w][x]);
            }
            else if (c == 'E')
            {
                bool w = operand_stack.top();
                operand_stack.pop();
                bool x = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(E[w][x]);
            }
        }
        if (operand_stack.top())
        {
            true_count++;
        }
    }
    return true_count == 32;
}

int main(int argc, char* argv[])
{
    while (getline(std::cin, formula) && formula != "0")
    {
        if (IsTautology())
        {
            puts("tautology");
        }
        else
        {
            puts("not");
        }
    }
    return 0;
}