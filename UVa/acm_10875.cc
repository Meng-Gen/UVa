#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>

template <class T>
inline std::string to_string(const T& t)
{
    std::stringstream builder;
    builder << t;
    return builder.str();
}

// -----------------------------------------------------------------------------

std::string big_literal[5][14] = 
{
    { "000", ".0.", "000", "000", "0.0", "000", "0..", "000", "000", "000", ".0.", "...", "0.0", ".0." },
    { "0.0", ".0.", "..0", "..0", "0.0", "0..", "0..", "..0", "0.0", "0.0", ".0.", "...", "0.0", "..." },
    { "0.0", ".0.", "000", "000", "000", "000", "000", "..0", "000", "000", "000", "000", ".0.", "000" },
    { "0.0", ".0.", "0..", "..0", "..0", "..0", "0.0", "..0", "0.0", "..0", ".0.", "...", "0.0", "..." },
    { "000", ".0.", "000", "000", "..0", "000", "000", "..0", "000", "..0", ".0.", "...", "0.0", ".0." },
};

std::map<std::string, char> big_literal_map;

void InitBigLiteralMap()
{
    std::string regular_literal("0123456789+-*/");

    for (int j = 0; j < 14; j++)
    {
        std::stringstream query;
        for (int i = 0; i < 5; i++)
        {
            query << big_literal[i][j];
        }
        big_literal_map[query.str()] = regular_literal[j];
    }
}

// -----------------------------------------------------------------------------

void PrintBigNumber(const std::string& number)
{
    int length = number.size();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (number[j] >= '0' && number[j] <= '9')
            {
                printf("%s", big_literal[i][number[j]-'0'].c_str());
            }
            else if (number[j] == '-')
            {
                printf("%s", big_literal[i][11].c_str());
            }
            putchar((j != length-1) ? ' ' : '\n');
        }
    }
}

// -----------------------------------------------------------------------------

std::string big_expression[5];

void ReadBigExpression()
{
    std::string buffer;
    int i = 0;
    while (getline(std::cin, buffer) && (i != 5))
    {
        if (buffer.size() >= 3)
        {
            big_expression[i] = buffer;
            i++;
        }
    }
}

char ParseBigLiteral(int pos)
{
    std::stringstream query;
    for (int i = 0; i < 5; i++)
    {
        query << big_expression[i].substr(pos, 3);
    }
    return big_literal_map[query.str()];
}

std::string ParseBigExpression()
{
    std::stringstream builder;
    int length = big_expression[0].size();
    for (int i = 0; i <= length - 3; i += 4)
    {
        builder << ParseBigLiteral(i);
    }
    return builder.str();
}

// -----------------------------------------------------------------------------

struct Token
{
    Token(char op, long long number, bool is_op, bool is_number) 
        : op_(op), number_(number), is_op_(is_op), is_number_(is_number) { }

    char op_;
    long long number_;
    bool is_op_;
    bool is_number_;
};

std::map<char, int> op_precedence;

void InitOpPrecedence()
{
    op_precedence['+'] = 0;
    op_precedence['-'] = 0;
    op_precedence['*'] = 1;
    op_precedence['/'] = 1;
}

std::vector<Token> postfix;

// http://faculty.cs.niu.edu/~hutchins/csci241/eval.htm
void GetPostfix(const std::string& infix)
{
    postfix.clear();
    std::stack<char> op_stack;

    int len = infix.size();
    char c = 0;

    for (int i = 0; i < len; i++)
    {
        c = infix[i];
        if (c >= '0' && c <= '9')
        {
            long long num = c - '0';
            while ((i < len - 1) && infix[i+1] >= '0' && infix[i+1] <= '9')
            {
                num *= 10;
                num += (infix[i+1] - '0');
                i++;
            }
            postfix.push_back(Token(0, num, false, true));
        }
        else 
        {
            while (!op_stack.empty())
            {
                char top = op_stack.top();
                if (op_precedence[c] <= op_precedence[top])
                {
                    postfix.push_back(Token(top, 0, true, false));
                    op_stack.pop();
                }
                else
                {
                    break;
                }
            }
            op_stack.push(c);            
        }
    }
    while (!op_stack.empty())
    {
        char top = op_stack.top();                 
        op_stack.pop();
        postfix.push_back(Token(top, 0, true, false));
    }
}

long long EvaluatePostfixExpression()
{
    std::stack<long long> valuation_stack;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i].is_number_)
        {
            valuation_stack.push(postfix[i].number_);
        }
        else if (postfix[i].is_op_)
        {
            char op = postfix[i].op_;
            long long b = valuation_stack.top();
            valuation_stack.pop();
            long long a = valuation_stack.top();
            valuation_stack.pop();

            if (op == '+')
            {
                valuation_stack.push(a + b);
            }
            else if (op == '-')
            {
                valuation_stack.push(a - b);
            }
            else if (op == '*')
            {
                valuation_stack.push(a * b);
            }
            else if (op == '/')
            {
                valuation_stack.push(a / b);
            }
        }
    }

    return valuation_stack.top();
}

long long EvaluateExpression(const std::string& infix)
{
    GetPostfix(infix);
    return EvaluatePostfixExpression();
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitBigLiteralMap();
    InitOpPrecedence();

    while (1)
    {
        ReadBigExpression();
        std::string expression = ParseBigExpression();
        if (expression == "0")
        {
            break;
        }

        // Test case: -9
        if (expression.size() > 0 && expression[0] == '-')
        {
            expression = "0" + expression;
        }
        long long result = EvaluateExpression(expression);
        PrintBigNumber(to_string<long long>(result));
        putchar('\n');
    }
    return 0;
}