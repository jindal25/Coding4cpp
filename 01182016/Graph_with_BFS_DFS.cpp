// C++ program to check if there is exist a path between two vertices
// of a graph.
#include<iostream>
#include <list>
using namespace std;
 
// This class represents a directed graph using adjacency list 
// representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void bfs(); 
    void bfsUtil(int s, bool * vis, list<int> qu);   

    void dfs();
    void dfsUtil(int v, bool visited[]);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::dfs() {
      
   bool *visited = new bool[V];
   for( int i=0; i<V; i++)
      visited[i]=false;

    for( int s=0; s<V; s++)
        if(!visited[s])
            dfsUtil(s,visited);
}

void Graph::dfsUtil(int v , bool visited[]) {

  cout << v << " ";

  visited[v]=true;
  list<int>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();i++) {
    if(!visited[*i])
      dfsUtil(*i,visited);
  }
}

void Graph::bfs(){

    // Create a queue for BFS
    list<int> queue;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if(!visited[i])
           bfsUtil(i,visited, queue);


    cout << endl;

}
 
// A BFS based function to check whether d is reachable from s.
void Graph::bfsUtil(int s , bool * visited, list<int> queue)
{
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        cout << s << " ";
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then 
            // return true
            
            // Else, continue to do BFS
            if (!visited[*i])
            {
                //cout << *i << " ";
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
     
    // If BFS is complete without visiting d
    //return false;
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs();
    g.dfs();



    Graph g1(7);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 5);
    g1.addEdge(5, 6);
    g1.bfs();
    g1.dfs();
    cout << endl;
    
    Graph g12(8);
    g12.addEdge(0, 1);
    g12.addEdge(1, 4);
    g12.addEdge(4, 6);
    g12.addEdge(6, 0);
    g12.addEdge(0, 3);
    g12.addEdge(3, 5);
    g12.addEdge(5, 2);
    g12.addEdge(2, 7);
    g12.bfs() ;
    cout << endl;
    g12.dfs() ;
    cout << endl;
    
 
    return 0;
}