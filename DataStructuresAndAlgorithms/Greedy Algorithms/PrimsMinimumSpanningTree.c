#include<stdio.h>

#define INFINITY 9999
#define MAX 20

int graph[MAX][MAX], spanning[MAX][MAX], n;

int prims()
{
	int cost[MAX][MAX];
	int v = 0, distance[MAX], from[MAX];
	int visited[MAX], i;

	//create cost[][] matrix,spanning[][]
	for (i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (graph[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = graph[i][j];
			spanning[i][j] = 0;
		}

	//initialise visited[],distance[] and from[]
	distance[0] = 0;
	visited[0] = 1;

	for (i = 1; i<n; i++)
	{
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
	}

	int min_cost = 0;        //cost of spanning tree
	int no_of_edges = n - 1;        //no. of edges to be added

	while (no_of_edges>0)
	{
		//find the vertex at minimum distance from the tree
		int min_distance = INFINITY;
		for (i = 1; i<n; i++)
			if (visited[i] == 0 && distance[i]<min_distance)
			{
				v = i;
				min_distance = distance[i];
			}

		const int u = from[v];

		//insert the edge in spanning tree
		spanning[u][v] = distance[v];
		spanning[v][u] = distance[v];
		no_of_edges--;
		visited[v] = 1;

		//update the distance[] array
		for (i = 1; i<n; i++)
			if (visited[i] == 0 && cost[i][v]<distance[i])
			{
				distance[i] = cost[i][v];
				from[i] = v;
			}

		min_cost = min_cost + cost[u][v];
	}

	return min_cost;
}

int main()
{
	int i, j;
	printf("Enter no. of vertices:");
	scanf_s("%d", &n);

	printf("\nEnter the adjacency matrix:\n");

	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			scanf_s("%d", &graph[i][j]);

	const int total_cost = prims();
	printf("\nSpanning tree matrix:\n");

	for (i = 0; i<n; i++)
	{
		printf("\n");
		for (j = 0; j<n; j++)
			printf("%d\t", spanning[i][j]);
	}

	printf("\n\nTotal cost of spanning tree=%d\n", total_cost);
	return 0;
}

