#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <stdio.h>

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// -----------------------------------------------------------------------------

std::map<char, int> precedence;

void InitPrecedence()
{
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
}

// http://www.cs.arizona.edu/classes/cs227/spring12/infix.pdf
int main(int argc, char* argv[])
{
    InitPrecedence();

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        std::stack<char> op_stack;
        std::string buffer;
        while (getline(std::cin, buffer) && buffer.size())
        {
            char c = buffer[0];
            if (IsDecimalDigit(c))
            {
                putchar(c);
            }
            else if (c == '(')
            {
                op_stack.push(c);
            }
            else if (c == ')')
            {
                while (true)
                {
                    char top = op_stack.top();
                    op_stack.pop();
                    if (top == '(')
                    {
                        break;
                    }
                    else 
                    {
                        putchar(top);
                    }
                }
            }
            else 
            {
                while (!op_stack.empty())
                {
                    char top = op_stack.top();
                    if (top == '(' || (precedence[top] < precedence[c])) 
                    {
                        break;
                    }
                    op_stack.pop();
                    putchar(top);
                }
                op_stack.push(c);
            }
        }
        while (!op_stack.empty())
        {
            putchar(op_stack.top());
            op_stack.pop();
        }

        putchar('\n');
    }

    return 0;
}