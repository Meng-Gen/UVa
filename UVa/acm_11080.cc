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
int num_edge;

bool visited[201];
bool connected_visited[201];
bool graph[201][201];
int coloring[201];

int get_connected_min_count(int node)
{
	bool is_bipartite = true;
	
	for (int i = 0; i < num_node; i++)
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

		for (int i = 0; i < num_node; i++)
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
		return -1;
	}

	int black_count = 0;
	int white_count = 0;
	for (int i = 0; i < num_node; i++)
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

	// Consider the graph with one single isolated point.
	if (black_count == 1 || white_count == 1)
	{
		return 1;
	}

	if (black_count < white_count)
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
		std::cin >> num_node >> num_edge;

		// 0-based.
		for (int x = 0; x < num_node; x++)
		{
			visited[x] = false;
			coloring[x] = UNKNOWN;
			for (int y = 0; y < num_node; y++)
			{
				graph[x][y] = false;
			}
		}

		for (int j = 0; j < num_edge; j++)
		{
			int edge_start;
			int edge_end;
			std::cin >> edge_start >> edge_end;
			graph[edge_start][edge_end] = true;
			graph[edge_end][edge_start] = true;
		}
	
		int total_min_count = 0;
		for (int j = 0; j < num_node; j++)
		{
			if (!visited[j])
			{
				coloring[j] = BLACK;
				int curr_min_count = get_connected_min_count(j);
				if (curr_min_count == -1)
				{
					total_min_count = -1;
					break;
				}
				else
				{
					total_min_count += curr_min_count;
				}
			}
		}
		printf("%d\n", total_min_count);
	}

	return 0;
}