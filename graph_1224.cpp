#include <iostream>
#include <list>
#include <string>


using namespace std;

class graph {
  int V;
  lis<string> *adj; //adjacency matrix
 public:
  graph(int a):V(a) {
    adj = new list<string>[V];
  }
   
  void addEdge(string v, int w);
  
  bool BFS( string s, string d);
 
  void DFS(string s);
  void DFSUtil(string v , bool visited[]); 
};
 
void graph::DFS(string s) {
  
   bool *visited = new bool[V];
   for( int i=0; i<V; i++)
      visited[i]=false;
   DFSUtil(s,visited);
}

void graph::DFSUtil(string v , bool visited[]) {

  cout << v << " ";

  visited[v]=true;
  list<string>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();i++) {
    if(!visited[*i])
      DFSUtil(*i,visited);
  }
}


void graph::addEdge( string v, int w) {
  adj[v].push_back(w);
}

bool graph::BFS(string s,  string d) {
  if(s==d)
   return true;
  
  bool *visited = new bool[V];
  for (int i=0; i<V; i++)
    visited[i]=false; 

  list<int>queue;
 
  queue.push_back(s);

  list<int>::iterator i;
  
  while(!queue.empty()) {
    s=queue.front();
    queue.pop_front();
  
    for (i = adj[s].begin();i != adj[s].end();i++) {
        if( *i ==d)
         return true;
        
        if(!visited[*i]) {
          visited[*i] = true;
          queue.push_back(*i);
        }
    }
}

}


int main()
{
  graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.DFS(2); 
  int u = 1, v = 3;
  if(g.BFS(u, v))
      cout<< "\n There is a path from " << u << " to " << v;
  else
      cout<< "\n There is no path from " << u << " to " << v;
 
  u = 3, v = 1;
  if(g.BFS(u, v))
      cout<< "\n There is a path from " << u << " to " << v;
  else
      cout<< "\n There is no path from " << u << " to " << v;
 
  return 0;

}
