//Dijkstra's Shortest Path Algorithm
#include<stdio.h>

int adj[50][50];													//An Adjacency Matrix for creating graph
int no_of_vertices, status[50];										//To find out if the vertex is already visited or not
int cost[50][50];													//It is used for storing the cost of going from one to another vertex
int distance[50], predecessor[50];

void CreateGraph()
{
	int i;
	printf("Enter no of vertices: ");
	scanf_s("%d", &no_of_vertices);
	const int max_edge = (no_of_vertices * (no_of_vertices - 1)) / 2;

	printf("\nInstructions: \nYou have to enter edges for each vertices, we will provide you the no of counts.\nIf any where you have to exit, enter (-1 -1).\nN.B. Don't press any value which is equal to max no of vertices\nor forming any loop structure.\n");
	int source, destin, costval;

	for (i = 0; i < no_of_vertices; i++)
		for (int j = 0; j < no_of_vertices; j++)
		{
			adj[i][j] = 0;
			cost[i][j] = 9999;
		}

	for (i = 1; i <= max_edge; i++)
	{
		printf("Enter edges and cost for %d: ", i);
		scanf_s("%d%d%d", &source, &destin, &costval);

		if (source == -1 && destin == -1 && costval == -1)							//Base Case
			break;
		if ((source == -1 || destin == -1) || (source == no_of_vertices) || (destin == no_of_vertices))
		{
			printf("Sorry, you have entered an incorrect option, redirecting again\n");
			i--;
		}
		else
		{
			adj[source][destin] = 1;
			adj[destin][source] = 1;
			cost[source][destin] = costval;
			cost[destin][source] = costval;
		}
	}
}

/**
 * \brief 
 * \param starting_vertex 
 */
void dijkstra_algorithm(const int starting_vertex)
{
	int next_node = 0, i;

	distance[starting_vertex] = 0;
	status[starting_vertex] = 1;
	int count = 1;													//Already source is counted

	while (count < no_of_vertices - 1)
	{
		int min_distance = 9999;

		for (i = 0; i < no_of_vertices; i++)
		{
			if (distance[i] < min_distance && !status[i])
			{
				min_distance = distance[i];
				next_node = i;										//It gives the node at minimum distance
			}

			status[next_node] = 1;
			for (i = 0; i < no_of_vertices; i++)
			{
				if (!status[i])
					if (min_distance + cost[next_node][i] < distance[i])
					{
						distance[i] = min_distance + cost[next_node][i];
						predecessor[i] = next_node;
					}
			}
		}
		count++;
	}
	
	for (i = 0; i < no_of_vertices; i++)
	{
		if (i != starting_vertex)
		{
			printf("\nDistance of node %d = %d", i, distance[i]);
			printf("\nPath = %d", i);

			int j = i;
			do
			{
				j = predecessor[j];
				printf(" <- %d", j);
			} while (j != starting_vertex);
		}
	}
	printf("\n");
}

void call_dijkstra()
{
	int start;
	printf("Enter starting vertex: ");
	scanf_s("%d", &start);

	for (int i = 0; i < no_of_vertices; i++)
	{
		distance[i] = 0;
		status[i] = 0;
		predecessor[i] = start;
	}
	dijkstra_algorithm(start);
}

int main()
{
	CreateGraph();
	call_dijkstra();
	return 0;
}
