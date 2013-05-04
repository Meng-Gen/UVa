// Similar to UVa 572.
//
// However, we need to keep track of the size of the connected component H.
// H is a star if |H| = 1.  Otherwise G may be moon, comet, sun or UFOs.
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

bool visited[100][100];
char grid[100][100];

int visit_star(int x, int y)
{
	Node node(x, y);
	
	std::stack<Node> dfs_stack;
	dfs_stack.push(node);

	int star_size = 0;
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

		if (grid[top.x][top.y] == '.')
		{
			continue;
		}

		star_size++;
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				Node next(top.x + dx, top.y + dy);
				dfs_stack.push(next);
			}
		}
	}
	return star_size;
}

int main(int argc, char* argv[])
{
	while(1)
	{
		std::cin >> m >> n;
		if (m == 0 && n == 0)
		{
			break;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < m; i++)
		{
			std::string grid_ith_row;
			std::cin >> grid_ith_row;
			for (int j = 0; j < n; j++)
			{
				grid[i][j] = grid_ith_row[j];
			}
		}

		int star_count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && grid[i][j] == '*')
				{
					if (visit_star(i, j) == 1)
					{
						star_count++;
					}
				}
			}
		}
		printf("%d\n", star_count);
	}

	return 0;
}