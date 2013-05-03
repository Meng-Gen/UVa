#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int N;
	while (std::cin >> N)
	{
		// Otherwise you will get a lot of WA.  Dealing with input/output is 
		// quite not easy in UVa.
		getchar();
		for (int i = 0; i < N; i++)
		{
			std::string buffer;
			getline(std::cin, buffer);

			bool legal_balance = true;
			std::stack<char> parenthese_stack;
			for (int j = 0; j < buffer.length(); j++)
			{
				char c = buffer[j];
				if (c == '(' || c == '[')
				{
					parenthese_stack.push(c);
				}
				else if (parenthese_stack.empty())
				{
					legal_balance = false;
					break;
				}
				else if (c == ')')
				{
					char top = parenthese_stack.top();
					if (top == '(')
					{
						parenthese_stack.pop();
					}
					else
					{
						legal_balance = false;
						break;
					}
				}
				else if (c == ']')
				{
					char top = parenthese_stack.top();
					if (top == '[')
					{
						parenthese_stack.pop();
					}
					else
					{
						legal_balance = false;
						break;
					}
				}
			}

			if (!parenthese_stack.empty())
			{
				legal_balance = false;
			}
			if (legal_balance)
			{
				printf("Yes\n");
			}
			else 
			{
				printf("No\n");
			}
		}
	}
	return 0;
}