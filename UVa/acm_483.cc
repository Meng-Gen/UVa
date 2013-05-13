#include <iostream>
#include <stack>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char c;
    std::stack<char> word_stack;
    while (1) 
    {
        c = getchar();
        if (c == EOF) 
        { 
            while (word_stack.size() > 0)
            {
                char top = word_stack.top();
                word_stack.pop();
                std::cout << top;
            }
            break; 
        }
        else if (c == '\n' || c == ' ')
        {
            while (word_stack.size() > 0)
            {
                char top = word_stack.top();
                word_stack.pop();
                std::cout << top;
            }
            std::cout << c;
        }
        else
        {
            word_stack.push(c);
        }
    }
    return 0;
}