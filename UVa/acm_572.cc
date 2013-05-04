#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int m;
int n;

struct Node
{
	int x;
	int y;

	Node() 
	{ 
		x = 0;
		y = 0;
	}

	Node(int some_x, int some_y)
	{
		x = some_x;
		y = some_y;
	}
};

bool visited[201][201];
char grid[201][201];

void visit_pocket(int x, int y)
{
	Node node(x, y);
	
	std::stack<Node> dfs_stack;
	dfs_stack.push(node);

	while (dfs_stack.size() > 0)
	{
		Node top = dfs_stack.top();
		dfs_stack.pop();

		if (top.x < 0 || top.x >= m || top.y < 0 || top.y >= n)
		{
			continue;
		}

		if (visited[top.x][top.y])
		{
			continue;
		}
		visited[top.x][top.y] = true;

		if (grid[top.x][top.y] == '*')
		{
			continue;
		}

		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				Node next(top.x + dx, top.y + dy);
				dfs_stack.push(next);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	while (1)
	{
		std::cin >> m >> n;

		if (m == 0)
		{
			break;
		}

		for (int i = 0; i < m; i++)
		{
			std::string grid_ith_row;
			std::cin >> grid_ith_row;
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
				grid[i][j] = grid_ith_row[j];
			}
		}

		int pocket_count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && grid[i][j] == '@')
				{
					pocket_count++;
					visit_pocket(i, j);
				}
			}
			
		}

		printf("%d\n", pocket_count);
	}

	return 0;
}