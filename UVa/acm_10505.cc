#include <iostream>
#include <stack>
#include <stdio.h>

enum COLOR
{
	UNKNOWN = 0,
	BLACK = 1,
	WHITE = 2,
};

int num_node;
bool visited[201];
bool connected_visited[201];
bool graph[201][201];
int coloring[201];

int get_connected_max_count(int node)
{
	bool is_bipartite = true;
	
	for (int i = 1; i <= num_node; i++)
	{
		connected_visited[i] = false;
	}

	std::stack<int> dfs_stack;
	dfs_stack.push(node);

	while (dfs_stack.size() > 0)
	{
		int top = dfs_stack.top();
		dfs_stack.pop();

		if (visited[top])
		{
			continue;
		}
		visited[top] = true;
		connected_visited[top] = true;

		for (int i = 1; i <= num_node; i++)
		{
			if (graph[top][i])
			{
				if (coloring[i] == UNKNOWN)
				{
					if (coloring[top] == BLACK)
					{
						coloring[i] = WHITE;
					}
					else if (coloring[top] == WHITE)
					{
						coloring[i] = BLACK;
					}
				}
				else
				{
					if (coloring[top] == coloring[i])
					{
						is_bipartite = false;
					}
				}
				dfs_stack.push(i);
			}
		}
	}

	if (!is_bipartite)
	{
		return 0;
	}

	int black_count = 0;
	int white_count = 0;
	for (int i = 1; i <= num_node; i++)
	{
		if (connected_visited[i])
		{
			if (coloring[i] == BLACK)
			{
				black_count++;
			}
			else
			{
				white_count++;
			}
		}
	}

	if (black_count > white_count)
	{
		return black_count;
	}
	return white_count;
}

int main(int argc, char* argv[])
{
	int testcase;
	std::cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		getchar();
		
		std::cin >> num_node;

		// 1-based.
		for (int x = 1; x <= num_node; x++)
		{
			visited[x] = false;
			coloring[x] = UNKNOWN;
			for (int y = 1; y <= num_node; y++)
			{
				graph[x][y] = false;
			}
		}

		for (int x = 1; x <= num_node; x++)
		{
			int num_edge;
			std::cin >> num_edge;
			for (int j = 1; j <= num_edge; j++)
			{
				int y;
				std::cin >> y;
				graph[x][y] = true;
				graph[y][x] = true;
			}
		}

		int total_max_count = 0;
		for (int j = 1; j <= num_node; j++)
		{
			if (!visited[j])
			{
				coloring[j] = BLACK;
				total_max_count += get_connected_max_count(j);
			}
		}
		printf("%d\n", total_max_count);

		getchar();
	}

	return 0;
}