#include <iostream>

#define V 9

void printSolution(int dist[], int v) {
	for( int i =0 ;i<v;i++)
		printf("node %d has min distance %d\n",i, dist[i] );
}

int minDistance(int * dist,bool * visited) {
	
	int min, min_index;

	min = INT_MAX;

	for( int i =0 ; i< V; i++) {
	  if(visited[i] == false && dist[i] <= min){
	    min = dist[i];
	    min_index = i;
	  }
	 }

	return min_index;
}

void dijkstra(int graph[V][V],int src) {

    int u;

	bool *visited = new bool[V];

	int dist[V];

	for( int i =0 ; i< V ;i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	for (int i=0; i<V; i++) {

	     u = minDistance(dist,visited); 
	     visited[u] = true;

	     for (int v=0; v<V; v++) {

	     	if( visited[v] != true && graph[u][v] && dist[v]!=INT_MAX && dist[v] > dist[u] + graph[u][v])
	     		dist[v] = dist[u] + graph[v][u];
		}

	}

	printSolution(dist,V);

}

// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}