//Wap to find Breadth First Search in Graph
#include<stdio.h>
#include<limits.h>

int adj[50][50];										//An Adjacency Matrix for creating graph
int no_of_vertices, status[50];							//To find out if the vertex is already visited or not

int queue[50], front = -1, rear = -1;

void CreateGraph()
{
	int i, j;
	printf("Enter no of vertices: ");
	scanf_s("%d", &no_of_vertices);
	int max_edge = (no_of_vertices * (no_of_vertices - 1)) / 2;

	printf("\nInstructions: \nYou have to enter edges for each vertices, we will provide you the no of counts.\nIf any where you have to exit, enter (-1 -1).\nN.B. Don't press any value which is equal to max no of vertices\nor forming any loop structure.\n");
	int source, destin;

	for (i = 0; i < no_of_vertices; i++)
		for (j = 0; j < no_of_vertices; j++)
			adj[i][j] = 0;

	for (i = 1; i <= max_edge; i++)
	{
		printf("Enter edges for %d: ", i);
		scanf_s("%d%d", &source, &destin);

		if (source == -1 && destin == -1)				//Base Case
			break;
		else if ((source == -1 || destin == -1) || (source == no_of_vertices) || (destin == no_of_vertices))
		{
			printf("Sorry, you have entered an incorrect option, redirecting again\n");
			i--;
		}
		else
		{
			adj[source][destin] = 1;
			adj[destin][source] = 1;
		}
	}
}

int isEmpty()
{
	if (front == -1)
		return 1;
	else
		return 0;
}

void enqueue(int val)
{
	if (rear == no_of_vertices - 1)
	{
		printf("Queue overflow!\n");
		return;
	}
	if (front == -1)
		front = 0;
	queue[++rear] = val;
}

int dequeue()
{
	if (isEmpty())
	{
		printf("Queue underflow!\n");
		return INT_MIN;
	}

	int val = queue[front];
	if (front == rear)
		front = rear = -1;
	else
		front++;
	return val;
}

void BFS(int vertex)
{
	int i;
	enqueue(vertex);
	status[vertex] = 1;
	printf("Breadth First Traversal of the graph is: ");
	while (!isEmpty())
	{

		int value = dequeue();
		status[vertex] = 2;
		printf("%d ", value);

		for (i = 0; i < no_of_vertices; i++)
		{
			if (adj[vertex][i] == 1 && status[i] == 0)
			{
				enqueue(i);
				status[i] = 1;
			}
		}
	}
	printf("\n");
}

void BFSAlgorithm()
{
	for (int i = 0; i < no_of_vertices; i++)
		status[i] = 0;									//0 represents node

	int start;
	printf("Enter starting vertex: ");
	scanf_s("%d", &start);
	BFS(start);
}

int main()
{
	CreateGraph();
	BFSAlgorithm();
	return 0;
}