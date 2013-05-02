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
bool visited[200];
bool graph[200][200];
int coloring[200];

bool is_bipartite(int node)
{
	bool rv = true;
	
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
						rv = false;
					}
				}
				dfs_stack.push(i);
			}
		}
	}

	return rv;
}

int main(int argc, char* argv[])
{
	int num_edge;
	while(1)
	{
		std::cin >> num_node;
		if (num_node == 0)
		{
			break;
		}
		for (int i = 0; i < num_node; i++)
		{
			visited[i] = false;
			coloring[i] = UNKNOWN;
			for (int j = 0; j < num_node; j++)
			{
				graph[i][j] = false;
			}
		}

		std::cin >> num_edge;
		for (int i = 0; i < num_edge; i++)
		{
			int start_node, end_node; 
			std::cin >> start_node >> end_node;
			graph[start_node][end_node] = true;
			graph[end_node][start_node] = true;
		}

		bool is_bipartite_graph = true;
		for (int i = 0; i < num_node; i++)
		{
			if (!visited[i])
			{
				coloring[i] = BLACK;
				if (!is_bipartite(i))
				{
					is_bipartite_graph = false;
					break;
				}
			}
		}

		if (is_bipartite_graph)
		{
			printf("BICOLORABLE.\n");
		}
		else
		{
			printf("NOT BICOLORABLE.\n");
		}
	}

	return 0;
}