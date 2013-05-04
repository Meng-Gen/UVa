// Similar to UVa 572, 11244
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

int m;

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

bool visited[26][26];
char grid[26][26];

void visit_war_eagle(int x, int y)
{
	Node node(x, y);
	
	std::stack<Node> dfs_stack;
	dfs_stack.push(node);

	while (dfs_stack.size() > 0)
	{
		Node top = dfs_stack.top();
		dfs_stack.pop();

		if (top.x < 0 || top.x >= m || top.y < 0 || top.y >= m)
		{
			continue;
		}

		if (visited[top.x][top.y])
		{
			continue;
		}
		visited[top.x][top.y] = true;

		if (grid[top.x][top.y] == '0')
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
	int image_id = 1;
	while(std::cin >> m)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < m; i++)
		{
			std::string grid_ith_row;
			std::cin >> grid_ith_row;
			for (int j = 0; j < m; j++)
			{
				grid[i][j] = grid_ith_row[j];
			}
		}

		int war_eagle_count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && grid[i][j] == '1')
				{
					visit_war_eagle(i, j);
					war_eagle_count++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", image_id, war_eagle_count);
		image_id++;
	}

	return 0;
}