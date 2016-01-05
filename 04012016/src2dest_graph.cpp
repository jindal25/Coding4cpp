#include <iostream>
#include <fstream>
#include <limits.h>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <cstdlib>

using namespace std;

int INFINITY = INT_MAX;

class Vertex {
public:
    string           name;   // Vertex name
    vector<Vertex *> adj;    // Adjacent vertices
    vector<int> weight;
    int              dist;   // Cost
  bool             visited;
    Vertex          *path;   // Previous vertex on shortest path
    string          parentname; // parent name for minimum spanning tree
    Vertex( const string & nm ) : name( nm )
      { reset( ); }

    void reset( )
      { dist = INFINITY; path = NULL; }
};


typedef map<string,Vertex *> vmap;
typedef pair<string,Vertex *> vpair;


class Graph
{
  public:
    Graph( ) { }
    ~Graph( );
    void addEdge( const string & sourceName, const string & destName, const int weight );
    void printPath( const string & destName ) const;
    void unweighted( const string & startName );
    void weighted( const string & startName );
      
  private:
    Vertex * getVertex( const string & vertexName );
    void printPath( const Vertex & dest ) const;
    void clearAll( );

    vmap vertexMap;
    vector<Vertex *> allVertices;
};

// To decide sorting order of priority queue
class PrioritizeVertices {
public :
    bool operator()(Vertex *x, Vertex *y )
    {
		if (x->dist < y->dist) return true;
		else return false;
    }
};



void Graph::addEdge( const string & sourceName, const string & destName ,const int weight)
{
    Vertex * v = getVertex( sourceName );
    Vertex * w = getVertex( destName );
    v->visited=false;
    w->visited=false;
    v->adj.push_back( w );
    w->adj.push_back(v);
    v->weight.push_back(weight);
    w->weight.push_back(weight);
}

void Graph::printPath( const string & destName ) const
{
    vmap::const_iterator itr = vertexMap.find( destName );

    if( itr == vertexMap.end( ) )
    {
        cout << "Destination vertex not found" << endl;
        return;
    }

    const Vertex & w = *(*itr).second;
    if( w.dist == INFINITY )
        cout << destName << " is unreachable";
    else
      {
	cout << "Distance is =\t"<< w.dist <<endl;

        printPath( w );
      }
    cout << endl;
}

// If vertexName is not present, add it to vertexMap
// In either case, return the Vertex
Vertex * Graph::getVertex( const string & vertexName )
{
    vmap::iterator itr = vertexMap.find( vertexName );

    if( itr == vertexMap.end( ) )
    {
        Vertex *newv = new Vertex( vertexName );
        allVertices.push_back( newv );
        vertexMap.insert( vpair( vertexName, newv ) );
        return newv;
    }
    return (*itr).second;
}

void Graph::printPath( const Vertex & dest ) const
{
    if( dest.path != NULL )
    {
        printPath( *dest.path );
        cout << " to ";
    }
    cout << dest.name;
 }

void Graph::clearAll( )
{
    for( int i = 0; i < allVertices.size( ); i++ )
        allVertices[ i ]->reset( );
}

Graph::~Graph( )
{
    for( int i = 0; i < allVertices.size( ); i++ )
        delete allVertices[ i ];
}


void Graph::unweighted( const string & startName )
{
    clearAll( );

    vmap::iterator itr = vertexMap.find( startName );

    if( itr == vertexMap.end( ) )
    {
        cout << startName << " is not a vertex in this graph" << endl;
        return;
    }

    Vertex *start = (*itr).second;
    list<Vertex *> q;
    q.push_back( start ); start->dist = 0;

    while( !q.empty( ) )
    {
        Vertex *v = q.front( );	q.pop_front( );

        for( int i = 0; i < v->adj.size( ); i++ )
        {
            Vertex *w = v->adj[ i ];
            if( w->dist == INFINITY )
            {
                w->dist = v->dist + 1;
                w->path = v;
                q.push_back( w );
            }
        }
    }
}


void Graph::weighted( const string & startName )
{
    clearAll( );

    vmap::iterator itr = vertexMap.find( startName );

    if( itr == vertexMap.end( ) )
    {
        cout << startName << " is not a vertex in this graph" << endl;
        return;
    }

    Vertex *start = (*itr).second;
    int cost;
    cost=0;
	priority_queue<Vertex *, vector<Vertex *>, PrioritizeVertices> prior_q;
	for( int i = 0; i < allVertices.size( ); i++ ) {
        prior_q.push(allVertices[i]);
	}
        Vertex *v = prior_q.top();
	v->dist = 0;
	while (!prior_q.empty())
    {
		Vertex *v = prior_q.top();
		prior_q.pop();
                v ->visited = true;
		cost = cost+v->dist;
		if (v->dist !=0)
		  cout << "Spaning Tree Edge:( " << v->name << " , " << v->parentname <<" )"<< endl;
		
        for( int i = 0; i < v->adj.size( ); i++ )
        {
            Vertex *w = v->adj[ i ];
            int xx = v->weight[i];
            if( (w->dist >  xx) && !(w->visited))
            {
                w->dist =  xx;
                w->path = v;
		w->parentname = v->name;
            }
        }
		
    }
	cout <<" Cost of the Spanning Tree is =  " << cost << endl;
}

/**
 * Process a request; return false if end of file.
 */
bool processRequest( istream & in, Graph & g )
{
    string startName;
    string destName;

    cout << "Enter start node: ";
    if( !( in >> startName ) )
        return false;
    /*    cout << "Enter destination node: ";
    if( !( in >> destName ) )
        return false;
    */
    g.weighted( startName );
    // g.printPath( destName );

    return true;
}


/**
 * A simple main that reads the file given by argv[1]
 * and then calls processRequest to compute shortest paths.
 * Skimpy error checking in order to concentrate on the basics.
 */
int main( int argc, char *argv[ ] )
{
    Graph g;

    g.addEdge("TOON","POON",1);
    g.addEdge("POON","POIN",1);
    g.addEdge("POIN","POIE",1);
    g.addEdge("POIE","PLIE",1);
    g.addEdge("PLIE","PLEE",1);
    g.addEdge("PLEE","PLEA",1);

    g.unweighted("TOON");
    g.printPath("PLEA");

    return 0;
}
